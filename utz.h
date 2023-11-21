/** @file utz.h
 *  @brief micro timezone library header
 *
 *  @author eV
 */

#ifndef _UTZ_H
#define _UTZ_H

#include <stdint.h>
#include <time.h>

/**************************************************************************/
/*                          struct definitions                            */
/**************************************************************************/

// reverse for big endian comparisons via raw?
/** @struct utime_t
 *  @brief time type
 *
 *  @var utime_t::second 0-59 or 0-0x59 in bcd mode
 *  @var utime_t::minute 0-59 or 0-0x59 in bcd mode
 *  @var utime_t::hour 0-23 or 0-0x23 in bcd mode
 *  @var utime_t::padding unused space to pad to 4 bytes
 *  @var utime_t::raw for comparisons and conversions
 */
typedef struct utime_t {
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
} utime_t;

// reverse for big endian comparisons via raw?
/** @struct udate_t
 *  @brief date type
 *
 *  @var udate_t::dayofweek day of week (monday = 1, sunday = 7)
 *  @var udate_t::dayofmonth 01-31 or 0x01-0x31 in bcd mode
 *  @var udate_t::month 01-12 or 0x01-0x12 in bcd mode
 *  @var udate_t::year 00-99 or 0x00-0x99 in bcd mode
 *  @var udate_t::padding unused space to pad to 4 bytes
 *  @var udate_t::raw for comparisons and conversions
 */
typedef struct udate_t {
  uint8_t year;       // 00-99 or 0x00-0x99 in bcd mode (offset 2000 ???)
  uint8_t month;      // 01-12 or 0x01-0x12 in bcd mode
  uint8_t dayofmonth; // 01-31 or 0x01-0x31 in bcd mode
  uint8_t dayofweek;
} udate_t;

/** @brief datetime type */
typedef struct udatetime_t {
  udate_t date;
  utime_t time;
} udatetime_t;

/** @brief timezone offset type */
typedef struct uoffset_t {
  uint8_t minutes; // 0 to 59
  int8_t hours; // -12 to +12
} uoffset_t;

/** @struct uzone_packed_t
 *  @brief packed timezone type
 *
 *  @var uzone_packed_t::offset_inc_minutes signed minutes in increments of OFFSET_INCREMENT
 *  @var uzone_packed_t::rules_idx index into rules array for start of corresponding rules
 *  @var uzone_packed_t::rules_len number of rule entries
 *  @var uzone_packed_t::abrev_formatter abreviation formatter
 */
typedef struct uzone_packed_t {
  int8_t offset_inc_minutes;
  uint8_t rules_idx;
  uint8_t rules_len;
  uint16_t abrev_formatter;
} uzone_packed_t;

/** @struct urule_packed_t
 *  @brief packed rule type, rules for daylight savings time
 *
 * There are 3 possible formats for on - the specifier for the day when the rule takes effect:
 * 1) the default format is "dayOfWeek >= dayOfMonth"
 * 2) unless on_dayofweek is 0, in which case the format is "dayOfMonth"
 * 3) unless on_dayofmonth is 0, in which case the format is "last dayOfWeek"
 *
 *  @var urule_packed_t::from_year years since 2000
 *  @var urule_packed_t::to_year years since 2000
 *  @var urule_packed_t::on_dayofweek day of week (monday = 1, sunday = 7)
 *  @var urule_packed_t::on_dayofmonth day of month
 *  @var urule_packed_t::at_is_local_time is time of day in local time, if not utc
 *  @var urule_packed_t::at_hours time of day, hours
 *  @var urule_packed_t::at_inc_minutes time of day, minutes, in OFFSET_INCREMENT minute increments
 *  @var urule_packed_t::letter (-,S,D) sorry Troll, Antarctica
 *  @var urule_packed_t::in_month month (1-12)
 *  @var urule_packed_t::offset_hours (0-3)
 */
typedef struct urule_packed_t {
  uint8_t from_year;
  uint8_t to_year;
  uint8_t on_dayofweek:3;
  uint8_t on_dayofmonth:5;
  uint8_t at_is_local_time:1;
  uint8_t at_hours:5;
  uint8_t at_inc_minutes:2;
  uint8_t letter:2;
  uint8_t in_month:4;
  uint8_t offset_hours:2;
} urule_packed_t;

/** @brief unpacked zone type */
typedef struct uzone_t {
  const char* name; //!< Zone name string
  uoffset_t offset; //!< Standard UTC offset
  const urule_packed_t* rules; //!< Pointer to first rule
  uint8_t rules_len; //!< Number of rules for zone
  const char* abrev_formatter; //!< Zone abreviation string
  const uzone_packed_t* src; //!< Packed Zone Source Pointer
} uzone_t;

/** @brief unpacked rule type, rules for daylight savings time */
typedef struct urule_t {
  union {
    udatetime_t datetime;
    struct {
      udate_t date;
      utime_t time;
    };
  };
  uint8_t is_local_time;
  char letter;
  uint8_t offset_hours;
} urule_t;

/**************************************************************************/
/*                         zone rule functions                            */
/**************************************************************************/

/** @brief advance pointer to list and returns index to the the prev item
 *
 *  @param list pointer
 *  @return index into the array for the item before advancement
 */
uint8_t get_next(const char** list);

/** @brief lookup a zone via zone_names
 *
 *  @param name the name of the zone to find
 *  @param zone_out pointer for zone found
 *  @return Status code (currently -1 or 0)
 */
extern int get_zone_by_name(char* name, uzone_t* zone_out);

/** @brief get the offset for zone at datetime, taking into account daylight savings time rules
 *
 *  @param zone zone
 *  @param utc_timestamp the utc timestamp to check rules for
 *  @param offset offset in seconds for zone at given utc time
 *  @return abbreviation letter
 */
extern char get_utc_offset(const uzone_t zone, const time_t utc_timestamp, time_t* offset);

#endif /* _UTZ_H */
