#include "utz.h"

const urule_packed_t _zone_rules[20] = {
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AN	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AN	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AS	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AS	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AT	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  1, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AT	2001	max	-	Oct	Sun>=1	2:00s	1:00	D
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	Canada	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	Canada	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 19, 255, 7,  2,  0,  3, 0, 0,  4, 0}, // 	Chile	2019	max	-	Apr	Sun>=2	3:00u	0	-
{ 23, 255, 7,  2,  0,  4, 0, 0,  9, 1}, // 	Chile	2023	max	-	Sep	Sun>=2	4:00u	1:00	-
{  0, 255, 7,  0,  0,  1, 0, 1,  3, 1}, // 	EU	1981	max	-	Mar	lastSun	 1:00u	1:00	S
{  0, 255, 7,  0,  0,  1, 0, 0, 10, 0}, // 	EU	1996	max	-	Oct	lastSun	 1:00u	0	-
{ 23, 255, 5,  0,  1,  0, 0, 1,  4, 1}, // 	Egypt	2023	max	-	Apr	lastFri	 0:00	1:00	S
{ 23, 255, 4,  0,  1, 23, 0, 0, 10, 0}, // 	Egypt	2023	max	-	Oct	lastThu	24:00	0	-
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	NZ	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  7, 255, 7,  0,  1,  2, 0, 2,  9, 1}, // 	NZ	2007	max	-	Sep	lastSun	2:00s	1:00	D
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	US	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	US	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 13, 255, 5, 23,  1,  2, 0, 2,  3, 1}, // 	Zion	2013	max	-	Mar	Fri>=23	2:00	1:00	D
{ 13, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Zion	2013	max	-	Oct	lastSun	2:00	0	S
};

const char _zone_abrevs[220] = {
'E','E','%','c','T','\0',
'W','A','T','\0',
'C','A','T','\0',
'E','A','T','\0',
'A','K','%','c','T','\0',
'-','0','3','/','-','0','2','\0',
'C','%','c','T','\0',
'M','%','c','T','\0',
'A','%','c','T','\0',
'P','%','c','T','\0',
'-','0','4','\0',
'C','S','T','\0',
'E','%','c','T','\0',
'-','0','2','/','-','0','1','\0',
'M','S','T','\0',
'-','0','4','/','-','0','3','\0',
'N','%','c','T','\0',
'+','0','7','\0',
'+','0','4','\0',
'H','K','S','T','\0',
'I','%','c','T','\0',
'+','0','5','4','5','\0',
'I','S','T','\0',
'+','0','3','\0',
'K','S','T','\0',
'+','0','8','\0',
'+','0','3','3','0','/','+','0','4','3','0','\0',
'J','S','T','\0',
'+','0','6','3','0','\0',
'A','C','%','c','T','\0',
'A','E','S','T','\0',
'A','C','S','T','\0',
'A','E','%','c','T','\0',
'A','W','S','T','\0',
'C','E','%','c','T','\0',
'G','M','T','/','B','S','T','\0',
'M','S','K','\0',
'N','Z','%','c','T','\0',
'C','h','S','T','\0',
'H','S','T','\0',
'S','S','T','\0',
'+','1','2','\0',
};

