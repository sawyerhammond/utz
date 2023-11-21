/** @file utz.c
 *  @brief micro timezone library
 *
 *  @author eV
 */

#include <stdint.h>
#include <string.h>
#include <time.h>

#include "utz.h"
#include "zones.h"

/**************************************************************************/
/*                              constants                                 */
/**************************************************************************/

#define UYEAR_OFFSET 2000
#define UYEAR_OFFSET_SEC 946684800
#define UYEAR_FROM_YEAR(y) (y - UYEAR_OFFSET)
#define UYEAR_TO_YEAR(y) (y + UYEAR_OFFSET)

#define OFFSET_INCREMENT 15 // Minutes

#define MAX_CURRENT_RULES 4 + 1 // Sorry Morocco

#define DAYS_IN_LEAP_YEAR 366

#define RULE_IS_VALID(r) ((r).letter != 0)

#define UTRUE 1
#define UFALSE 0

#define ustrneq(s1, s2, n) (strncmp(s1, s2, n) == 0)

/**************************************************************************/
/*                         datetime functions                             */
/**************************************************************************/

/** @brief returns the day of the week for the given year/month/day
 *
 *  @param y year: 1 <= y <= 255 (2001 - 2255)
 *  @param m month: 1 <= m <= 12
 *  @param d day: 1 <= d <= 31
 *  @return day of week (Monday = 1, Sunday = 7)
 */
uint8_t dayofweek(uint8_t y, uint8_t m, uint8_t d) {
    static const uint8_t dayofweek_table[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    d = ((UYEAR_TO_YEAR(y) + (UYEAR_TO_YEAR(y)/4) - (UYEAR_TO_YEAR(y)/100) + UYEAR_OFFSET/400 + dayofweek_table[m-1] + d) % 7);
    if (d == 0) { return 7; } else { return d; }
}

/** @brief returns true if the year is a leap year
 *
 *  @param y year: 1 <= y <= 255 (2001 - 2255)
 *  @brief true if the year is a leap year
 */
uint8_t is_leap_year(uint8_t y) {
#if UYEAR_OFFSET == 2000
    if (y % 4 || y == 100 || y == 200) {
    return UFALSE;
  }
  return UTRUE;
#else
  if ((((UYEAR_TO_YEAR(y) % 4) == 0) && ((UYEAR_TO_YEAR(y) % 100) != 0)) || ((UYEAR_TO_YEAR(y) % 400) == 0)) {
    return UTRUE;
  }
  return UFALSE;
#endif
}

uint8_t days_in_month(uint8_t y, uint8_t m) {
  static const uint8_t days_in_month_nonleap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m == 2 && is_leap_year(y)) {
    return days_in_month_nonleap[m] + 1;
  } else {
    return days_in_month_nonleap[m];
  }
}

/** @brief returns days needed to get from the "current" day to the desired day of the week.
 *
 *  @param dayofweek_of_cur the "current" day of the week: 1 <= dayofweek_of_cur <= 7 (Monday = 1, Sunday = 7)
 *  @param dayofweek the desired day of the week: 1 <= dayofweek <= 7 (Monday = 1, Sunday = 7)
 *  @return number of days
 */
uint8_t next_dayofweek_offset(uint8_t dayofweek_of_cur, uint8_t dayofweek) {
  return (7 + dayofweek - dayofweek_of_cur) % 7;
}

int16_t udatetime_cmp(const udatetime_t* dt1, const udatetime_t* dt2) {
  int16_t ret;
  ret = dt1->date.year - dt2->date.year; if(ret != 0) { return ret; }
  ret = dt1->date.month - dt2->date.month; if(ret != 0) { return ret; }
  ret = dt1->date.dayofmonth - dt2->date.dayofmonth; if(ret != 0) { return ret; }
  ret = dt1->time.hour - dt2->time.hour; if(ret != 0) { return ret; }
  ret = dt1->time.minute - dt2->time.minute; if(ret != 0) { return ret; }
  ret = dt1->time.second - dt2->time.second; if(ret != 0) { return ret; }
  return 0;
}

/**************************************************************************/
/*                         zone rule functions                            */
/**************************************************************************/

/** @brief unpack rule
 *
 *  @param rule_in pointer to packed rule
 *  @param cur_year year: 1 <= y <= 255 (2001 - 2255)
 *  @param rule_out pointer for the output unpacked rule
 *  @return void
 */
