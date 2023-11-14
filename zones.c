#include "utz.h"

const urule_packed_t _zone_rules[88] = {
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AN	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AN	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AS	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AS	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AT	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  1, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AT	2001	max	-	Oct	Sun>=1	2:00s	1:00	D
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	Canada	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	Canada	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 19, 255, 7,  2,  0,  3, 0, 0,  4, 0}, // 	Chile	2019	max	-	Apr	Sun>=2	3:00u	0	-
{ 19, 255, 7,  2,  0,  4, 0, 0,  9, 1}, // 	Chile	2019	max	-	Sep	Sun>=2	4:00u	1:00	-
{  0, 255, 7,  0,  0,  1, 0, 1,  3, 1}, // 	EU	1981	max	-	Mar	lastSun	 1:00u	1:00	S
{  0, 255, 7,  0,  0,  1, 0, 0, 10, 0}, // 	EU	1996	max	-	Oct	lastSun	 1:00u	0	-
{ 21,  23, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2021	2023	-	Mar	21	24:00	1:00	-
{ 24,  24, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2024	only	-	Mar	20	24:00	1:00	-
{ 25,  27, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2025	2027	-	Mar	21	24:00	1:00	-
{ 28,  29, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2028	2029	-	Mar	20	24:00	1:00	-
{ 30,  31, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2030	2031	-	Mar	21	24:00	1:00	-
{ 32,  33, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2032	2033	-	Mar	20	24:00	1:00	-
{ 34,  35, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2034	2035	-	Mar	21	24:00	1:00	-
{ 36,  37, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2036	2037	-	Mar	20	24:00	1:00	-
{ 38,  39, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2038	2039	-	Mar	21	24:00	1:00	-
{ 40,  41, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2040	2041	-	Mar	20	24:00	1:00	-
{ 42,  43, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2042	2043	-	Mar	21	24:00	1:00	-
{ 44,  45, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2044	2045	-	Mar	20	24:00	1:00	-
{ 46,  47, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2046	2047	-	Mar	21	24:00	1:00	-
{ 48,  49, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2048	2049	-	Mar	20	24:00	1:00	-
{ 50,  51, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2050	2051	-	Mar	21	24:00	1:00	-
{ 52,  53, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2052	2053	-	Mar	20	24:00	1:00	-
{ 54,  55, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2054	2055	-	Mar	21	24:00	1:00	-
{ 56,  57, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2056	2057	-	Mar	20	24:00	1:00	-
{ 58,  59, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2058	2059	-	Mar	21	24:00	1:00	-
{ 60,  62, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2060	2062	-	Mar	20	24:00	1:00	-
{ 63,  63, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2063	only	-	Mar	21	24:00	1:00	-
{ 64,  66, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2064	2066	-	Mar	20	24:00	1:00	-
{ 67,  67, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2067	only	-	Mar	21	24:00	1:00	-
{ 68,  70, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2068	2070	-	Mar	20	24:00	1:00	-
{ 71,  71, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2071	only	-	Mar	21	24:00	1:00	-
{ 72,  74, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2072	2074	-	Mar	20	24:00	1:00	-
{ 75,  75, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2075	only	-	Mar	21	24:00	1:00	-
{ 76,  78, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2076	2078	-	Mar	20	24:00	1:00	-
{ 79,  79, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2079	only	-	Mar	21	24:00	1:00	-
{ 80,  82, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2080	2082	-	Mar	20	24:00	1:00	-
{ 83,  83, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2083	only	-	Mar	21	24:00	1:00	-
{ 84,  86, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2084	2086	-	Mar	20	24:00	1:00	-
{ 87,  87, 0, 21,  1, 24, 0, 0,  3, 1}, // 	Iran	2087	only	-	Mar	21	24:00	1:00	-
{ 88, 255, 0, 20,  1, 24, 0, 0,  3, 1}, // 	Iran	2088	max	-	Mar	20	24:00	1:00	-
{ 21,  23, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2021	2023	-	Sep	21	24:00	0	-
{ 24,  24, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2024	only	-	Sep	20	24:00	0	-
{ 25,  27, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2025	2027	-	Sep	21	24:00	0	-
{ 28,  29, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2028	2029	-	Sep	20	24:00	0	-
{ 30,  31, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2030	2031	-	Sep	21	24:00	0	-
{ 32,  33, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2032	2033	-	Sep	20	24:00	0	-
{ 34,  35, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2034	2035	-	Sep	21	24:00	0	-
{ 36,  37, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2036	2037	-	Sep	20	24:00	0	-
{ 38,  39, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2038	2039	-	Sep	21	24:00	0	-
{ 40,  41, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2040	2041	-	Sep	20	24:00	0	-
{ 42,  43, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2042	2043	-	Sep	21	24:00	0	-
{ 44,  45, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2044	2045	-	Sep	20	24:00	0	-
{ 46,  47, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2046	2047	-	Sep	21	24:00	0	-
{ 48,  49, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2048	2049	-	Sep	20	24:00	0	-
{ 50,  51, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2050	2051	-	Sep	21	24:00	0	-
{ 52,  53, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2052	2053	-	Sep	20	24:00	0	-
{ 54,  55, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2054	2055	-	Sep	21	24:00	0	-
{ 56,  57, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2056	2057	-	Sep	20	24:00	0	-
{ 58,  59, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2058	2059	-	Sep	21	24:00	0	-
{ 60,  62, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2060	2062	-	Sep	20	24:00	0	-
{ 63,  63, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2063	only	-	Sep	21	24:00	0	-
{ 64,  66, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2064	2066	-	Sep	20	24:00	0	-
{ 67,  67, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2067	only	-	Sep	21	24:00	0	-
{ 68,  70, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2068	2070	-	Sep	20	24:00	0	-
{ 71,  71, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2071	only	-	Sep	21	24:00	0	-
{ 72,  74, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2072	2074	-	Sep	20	24:00	0	-
{ 75,  75, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2075	only	-	Sep	21	24:00	0	-
{ 76,  78, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2076	2078	-	Sep	20	24:00	0	-
{ 79,  79, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2079	only	-	Sep	21	24:00	0	-
{ 80,  82, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2080	2082	-	Sep	20	24:00	0	-
{ 83,  83, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2083	only	-	Sep	21	24:00	0	-
{ 84,  86, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2084	2086	-	Sep	20	24:00	0	-
{ 87,  87, 0, 21,  1, 23, 0, 0,  9, 0}, // 	Iran	2087	only	-	Sep	21	24:00	0	-
{ 88, 255, 0, 20,  1, 23, 0, 0,  9, 0}, // 	Iran	2088	max	-	Sep	20	24:00	0	-
{  2, 255, 7,  1,  1,  2, 0, 2,  4, 1}, // 	Mexico	2002	max	-	Apr	Sun>=1	2:00	1:00	D
{  2, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Mexico	2002	max	-	Oct	lastSun	2:00	0	S
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	NZ	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  7, 255, 7,  0,  1,  2, 0, 2,  9, 1}, // 	NZ	2007	max	-	Sep	lastSun	2:00s	1:00	D
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	US	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	US	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 13, 255, 5, 23,  1,  2, 0, 2,  3, 1}, // 	Zion	2013	max	-	Mar	Fri>=23	2:00	1:00	D
{ 13, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Zion	2013	max	-	Oct	lastSun	2:00	0	S
};

const char _zone_abrevs[209] = {
'E','E','S','T','\0',
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
'E','%','c','T','\0',
'M','S','T','\0',
'C','S','T','\0',
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
'+','0','3','3','0','/','+','0','4','3','0','\0',
'J','S','T','\0',
'+','0','6','3','0','\0',
'A','C','%','c','T','\0',
'A','E','S','T','\0',
'A','C','S','T','\0',
'A','E','%','c','T','\0',
'A','W','S','T','\0',
'C','E','%','c','T','\0',
'E','E','%','c','T','\0',
'G','M','T','/','B','S','T','\0',
'M','S','K','\0',
'N','Z','%','c','T','\0',
'C','h','S','T','\0',
'H','S','T','\0',
'S','S','T','\0',
};

const uzone_packed_t _zone_defns[43] = {
// Africa/Cairo	2:00	Egypt	EE%sT
{  8,   0,   0,   0},
// Africa/Lagos	1:00	-	WAT
{  4,   0,   0,   5},
// Africa/Maputo	2:00	-	CAT
{  8,   0,   0,   9},
// Africa/Nairobi	3:00	-	EAT
{ 12,   0,   0,  13},
// America/Anchorage	-9:00	US	AK%sT
{-36,  84,   2,  17},
// America/Argentina/Buenos_Aires	-3:00	Arg	-03/-02
// America/Sao_Paulo	-3:00	Brazil	-03/-02
{-12,   0,   0,  23},
// America/Chicago	-6:00	US	C%sT
{-24,  84,   2,  31},
// America/Denver	-7:00	US	M%sT
{-28,  84,   2,  36},
// America/Halifax	-4:00	Canada	A%sT
{-16,   6,   2,  41},
// America/Los_Angeles	-8:00	US	P%sT
// America/Tijuana	-8:00	US	P%sT
{-32,  84,   2,  46},
// America/Manaus	-4:00	-	-04
{-16,   0,   0,  51},
// America/Mexico_City	-6:00	Mexico	C%sT
{-24,  80,   2,  31},
// America/New_York	-5:00	US	E%sT
{-20,  84,   2,  55},
// America/Phoenix	-7:00	-	MST
{-28,   0,   0,  60},
// America/Regina	-6:00	-	CST
{-24,   0,   0,  64},
// America/Santiago	-4:00	Chile	-04/-03
{-16,   8,   2,  68},
// America/St_Johns	-3:30	Canada	N%sT
{-14,   6,   2,  76},
// Asia/Bangkok	7:00	-	+07
// Asia/Ho_Chi_Minh	7:00	-	+07
{ 28,   0,   0,  81},
// Asia/Dubai	4:00	-	+04
{ 16,   0,   0,  85},
// Asia/Hong_Kong	8:00	HK	HK%sT
{ 32,   0,   0,  89},
// Asia/Jerusalem	2:00	Zion	I%sT
{  8,  86,   2,  94},
// Asia/Kathmandu	5:45	-	+0545
{ 23,   0,   0,  99},
// Asia/Kolkata	5:30	-	IST
{ 22,   0,   0, 105},
// Asia/Riyadh	3:00	-	+03
// Europe/Istanbul	3:00	-	+03
{ 12,   0,   0, 109},
// Asia/Seoul	9:00	ROK	K%sT
{ 36,   0,   0, 113},
// Asia/Shanghai	8:00	PRC	C%sT
// Asia/Taipei	8:00	Taiwan	C%sT
{ 32,   0,   0,  64},
// Asia/Tehran	3:30	Iran	+0330/+0430
{ 14,  12,  68, 117},
// Asia/Tokyo	9:00	Japan	J%sT
{ 36,   0,   0, 129},
// Asia/Yangon	6:30	-	+0630
{ 26,   0,   0, 133},
// Australia/Adelaide	9:30	AS	AC%sT
{ 38,   2,   2, 139},
// Australia/Brisbane	10:00	AQ	AE%sT
{ 40,   0,   0, 145},
// Australia/Darwin	9:30	Aus	AC%sT
{ 38,   0,   0, 150},
// Australia/Hobart	10:00	AT	AE%sT
{ 40,   4,   2, 155},
// Australia/Perth	8:00	AW	AW%sT
{ 32,   0,   0, 161},
// Australia/Sydney	10:00	AN	AE%sT
{ 40,   0,   2, 155},
// Europe/Belgrade	1:00	EU	CE%sT
{  4,  10,   2, 166},
// Europe/Helsinki	2:00	EU	EE%sT
{  8,  10,   2, 172},
// Europe/London	0:00	EU	GMT/BST
{  0,  10,   2, 178},
// Europe/Moscow	3:00	-	MSK
{ 12,   0,   0, 186},
// Pacific/Auckland	12:00	NZ	NZ%sT
{ 48,  82,   2, 190},
// Pacific/Guam	10:00	-	ChST
{ 40,   0,   0, 196},
// Pacific/Honolulu	-10:00	-	HST
{-40,   0,   0, 201},
// Pacific/Pago_Pago	-11:00	-	SST
{-44,   0,   0, 205},
};

const char _zone_names[475] = {
                        'A','d','e','l','a','i','d','e','\0',  29, // Adelaide
                    'A','n','c','h','o','r','a','g','e','\0',   4, // Anchorage
                        'A','u','c','k','l','a','n','d','\0',  39, // Auckland
                            'B','a','n','g','k','o','k','\0',  17, // Bangkok
                        'B','e','l','g','r','a','d','e','\0',  35, // Belgrade
            'B','r','a','z','z','a','v','i','l','l','e','\0',   1, // Brazzaville
                        'B','r','i','s','b','a','n','e','\0',  30, // Brisbane
        'B','u','e','n','o','s',' ','A','i','r','e','s','\0',   5, // Buenos Aires
                                    'C','a','i','r','o','\0',   0, // Cairo
                            'C','h','i','c','a','g','o','\0',   6, // Chicago
                    'C','h','o','n','g','q','i','n','g','\0',  25, // Chongqing
                                'D','a','r','w','i','n','\0',  31, // Darwin
                                'D','e','n','v','e','r','\0',   7, // Denver
                                    'D','u','b','a','i','\0',  18, // Dubai
                                        'G','u','a','m','\0',  40, // Guam
                            'H','a','l','i','f','a','x','\0',   8, // Halifax
                                'H','a','r','a','r','e','\0',   2, // Harare
                        'H','e','l','s','i','n','k','i','\0',  36, // Helsinki
            'H','o',' ','C','h','i',' ','M','i','n','h','\0',  17, // Ho Chi Minh
                                'H','o','b','a','r','t','\0',  32, // Hobart
                    'H','o','n','g',' ','K','o','n','g','\0',  19, // Hong Kong
                        'H','o','n','o','l','u','l','u','\0',  41, // Honolulu
                        'I','s','t','a','n','b','u','l','\0',  23, // Istanbul
                    'J','e','r','u','s','a','l','e','m','\0',  20, // Jerusalem
                    'K','a','t','h','m','a','n','d','u','\0',  21, // Kathmandu
                            'K','o','l','k','a','t','a','\0',  22, // Kolkata
                                'K','u','w','a','i','t','\0',  23, // Kuwait
                                    'L','a','g','o','s','\0',   1, // Lagos
                                'L','o','n','d','o','n','\0',  37, // London
            'L','o','s',' ','A','n','g','e','l','e','s','\0',   9, // Los Angeles
                                'M','a','n','a','u','s','\0',  10, // Manaus
            'M','e','x','i','c','o',' ','C','i','t','y','\0',  11, // Mexico City
                                'M','i','d','w','a','y','\0',  42, // Midway
                                'M','o','s','c','o','w','\0',  38, // Moscow
                            'N','a','i','r','o','b','i','\0',   3, // Nairobi
                        'N','e','w',' ','Y','o','r','k','\0',  12, // New York
                                    'P','e','r','t','h','\0',  33, // Perth
                            'P','h','o','e','n','i','x','\0',  13, // Phoenix
                                'R','e','g','i','n','a','\0',  14, // Regina
                        'S','a','n','t','i','a','g','o','\0',  15, // Santiago
                    'S','a','o',' ','P','a','u','l','o','\0',   5, // Sao Paulo
                        'S','a','r','a','j','e','v','o','\0',  35, // Sarajevo
                                    'S','e','o','u','l','\0',  24, // Seoul
                        'S','h','a','n','g','h','a','i','\0',  25, // Shanghai
                        'S','t',' ','J','o','h','n','s','\0',  16, // St Johns
                                'S','y','d','n','e','y','\0',  34, // Sydney
                                'T','a','i','p','e','i','\0',  25, // Taipei
                                'T','e','h','r','a','n','\0',  26, // Tehran
                            'T','i','j','u','a','n','a','\0',   9, // Tijuana
                                    'T','o','k','y','o','\0',  27, // Tokyo
                                'Y','a','n','g','o','n','\0',  28, // Yangon
};
const urule_packed_t* zone_rules = (urule_packed_t*)  _zone_rules;
const char* zone_abrevs = (char*) _zone_abrevs;
const uzone_packed_t* zone_defns = (uzone_packed_t*) _zone_defns;
const char* zone_names = (char*) _zone_names;