const uzone_packed_t _zone_defns[46] = {
// Africa/Cairo	2:00	Egypt	EE%sT
{  8,  12,   2,   0},
// Africa/Lagos	1:00	-	WAT
{  4,   0,   0,   6},
// Africa/Maputo	2:00	-	CAT
{  8,   0,   0,  10},
// Africa/Nairobi	3:00	-	EAT
{ 12,   0,   0,  14},
// America/Anchorage	-9:00	US	AK%sT
{-36,  16,   2,  18},
// America/Argentina/Buenos_Aires	-3:00	Arg	-03/-02
// America/Sao_Paulo	-3:00	Brazil	-03/-02
{-12,   0,   0,  24},
// America/Chicago	-6:00	US	C%sT
{-24,  16,   2,  32},
// America/Denver	-7:00	US	M%sT
{-28,  16,   2,  37},
// America/Halifax	-4:00	Canada	A%sT
{-16,   6,   2,  42},
// America/Los_Angeles	-8:00	US	P%sT
// America/Tijuana	-8:00	US	P%sT
{-32,  16,   2,  47},
// America/Manaus	-4:00	-	-04
{-16,   0,   0,  52},
// America/Mexico_City	-6:00	Mexico	C%sT
// America/Regina	-6:00	-	CST
{-24,   0,   0,  56},
// America/New_York	-5:00	US	E%sT
{-20,  16,   2,  60},
// America/Nuuk	-3:00	EU	-03/-02	2023
{-12,  10,   2,  24},
// America/Nuuk	-2:00	EU	-02/-01
{ -8,  10,   2,  65},
// America/Phoenix	-7:00	-	MST
{-28,   0,   0,  73},
// America/Santiago	-4:00	Chile	-04/-03
{-16,   8,   2,  77},
// America/St_Johns	-3:30	Canada	N%sT
{-14,   6,   2,  85},
// Asia/Bangkok	7:00	-	+07
// Asia/Ho_Chi_Minh	7:00	-	+07
{ 28,   0,   0,  90},
// Asia/Dubai	4:00	-	+04
{ 16,   0,   0,  94},
// Asia/Hong_Kong	8:00	HK	HK%sT
{ 32,   0,   0,  98},
// Asia/Jerusalem	2:00	Zion	I%sT
{  8,  18,   2, 103},
// Asia/Kathmandu	5:45	-	+0545
{ 23,   0,   0, 108},
// Asia/Kolkata	5:30	-	IST
{ 22,   0,   0, 114},
// Asia/Riyadh	3:00	-	+03
// Europe/Istanbul	3:00	-	+03
{ 12,   0,   0, 118},
// Asia/Seoul	9:00	ROK	K%sT
{ 36,   0,   0, 122},
// Asia/Shanghai	8:00	PRC	C%sT
// Asia/Taipei	8:00	Taiwan	C%sT
{ 32,   0,   0,  56},
// Asia/Singapore	8:00	-	+08
{ 32,   0,   0, 126},
// Asia/Tehran	3:30	Iran	+0330/+0430
{ 14,   0,   0, 130},
// Asia/Tokyo	9:00	Japan	J%sT
{ 36,   0,   0, 142},
// Asia/Yangon	6:30	-	+0630
{ 26,   0,   0, 146},
// Australia/Adelaide	9:30	AS	AC%sT
{ 38,   2,   2, 152},
// Australia/Brisbane	10:00	AQ	AE%sT
{ 40,   0,   0, 158},
// Australia/Darwin	9:30	Aus	AC%sT
{ 38,   0,   0, 163},
// Australia/Hobart	10:00	AT	AE%sT
{ 40,   4,   2, 168},
// Australia/Perth	8:00	AW	AW%sT
{ 32,   0,   0, 174},
// Australia/Sydney	10:00	AN	AE%sT
{ 40,   0,   2, 168},
// Europe/Belgrade	1:00	EU	CE%sT
// Europe/Berlin	1:00	EU	CE%sT
// Europe/Brussels	1:00	EU	CE%sT
{  4,  10,   2, 179},
// Europe/Helsinki	2:00	EU	EE%sT
{  8,  10,   2,   0},
// Europe/London	0:00	EU	GMT/BST
{  0,  10,   2, 185},
// Europe/Moscow	3:00	-	MSK
{ 12,   0,   0, 193},
// Pacific/Auckland	12:00	NZ	NZ%sT
{ 48,  14,   2, 197},
// Pacific/Guam	10:00	-	ChST
{ 40,   0,   0, 203},
// Pacific/Honolulu	-10:00	-	HST
{-40,   0,   0, 208},
// Pacific/Pago_Pago	-11:00	-	SST
{-44,   0,   0, 212},
// Pacific/Tarawa	12:00	-	+12
{ 48,   0,   0, 216},
};

