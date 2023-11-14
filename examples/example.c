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

static void print_all(struct tm tm, udatetime_t dt)
{
  printf("%d/%d/%d - %d:%d:%d\r\n", tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
  printf("%d/%d/%d - %d:%d:%d\r\n", dt.date.month, dt.date.dayofmonth, dt.date.year+2000, dt.time.hour, dt.time.minute, dt.time.second);
}

static void test_working(void)
{
  struct tm tm;
  udatetime_t dt = {0};
  uoffset_t offset;
  uzone_t active_zone;
  time_t time;
  get_zone_by_name("Chicago", &active_zone);

  //all of 2023
  for(time_t i=1672552800; i<1704088799; i+=60)
  {
    time = i;
    //clear TZ
    unsetenv("TZ");
    tzset();

    //Get the local time from actual for DST
    tm = *localtime(&time);

    int dst = tm.tm_isdst;

    //Set the TZ to UTC
    setenv("TZ", "UTC", 1);
    tzset();

    //Adjust for time zone
    time -= 3600 * 6;
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
      if(offset.hours != -5)
      {
        printf("NO Should not be DST! %d - isdst: %d\r\n", offset.hours, dst);
        print_all(tm, dt);
      }
    }
    else
    {
      if(offset.hours != -6)
      {
        printf("NO Should not be DST! %d - isdst: %d\r\n", offset.hours, dst);
        print_all(tm, dt);
      }
    }
  }
}

int main()
{
  //printf("Total library db size: %lu B\n", sizeof(zone_rules) + sizeof(zone_abrevs) + sizeof(zone_defns) + sizeof(zone_names));

  test_working();
  return 0;

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
  uoffset_t offset;
  char c = get_current_offset(&active_zone, &dt, &offset);
  printf("%s, current offset: %d.%d\n", active_zone.name, offset.hours, offset.minutes / 60);
  printf(active_zone.abrev_formatter, c);
  printf("\n");

  return 0;
}
