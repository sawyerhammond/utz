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

int main()
{
  printf("Total library db size: %lu B\n", sizeof(zone_rules) + sizeof(zone_abrevs) + sizeof(zone_defns) + sizeof(zone_names));

  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  //time_t time = ts.tv_sec;
  time_t time = 1699165800;
  struct tm tm = *localtime(&time);

  udatetime_t dt = {0};
  dt.date.year = tm.tm_year + 1900 - 2000;
  dt.date.month = tm.tm_mon + 1;
  dt.date.dayofmonth = tm.tm_mday;
  dt.time.hour = tm.tm_hour;
  dt.time.minute = tm.tm_min;
  dt.time.second = tm.tm_sec;

  printf("isdst: %s\r\n", tm.tm_isdst? "True" : "False");

  uzone_t active_zone;
  get_zone_by_name("Chicago", &active_zone);
  uoffset_t offset;
  char c = get_current_offset(&active_zone, &dt, &offset);
  printf("%s, current offset: %d.%d\n", active_zone.name, offset.hours, offset.minutes / 60);
  printf(active_zone.abrev_formatter, c);
  printf("\n");

/*
  for(int i=1699165800; i<1762327800; i+=60)
  {
    time_t time = i;
    struct tm tm = *localtime(&time);
    get_current_offset(&active_zone, &dt, &offset);
    if(tm.tm_isdst)
    {
      if(offset.hours != -5)
      {
        printf("NO Should be DST! %d\r\n", offset.hours);
        printf("%s\r\n", asctime(&tm));
      }
    }
    else if(!tm.tm_isdst)
    {
      if(offset.hours != -6)
      {
        printf("NO Should not be DST! %d\r\n", offset.hours);
        printf("%s\r\n", asctime(&tm));
      }
    }
  }
  */
  return 0;
}