const char _zone_names[951] = {
                                                                          'A','f','r','i','c','a','/','B','r','a','z','z','a','v','i','l','l','e','\0',   1, // Africa/Brazzaville
                                                                                                  'A','f','r','i','c','a','/','C','a','i','r','o','\0',   0, // Africa/Cairo
                                                                                              'A','f','r','i','c','a','/','H','a','r','a','r','e','\0',   2, // Africa/Harare
                                                                                                  'A','f','r','i','c','a','/','L','a','g','o','s','\0',   1, // Africa/Lagos
                                                                                          'A','f','r','i','c','a','/','N','a','i','r','o','b','i','\0',   3, // Africa/Nairobi
                                                                              'A','m','e','r','i','c','a','/','A','n','c','h','o','r','a','g','e','\0',   4, // America/Anchorage
                          'A','m','e','r','i','c','a','/','A','r','g','e','n','t','i','n','a','/','B','u','e','n','o','s','_','A','i','r','e','s','\0',   5, // America/Argentina/Buenos_Aires
                                                                                      'A','m','e','r','i','c','a','/','C','h','i','c','a','g','o','\0',   6, // America/Chicago
                                                                                          'A','m','e','r','i','c','a','/','D','e','n','v','e','r','\0',   7, // America/Denver
                                                                                      'A','m','e','r','i','c','a','/','G','o','d','t','h','a','b','\0',  14, // America/Godthab
                                                                                      'A','m','e','r','i','c','a','/','H','a','l','i','f','a','x','\0',   8, // America/Halifax
                                                                      'A','m','e','r','i','c','a','/','L','o','s','_','A','n','g','e','l','e','s','\0',   9, // America/Los_Angeles
                                                                                          'A','m','e','r','i','c','a','/','M','a','n','a','u','s','\0',  10, // America/Manaus
                                                                      'A','m','e','r','i','c','a','/','M','e','x','i','c','o','_','C','i','t','y','\0',  11, // America/Mexico_City
                                                                                  'A','m','e','r','i','c','a','/','N','e','w','_','Y','o','r','k','\0',  12, // America/New_York
                                                                                      'A','m','e','r','i','c','a','/','P','h','o','e','n','i','x','\0',  15, // America/Phoenix
                                                                                          'A','m','e','r','i','c','a','/','R','e','g','i','n','a','\0',  11, // America/Regina
                                                                                  'A','m','e','r','i','c','a','/','S','a','n','t','i','a','g','o','\0',  16, // America/Santiago
                                                                              'A','m','e','r','i','c','a','/','S','a','o','_','P','a','u','l','o','\0',   5, // America/Sao_Paulo
                                                                                  'A','m','e','r','i','c','a','/','S','t','_','J','o','h','n','s','\0',  17, // America/St_Johns
                                                                                      'A','m','e','r','i','c','a','/','T','i','j','u','a','n','a','\0',   9, // America/Tijuana
                                                                                                  'A','s','i','a','/','B','a','n','g','k','o','k','\0',  18, // Asia/Bangkok
                                                                                          'A','s','i','a','/','C','h','o','n','g','q','i','n','g','\0',  26, // Asia/Chongqing
                                                                                                          'A','s','i','a','/','D','u','b','a','i','\0',  19, // Asia/Dubai
                                                                                  'A','s','i','a','/','H','o','_','C','h','i','_','M','i','n','h','\0',  18, // Asia/Ho_Chi_Minh
                                                                                          'A','s','i','a','/','H','o','n','g','_','K','o','n','g','\0',  20, // Asia/Hong_Kong
                                                                                          'A','s','i','a','/','J','e','r','u','s','a','l','e','m','\0',  21, // Asia/Jerusalem
                                                                                          'A','s','i','a','/','K','a','t','h','m','a','n','d','u','\0',  22, // Asia/Kathmandu
                                                                                                  'A','s','i','a','/','K','o','l','k','a','t','a','\0',  23, // Asia/Kolkata
                                                                              'A','s','i','a','/','K','u','a','l','a','_','L','u','m','p','u','r','\0',  27, // Asia/Kuala_Lumpur
                                                                                                      'A','s','i','a','/','K','u','w','a','i','t','\0',  24, // Asia/Kuwait
                                                                                                          'A','s','i','a','/','S','e','o','u','l','\0',  25, // Asia/Seoul
                                                                                              'A','s','i','a','/','S','h','a','n','g','h','a','i','\0',  26, // Asia/Shanghai
                                                                                                      'A','s','i','a','/','T','a','i','p','e','i','\0',  26, // Asia/Taipei
                                                                                                      'A','s','i','a','/','T','e','h','r','a','n','\0',  28, // Asia/Tehran
                                                                                                          'A','s','i','a','/','T','o','k','y','o','\0',  29, // Asia/Tokyo
                                                                                                      'A','s','i','a','/','Y','a','n','g','o','n','\0',  30, // Asia/Yangon
                                                                          'A','u','s','t','r','a','l','i','a','/','A','d','e','l','a','i','d','e','\0',  31, // Australia/Adelaide
                                                                          'A','u','s','t','r','a','l','i','a','/','B','r','i','s','b','a','n','e','\0',  32, // Australia/Brisbane
                                                                                  'A','u','s','t','r','a','l','i','a','/','D','a','r','w','i','n','\0',  33, // Australia/Darwin
                                                                                  'A','u','s','t','r','a','l','i','a','/','H','o','b','a','r','t','\0',  34, // Australia/Hobart
                                                                                      'A','u','s','t','r','a','l','i','a','/','P','e','r','t','h','\0',  35, // Australia/Perth
                                                                                  'A','u','s','t','r','a','l','i','a','/','S','y','d','n','e','y','\0',  36, // Australia/Sydney
                                                                                  'E','u','r','o','p','e','/','A','m','s','t','e','r','d','a','m','\0',  37, // Europe/Amsterdam
                                                                                      'E','u','r','o','p','e','/','B','e','l','g','r','a','d','e','\0',  37, // Europe/Belgrade
                                                                                              'E','u','r','o','p','e','/','B','e','r','l','i','n','\0',  37, // Europe/Berlin
                                                                                      'E','u','r','o','p','e','/','B','r','u','s','s','e','l','s','\0',  37, // Europe/Brussels
                                                                                      'E','u','r','o','p','e','/','H','e','l','s','i','n','k','i','\0',  38, // Europe/Helsinki
                                                                                      'E','u','r','o','p','e','/','I','s','t','a','n','b','u','l','\0',  24, // Europe/Istanbul
                                                                                              'E','u','r','o','p','e','/','L','o','n','d','o','n','\0',  39, // Europe/London
                                                                                              'E','u','r','o','p','e','/','M','o','s','c','o','w','\0',  40, // Europe/Moscow
                                                                                      'E','u','r','o','p','e','/','S','a','r','a','j','e','v','o','\0',  37, // Europe/Sarajevo
                                                                                  'P','a','c','i','f','i','c','/','A','u','c','k','l','a','n','d','\0',  41, // Pacific/Auckland
                                                                                                  'P','a','c','i','f','i','c','/','G','u','a','m','\0',  42, // Pacific/Guam
                                                                                  'P','a','c','i','f','i','c','/','H','o','n','o','l','u','l','u','\0',  43, // Pacific/Honolulu
                                                                                          'P','a','c','i','f','i','c','/','M','a','j','u','r','o','\0',  45, // Pacific/Majuro
                                                                                          'P','a','c','i','f','i','c','/','M','i','d','w','a','y','\0',  44, // Pacific/Midway
};
const urule_packed_t* zone_rules = (urule_packed_t*)  _zone_rules;
const char* zone_abrevs = (char*) _zone_abrevs;
const uzone_packed_t* zone_defns = (uzone_packed_t*) _zone_defns;
const char* zone_names = (char*) _zone_names;
