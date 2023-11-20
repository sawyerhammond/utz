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

const char _days_of_week[] = {
'M','o','n','d','a','y','\0',
'T','u','e','s','d','a','y','\0',
'W','e','d','n','e','s','d','a','y','\0',
'T','h','u','r','s','d','a','y','\0',
'F','r','i','d','a','y','\0',
'S','a','t','u','r','d','a','y','\0',
'S','u','n','d','a','y','\0',
};

const char* days_of_week = (char*)  _days_of_week;

const uint8_t _days_of_week_idx[] = {0, 7, 15, 25, 34, 41, 50};
const uint8_t* days_of_week_idx = (uint8_t*) _days_of_week_idx;

const char _months_of_year[] = {
'J','a','n','u','a','r','y','\0',
'F','e','b','r','u','a','r','y','\0',
'M','a','r','c','h','\0',
'A','p','r','i','l','\0',
'M','a','y','\0',
'J','u','n','e','\0',
'J','u','l','y','\0',
'A','u','g','u','s','t','\0',
'S','e','p','t','e','m','b','e','r','\0',
'N','o','v','e','m','b','e','r','\0',
'D','e','c','e','m','b','e','r','\0',
};
const char* months_of_year = (char*) _months_of_year;

const uint8_t _months_of_year_idx[] = {0, 8, 17, 23, 29, 33, 38, 43, 50, 60, 68, 77};
const uint8_t* months_of_year_idx = (uint8_t*) _months_of_year_idx;

urule_t cached_rules[MAX_CURRENT_RULES];
const uzone_packed_t* last_zone;
uint8_t last_year;

#define ustrneq(s1, s2, n) (strncmp(s1, s2, n) == 0)