void unpack_rule(const urule_packed_t* rule_in, uint8_t cur_year, urule_t* rule_out) {
  static const char letter_lut[3] = {'-', 'S', 'D'};

  uint8_t dayofweek_of_first_dayofmonth;
  uint8_t first_dayofweek;
  uint8_t dayofweek_of_dayofmonth;

  rule_out->date.year = cur_year;
  rule_out->date.month = 0;
  rule_out->date.month += rule_in->in_month;

  if (rule_in->on_dayofweek == 0) { // format is DOM e.g. 22
    rule_out->date.dayofmonth = rule_in->on_dayofmonth;
  } else if (rule_in->on_dayofmonth == 0) { // format is lastDOW e.g. lastSun
    dayofweek_of_first_dayofmonth = dayofweek(cur_year, rule_in->in_month, 1);
    first_dayofweek = next_dayofweek_offset(dayofweek_of_first_dayofmonth, rule_in->on_dayofweek);
    rule_out->date.dayofmonth = 1 + (7*3) + first_dayofweek;
    if (rule_out->date.dayofmonth + 7 <= days_in_month(cur_year, rule_in->in_month)) {
      rule_out->date.dayofmonth += 7;
    }
  } else { // format is DOW >= DOM e.g. Sun>=22
    dayofweek_of_dayofmonth = dayofweek(cur_year, rule_in->in_month, rule_in->on_dayofmonth);
    rule_out->date.dayofmonth = rule_in->on_dayofmonth + next_dayofweek_offset(
      dayofweek_of_dayofmonth,
      rule_in->on_dayofweek
    );
  }

  rule_out->time.hour = 0;
  rule_out->time.hour += rule_in->at_hours;
  rule_out->time.minute = 0;
  rule_out->time.minute += rule_in->at_inc_minutes * OFFSET_INCREMENT;
  rule_out->is_local_time = 0;
  rule_out->is_local_time += rule_in->at_is_local_time;

  rule_out->letter = letter_lut[rule_in->letter];

  rule_out->offset_hours = 0;
  rule_out->offset_hours += rule_in->offset_hours;
}

/** @brief unpack timezone
 *
 *  @param name the name of the timezone
 *  @param zone_in pointer to input packed zone
 *  @param zone_in pointer to output unpacked zone
 *  @return void
 */
void unpack_zone(const uzone_packed_t* zone_in, const char* name, uzone_t* zone_out) {
  zone_out->src = zone_in;
  zone_out->name = name;

  int8_t abs_offset_inc_min = zone_in->offset_inc_minutes >= 0 ? zone_in->offset_inc_minutes : -zone_in->offset_inc_minutes;
  zone_out->offset.minutes = (abs_offset_inc_min % (60 / OFFSET_INCREMENT)) * OFFSET_INCREMENT;
  zone_out->offset.hours = zone_in->offset_inc_minutes / (60 / OFFSET_INCREMENT);
  zone_out->rules = &(zone_rules[zone_in->rules_idx]);
  zone_out->rules_len = zone_in->rules_len;

  zone_out->abrev_formatter = &zone_abrevs[zone_in->abrev_formatter];
}

/** @brief advance pointer to list and returns index to the the prev item
 *
 *  @param list pointer
 *  @return index into the array for the item before advancement
 */
uint8_t get_next(const char** list) {
  do {
    (*list)++;
  } while (*(*list) != '\0');
  return (uint8_t) *(++(*list));
}

/** @brief lookup a zone via zone_names
 *
 *  @param name the name of the zone to find
 *  @param zone_out pointer for zone found
 *  @return void
 */
int get_zone_by_name(char* name, uzone_t* zone_out) {
  if(name == NULL)
      return -2;
  uint16_t utz_k;
  //memset(cached_rules, 0, sizeof(cached_rules)); Original implementation chached the rules to increase speed and repeat generation (?)
  const char* zone = zone_names;
  char * cur_name = (char *)zone;
  for (utz_k = 0; utz_k < NUM_ZONE_NAMES; utz_k++) {
    if (ustrneq(zone, name, MAX_ZONE_NAME_LEN)) {
	  cur_name = (char *)zone;
      unpack_zone(&zone_defns[get_next(&zone)], cur_name, zone_out);
      return 0;
    } else {
      get_next(&zone);
    }
    zone++;
  }
  return -1;
}

