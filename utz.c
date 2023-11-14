/** @file utz.c
 *  @brief micro timezone library
 *
 *  @author eV
 */

#include <stdint.h>
#include <string.h>

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
  uint8_t l = 0;
  uint8_t current_rule_count = 1;

  for (utz_i = 0; utz_i < num_rules && current_rule_count < MAX_CURRENT_RULES; utz_i++) {
    // First lets find the "last" rule of the previous year, for simplification
    // this assumes that multiple rules don't apply to the same month and
    // that the offset would not change between years (just the day of effect)
    if (cur_year >= rules_in[utz_i].from_year && cur_year <= rules_in[utz_i].to_year) {
      if (rules_in[utz_i].in_month > rules_in[l].in_month) {
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
  if (last_zone != zone->src || last_year != datetime->date.year) {
    unpack_rules(zone->rules, zone->rules_len, datetime->date.year, cached_rules);
    last_zone = zone->src;
    last_year = datetime->date.year;
  }

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