uint8_t dayofweek(uint8_t y, uint8_t m, uint8_t d) {
    static const uint8_t dayofweek_table[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    d = ((UYEAR_TO_YEAR(y) + (UYEAR_TO_YEAR(y)/4) - (UYEAR_TO_YEAR(y)/100) + UYEAR_OFFSET/400 + dayofweek_table[m-1] + d) % 7);
    if (d == 0) { return 7; } else { return d; }
}

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

void rulecpy(urule_t* dest, urule_t* src) {
#ifndef UTZ_GLOBAL_COUNTERS
  uint8_t utz_i;
#endif
  for (utz_i = 0; utz_i < sizeof(urule_t); utz_i++) {
    ((uint8_t*)dest)[utz_i] = ((uint8_t*)src)[utz_i];
  }
}

void unpack_rules(const urule_packed_t* rules_in, uint8_t num_rules, uint8_t cur_year, urule_t* rules_out) {
#ifndef UTZ_GLOBAL_COUNTERS
  uint8_t utz_i;
#endif
  uint8_t last_rule_index = 0;
  uint8_t current_rule_count = 1;

  for (utz_i = 0; utz_i < num_rules && current_rule_count < MAX_CURRENT_RULES; utz_i++) {
    // First lets find the "last" rule of the previous year, for simplification
    // this assumes that multiple rules don't apply to the same month and
    // that the offset would not change between years (just the day of effect)

    //Is the rule valid for the current year?
    if (cur_year >= rules_in[utz_i].from_year && cur_year <= rules_in[utz_i].to_year) {
      //If , then set l
      if (rules_in[utz_i].in_month > rules_in[last_rule_index].in_month) {
        last_rule_index = utz_i;
      }
      printf("Packing rule %d\r\n", utz_i);
      unpack_rule(&rules_in[utz_i], cur_year, &rules_out[current_rule_count++]);
    }
  }

  printf("Packing rule %d\r\n", last_rule_index);
  unpack_rule(&rules_in[last_rule_index], cur_year, rules_out);
  // We override the "last" rule time of effect to be the start of the current year
  rules_out->date.year = cur_year;
  rules_out->date.month = 1;
  rules_out->date.dayofmonth = 1;
  for (utz_i = 0; utz_i < sizeof(utime_t); utz_i++) {
    ((char*)&rules_out->time)[utz_i] = 0;
  }
}

const urule_t* get_active_rule(const urule_t* rules, const udatetime_t* datetime) {
#ifndef UTZ_GLOBAL_COUNTERS
  int8_t utz_i = 0;
#endif
  for (utz_i = 1; utz_i < MAX_CURRENT_RULES; utz_i++) {
    if (!RULE_IS_VALID(rules[utz_i]) || udatetime_cmp(datetime, &(rules[utz_i].datetime)) < 0) {
      return &rules[utz_i-1];
    }
  }
  return &rules[MAX_CURRENT_RULES-1];
}

char get_current_offset(const uzone_t* zone, const udatetime_t* datetime, uoffset_t* offset) {
  const urule_t* rule;
  /*
  if (last_zone != zone->src || last_year != datetime->date.year) {
    unpack_rules(zone->rules, zone->rules_len, datetime->date.year, cached_rules);
    last_zone = zone->src;
    last_year = datetime->date.year;
  }
  */
  unpack_rules(zone->rules, zone->rules_len, datetime->date.year, cached_rules);

  offset->minutes = zone->offset.minutes;
  offset->hours = zone->offset.hours;
  rule = get_active_rule(cached_rules, datetime);
  offset->hours += rule->offset_hours;
  return rule->letter;
}

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

uint8_t get_next(const char** list) {
  do {
    (*list)++;
  } while (*(*list) != '\0');
  return (uint8_t) *(++(*list));
}

const char* get_index(const char* list, uint8_t i) {
  while(i-->0) {
    get_next(&list);
  }
  return list;
}

void get_zone_by_name(char* name, uzone_t* zone_out) {
#ifndef UTZ_GLOBAL_COUNTERS
  uint16_t utz_k;
#endif
  memset(cached_rules, 0, sizeof(cached_rules));
  const char* zone = zone_names;
  for (utz_k = 0; utz_k < NUM_ZONE_NAMES; utz_k++) {
    if (ustrneq(zone, name, MAX_ZONE_NAME_LEN)) {
      unpack_zone(&zone_defns[get_next(&zone)], name, zone_out);
      break;
    } else {
      get_next(&zone);
    }
    zone++;
  }
}
////////////////////////////////////////////////////////////////////////////////////
static void unpack_rules2(const urule_packed_t* rules_in, uint8_t num_rules, time_t utc_timestamp, urule_t* rules_out, time_t stdoff) {
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

static urule_t get_active_rule2(const urule_t* rules, time_t utc_timestamp, time_t stdoff)
{
  int8_t utz_i = 0;
  time_t timestamp;
  udatetime_t date;
  struct tm tm;
  for (utz_i = 1; utz_i < MAX_CURRENT_RULES; utz_i++)
  {
    //printf("utz_i: %d, mon: %d\r\n", utz_i, rules[utz_i].datetime.date.dayofmonth);
    //printf("RULE %d:\r\n", utz_i);
    //printf("Date: %d-%d-%d\r\n", rules[utz_i].datetime.date.month, rules[utz_i].datetime.date.dayofmonth, rules[utz_i].datetime.date.year);
    //printf("Time: %02d:%02d:%02d\r\n", rules[utz_i].datetime.time.hour, rules[utz_i].datetime.time.minute, rules[utz_i].datetime.time.second);
    //printf("Letter: %c\r\n", rules[utz_i].letter);
    //printf("is valid: %d\r\n", !RULE_IS_VALID(rules[utz_i]));
    //Check if time needs to be adjusted
    timestamp = utc_timestamp;
    if(rules[utz_i].is_local_time)
    {
      timestamp += stdoff;
    }

    tm = *localtime(&timestamp);
    //printf("Current Date: %s\r\n", asctime(&tm));
    date.date.dayofmonth = tm.tm_mday;
    date.date.dayofweek = tm.tm_wday;//
    date.date.month = tm.tm_mon + 1;
    date.date.year = tm.tm_year + 1900 - 2000;
    date.time.hour = tm.tm_hour;
    date.time.minute = tm.tm_min;
    date.time.second = tm.tm_sec;

    //printf("Timestamp: %d/%d/%d -- %02d:%02d:%02d\r\n", date.date.month, date.date.dayofmonth, date.date.year, date.time.hour, date.time.minute, date.time.second);

    //Check if after the rule date
    //printf("%u - %u\r\n", date.date.dayofweek, rules[utz_i].datetime.date.dayofweek);
    //printf("ret %d\r\n", udatetime_cmp(&date, &(rules[utz_i].datetime)));
    if (!RULE_IS_VALID(rules[utz_i]) || udatetime_cmp(&date, &(rules[utz_i].datetime)) < 0)
    //if (udatetime_cmp(&date, &(rules[utz_i].datetime)) > 0)
    {
      //printf("Ret 1\r\n");
      return rules[utz_i-1];
    }
  }
  //printf("Ret 2\r\n");
  return rules[MAX_CURRENT_RULES-1];
}

char get_utc_offset(const uzone_t zone, const time_t utc_timestamp, time_t* offset)
{
  //The offset will at least be the standard offset
  //offset->minutes = zone->offset.minutes;
  //offset->hours = zone->offset.hours;
  *offset = zone.offset.hours*3600 + zone.offset.minutes*60;

  // No Rules Just use the standart offset
  if(zone.rules_len == 0)
  {
    return 's';//TODO: FIXME
  } 

  // Get a list of rules for the associated schedule
  urule_t rule_list[MAX_CURRENT_RULES] = { 0 };
  unpack_rules2(zone.rules, zone.rules_len, utc_timestamp, rule_list, *offset);

  //Get the active rule and add the hour offset to the standard offset
  urule_t rule;
  rule = get_active_rule2(rule_list, utc_timestamp, *offset);
  //printf("return: %d\r\n", rule.date.month);
  *offset += rule.offset_hours*3600;

  //Return the letter associated with the rule usually S or D -> C%cT for CST or CDT
  return rule.letter;
}
