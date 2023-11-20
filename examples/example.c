/** @file example.c
 *  @brief FIXME
 *
 *  @author eV Quirk
 */

#include "../utz.h"
#include "../zones.h"

//#include <ctime>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define ustrneq(s1, s2, n) (strncmp(s1, s2, n) == 0)

static void print_all(struct tm tm, udatetime_t dt)
{
  printf("%d/%d/%d - %d:%d:%d\r\n", tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
  printf("%d/%d/%d - %d:%d:%d\r\n", dt.date.month, dt.date.dayofmonth, dt.date.year+2000, dt.time.hour, dt.time.minute, dt.time.second);
}

static void test_zone(char * name)
{
  printf("Testing Zone %s\r\n", name);
  struct tm tm;
  udatetime_t dt = {0};
  uoffset_t offset;
  uzone_t active_zone;
  time_t time;
  get_zone_by_name(name, &active_zone);
  //all of 2023
  for(time_t i=1672552800; i<1704088799; i+=60)
  {
    time = i;
    //clear TZ
    setenv("TZ", name, 1);
    tzset();

    assert(strcmp(getenv("TZ"), name) == 0);

    //Get the local time from actual for DST
    tm = *localtime(&time);

    int dst = tm.tm_isdst;

    //Set the TZ to UTC
    setenv("TZ", "UTC", 1);
    tzset();

    //Adjust for time zone
    time += (3600 * active_zone.offset.hours) + (60 * active_zone.offset.minutes);
    tm = *localtime(&time);

    dt.date.year = tm.tm_year + 1900 - 2000;
    dt.date.month = tm.tm_mon + 1;
    dt.date.dayofmonth = tm.tm_mday;
    dt.time.hour = tm.tm_hour;
    dt.time.minute = tm.tm_min;
    dt.time.second = tm.tm_sec;

    get_current_offset(&active_zone, &dt, &offset);

    if(dst)
    {
      if(offset.hours != (active_zone.offset.hours + active_zone.rules->offset_hours))
      {
        printf("Rule 1 Month: %d\r\n", active_zone.rules[0].in_month);
        printf("Rule 2 Month: %d\r\n", active_zone.rules[1].in_month);
        printf("Was %d - Should Be %d\r\n", offset.hours, (active_zone.offset.hours + active_zone.rules->offset_hours));
        printf("Number of Rules: %d\r\n", active_zone.rules_len);
        printf("Time UTC: %s\r\n", asctime(&tm));
      }
      assert(offset.hours == (active_zone.offset.hours + active_zone.rules->offset_hours));
    }
    else
    {
      if(offset.hours != active_zone.offset.hours)
      {
        printf("Rule 1 Month: %d\r\n", active_zone.rules[0].in_month);
        printf("Rule 2 Month: %d\r\n", active_zone.rules[1].in_month);
        printf("Was %d - Should Be %d\r\n", offset.hours, active_zone.offset.hours);
        printf("Number of Rules: %d\r\n", active_zone.rules_len);
        printf("Time UTC: %s\r\n", asctime(&tm));
      }
      assert(offset.hours == active_zone.offset.hours);
    }
  }
}

void test(char * name)
{
  printf("Testing Zone %s\r\n", name);
  struct tm tm;
  udatetime_t dt = {0};
  time_t offset;
  uzone_t active_zone;
  time_t time;
  get_zone_by_name(name, &active_zone);
  time_t stdoff = active_zone.offset.hours*3600 + active_zone.offset.minutes*60;
  //all of 2023
  for(time=1672552800; time<1704088799; time+=60)
  {
    //time = 1678608000;
    //time = 1699167600;
    //clear TZ
    setenv("TZ", name, 1);
    tzset();

    assert(strcmp(getenv("TZ"), name) == 0);

    //Get the local time from actual for DST
    tm = *localtime(&time);

    int dst = tm.tm_isdst;

    //Set the TZ to UTC
    setenv("TZ", "UTC", 1);
    tzset();

    get_utc_offset(active_zone, time, &offset);

    if(dst)//IN DST
    {
      if(offset != (stdoff+3600))
      {
        printf("Was %ld - Should Be %ld\r\n", offset/3600, ((stdoff+3600)/3600));
        printf("Time UTC: %ld\r\n", time);
      }
      assert(offset == (stdoff+3600));
    }
    else//NOT in DST
    {
      if(offset != stdoff)
      {
        printf("Was %ld - Should Be %ld\r\n", offset/3600, (stdoff/3600));
        printf("Time UTC: %ld\r\n", time);
      }
      assert(offset == stdoff);
    }
  }
}

int main()
{
  //printf("Total library db size: %lu B\n", sizeof(zone_rules) + sizeof(zone_abrevs) + sizeof(zone_defns) + sizeof(zone_names));

  //Go through each zone and test it
  //
  char* zone = (char *)&zone_names[0];
  for (uint16_t utz_k = 0; utz_k < NUM_ZONE_NAMES; utz_k++) {
    test(zone);
    get_next(&zone);
    zone++;
    if(strcmp(zone, "")==0)
      break;
  }
  //
  //test_zone("America/Santiago");
  test("America/Chicago");

  return 0;
  /*

  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  //time_t time = ts.tv_sec;
  time_t time = 1699165800;
  time = 1699169400;

  struct tm tm = *localtime(&time);

  int dst = tm.tm_isdst;

  setenv("TZ", "UTC", 1);
  tzset();
  printf("%s\r\n", getenv("TZ"));

  time -= 3600 * 6;
  tm = *localtime(&time);

  udatetime_t dt = {0};
  dt.date.year = tm.tm_year + 1900 - 2000;
  dt.date.month = tm.tm_mon + 1;
  dt.date.dayofmonth = tm.tm_mday;
  dt.time.hour = tm.tm_hour;
  dt.time.minute = tm.tm_min;
  dt.time.second = tm.tm_sec;

  print_all(tm, dt);

  printf("isdst: %d\r\n", dst);

  uzone_t active_zone;
  get_zone_by_name("Chicago", &active_zone);
  printf("zone offset: %d:%d\r\n", active_zone.offset.hours, active_zone.offset.minutes);
  uoffset_t offset;
  char c = get_current_offset(&active_zone, &dt, &offset);
  printf("%s, current offset: %d.%d\n", active_zone.name, offset.hours, offset.minutes / 60);
  printf(active_zone.abrev_formatter, c);
  printf("\n");

  return 0;
  */
}