/** @brief unpack rules that are active in the current year
 *
 *  Note this assumes no two rules are active on the same day
 *
 *  @param rules_in pointer to packed rules
 *  @param num_rules the number of rules in the array
 *  @param cur_year year: 1 <= y <= 255 (2001 - 2255)
 *  @param rules_out pointer for the output unpacked rules
 *  @return void
 */
static void unpack_rules(const urule_packed_t* rules_in, uint8_t num_rules, time_t utc_timestamp, urule_t* rules_out, time_t stdoff) {
  uint8_t utz_i;
  uint8_t l = 0;
  uint8_t current_rule_count = 1;
  time_t timestamp = 0;
  uint8_t cur_year = 0;

  for (utz_i = 0; utz_i < num_rules && current_rule_count < MAX_CURRENT_RULES; utz_i++)
  {
    // First lets find the "last" rule of the previous year, for simplification
    // this assumes that multiple rules don't apply to the same month and
    // that the offset would not change between years (just the day of effect)

    // Does the rule want utc? or std offset?
    timestamp = utc_timestamp;
    if(rules_in[utz_i].at_is_local_time)
    {
      //Use local time so adjust the timestamp
      timestamp += stdoff;
    }
    //TODO: ASSUMES TZ IS UTC
    cur_year = (*localtime(&timestamp)).tm_year + 1900 - 2000;

    if (cur_year >= rules_in[utz_i].from_year && cur_year <= rules_in[utz_i].to_year)
    {
      if (rules_in[utz_i].in_month > rules_in[l].in_month)
      {
        l = utz_i;
      }
      unpack_rule(&rules_in[utz_i], cur_year, &rules_out[current_rule_count++]);
    }
  }

  unpack_rule(&rules_in[l], cur_year, rules_out);
  // We override the "last" rule time of effect to be the start of the current year
  rules_out->date.year = cur_year;
  rules_out->date.month = 1;
  rules_out->date.dayofmonth = 1;
  for (utz_i = 0; utz_i < sizeof(utime_t); utz_i++) {
    ((char*)&rules_out->time)[utz_i] = 0;
  }
}

/** @brief get the rule that applies at datetime
 *
 *  @param rules pointer to rules
 *  @param utc_timestamp the utc timestamp to check rules for
 *  @return a pointer the the rule that applies
 */
static urule_t get_active_rule(const urule_t* rules, time_t utc_timestamp, time_t stdoff)
{
  int8_t utz_i = 0;
  time_t timestamp;
  udatetime_t date;
  struct tm tm;
  for (utz_i = 1; utz_i < MAX_CURRENT_RULES; utz_i++)
  {
    //Check if time needs to be adjusted
    timestamp = utc_timestamp;
    if(rules[utz_i].is_local_time)
    {
      timestamp += stdoff;
    }

    //TODO: ASSUMES TZ IS UTC
    tm = *localtime(&timestamp);
    date.date.dayofmonth = tm.tm_mday;
    date.date.dayofweek = tm.tm_wday;//
    date.date.month = tm.tm_mon + 1;
    date.date.year = tm.tm_year + 1900 - 2000;
    date.time.hour = tm.tm_hour;
    date.time.minute = tm.tm_min;
    date.time.second = tm.tm_sec;

    //Check if after the rule date
    if (!RULE_IS_VALID(rules[utz_i]) || udatetime_cmp(&date, &(rules[utz_i].datetime)) < 0)
    {
      return rules[utz_i-1];
    }
  }
  return rules[MAX_CURRENT_RULES-1];
}

char get_utc_offset(const uzone_t zone, const time_t utc_timestamp, time_t* offset)
{
  //The offset will at least be the standard offset
  *offset = zone.offset.hours*3600 + zone.offset.minutes*60;

  // No Rules Just use the standart offset
  if(zone.rules_len == 0)
  {
    return 0;
  }

  // Get a list of rules for the associated schedule
  urule_t rule_list[MAX_CURRENT_RULES] = { 0 };
  unpack_rules(zone.rules, zone.rules_len, utc_timestamp, rule_list, *offset);

  //Get the active rule and add the hour offset to the standard offset
  urule_t rule;
  rule = get_active_rule(rule_list, utc_timestamp, *offset);
  *offset += rule.offset_hours*3600;

  //Return the letter associated with the rule usually S or D -> C%cT for CST or CDT
  return rule.letter;
}
