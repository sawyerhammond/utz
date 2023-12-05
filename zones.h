#ifndef _ZONES_H
#define _ZONES_H

#define MAX_ABREV_FORMATTER_LEN 11

#include "utz.h"


#define NUM_ZONE_NAMES 108
#define MAX_ZONE_NAME_LEN 31

extern const urule_packed_t* zone_rules;
extern const uzone_packed_t* zone_defns;
extern const char* zone_abrevs;
extern const char* zone_names;
#endif /* _ZONES_H */