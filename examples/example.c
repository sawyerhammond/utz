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
  for(time=1672552800; time<1700000000; time+=60)
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
  /*
  char* zone = (char *)&zone_names[0];
  for (uint16_t utz_k = 0; utz_k < NUM_ZONE_NAMES; utz_k++) {
    test(zone);
    get_next(&zone);
    zone++;
    if(strcmp(zone, "")==0)
      break;
  }
  */
  //
  //test("Pacific/Midway");
  uzone_t active_zone;
  printf("%d\r\n", get_zone_by_name("hello", &active_zone));

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
