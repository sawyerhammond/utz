#include "utz.h"

const urule_packed_t _zone_rules[34] = {
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AN	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AN	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AS	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AS	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AT	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  1, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AT	2001	max	-	Oct	Sun>=1	2:00s	1:00	D
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	AV	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  8, 255, 7,  1,  1,  2, 0, 2, 10, 1}, // 	AV	2008	max	-	Oct	Sun>=1	2:00s	1:00	D
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	Canada	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	Canada	2007	max	-	Nov	Sun>=1	2:00	0	S
{  8, 255, 7,  1,  1,  2, 0, 0,  4, 0}, // 	Chatham	2008	max	-	Apr	Sun>=1	2:45s	0	-
{  7, 255, 7,  0,  1,  2, 0, 0,  9, 1}, // 	Chatham	2007	max	-	Sep	lastSun	2:45s	1:00	-
{ 19, 255, 7,  2,  0,  3, 0, 0,  4, 0}, // 	Chile	2019	max	-	Apr	Sun>=2	3:00u	0	-
{ 23, 255, 7,  2,  0,  4, 0, 0,  9, 1}, // 	Chile	2023	max	-	Sep	Sun>=2	4:00u	1:00	-
{ 13, 255, 7,  8,  1,  0, 0, 2,  3, 1}, // 	Cuba	2013	max	-	Mar	Sun>=8	0:00s	1:00	D
{ 12, 255, 7,  1,  1,  0, 0, 1, 11, 0}, // 	Cuba	2012	max	-	Nov	Sun>=1	0:00s	0	S
{  0, 255, 7,  0,  0,  1, 0, 1,  3, 1}, // 	EU	1981	max	-	Mar	lastSun	 1:00u	1:00	S
{  0, 255, 7,  0,  0,  1, 0, 0, 10, 0}, // 	EU	1996	max	-	Oct	lastSun	 1:00u	0	-
{  0, 255, 7,  0,  0,  1, 0, 1,  3, 1}, // 	EUAsia	1981	max	-	Mar	lastSun	 1:00u	1:00	S
{  0, 255, 7,  0,  0,  1, 0, 0, 10, 0}, // 	EUAsia	1996	max	-	Oct	lastSun	 1:00u	0	-
{ 23, 255, 5,  0,  1,  0, 0, 1,  4, 1}, // 	Egypt	2023	max	-	Apr	lastFri	 0:00	1:00	S
{ 23, 255, 4,  0,  1, 23, 0, 0, 10, 0}, // 	Egypt	2023	max	-	Oct	lastThu	24:00	0	-
{  0, 255, 7,  0,  0,  1, 0, 0,  3, 0}, // 	Eire	1981	max	-	Mar	lastSun	 1:00u	0	-
{  0, 255, 7,  0,  0,  1, 0, 0, 10, -1}, // 	Eire	1996	max	-	Oct	lastSun	 1:00u	-1:00	-
{  8, 255, 7,  1,  1,  1, 0, 0,  4, 0}, // 	LH	2008	max	-	Apr	Sun>=1	2:00	0	-
{  8, 255, 7,  1,  1,  1, 0, 0, 10, 0}, // 	LH	2008	max	-	Oct	Sun>=1	2:00	0:30	-
{  0, 255, 7,  0,  1,  2, 0, 1,  3, 1}, // 	Moldova	1997	max	-	Mar	lastSun	 2:00	1:00	S
{  0, 255, 7,  0,  1,  2, 0, 0, 10, 0}, // 	Moldova	1997	max	-	Oct	lastSun	 3:00	0	-
{  8, 255, 7,  1,  1,  2, 0, 1,  4, 0}, // 	NZ	2008	max	-	Apr	Sun>=1	2:00s	0	S
{  7, 255, 7,  0,  1,  2, 0, 2,  9, 1}, // 	NZ	2007	max	-	Sep	lastSun	2:00s	1:00	D
{  7, 255, 7,  8,  1,  2, 0, 2,  3, 1}, // 	US	2007	max	-	Mar	Sun>=8	2:00	1:00	D
{  7, 255, 7,  1,  1,  1, 0, 1, 11, 0}, // 	US	2007	max	-	Nov	Sun>=1	2:00	0	S
{ 13, 255, 5, 23,  1,  2, 0, 2,  3, 1}, // 	Zion	2013	max	-	Mar	Fri>=23	2:00	1:00	D
{ 13, 255, 7,  0,  1,  1, 0, 1, 10, 0}, // 	Zion	2013	max	-	Oct	lastSun	2:00	0	S
};

const char _zone_abrevs[343] = {
'G','M','T','\0',
'E','E','%','c','T','\0',
'S','A','S','T','\0',
'W','A','T','\0',
'C','A','T','\0',
'E','A','T','\0',
'E','E','T','\0',
'H','%','c','T','\0',
'A','K','%','c','T','\0',
'-','0','3','/','-','0','2','\0',
'-','0','3','\0',
'C','%','c','T','\0',
'M','%','c','T','\0',
'E','%','c','T','\0',
'A','%','c','T','\0',
'E','S','T','\0',
'P','%','c','T','\0',
'-','0','4','\0',
'M','S','T','\0',
'C','S','T','\0',
'-','0','2','\0',
'-','0','2','/','-','0','1','\0',
'A','S','T','\0',
'-','0','5','\0',
'-','0','4','/','-','0','3','\0',
'N','%','c','T','\0',
'+','0','5','\0',
'+','0','7','\0',
'+','0','6','/','+','0','7','\0',
'+','0','4','\0',
'H','K','S','T','\0',
'I','%','c','T','\0',
'+','0','5','4','5','\0',
'I','S','T','\0',
'+','0','8','\0',
'W','I','T','A','\0',
'+','0','3','\0',
'K','S','T','\0',
'+','0','3','3','0','/','+','0','4','3','0','\0',
'+','0','6','\0',
'J','S','T','\0',
'+','0','8','/','+','0','9','\0',
'+','0','6','3','0','\0',
'W','E','%','c','T','\0',
'A','C','%','c','T','\0',
'A','E','S','T','\0',
'A','C','S','T','\0',
'A','E','%','c','T','\0',
'+','1','0','3','0','/','+','1','1','\0',
'A','W','S','T','\0',
'C','E','%','c','T','\0',
'I','S','T','/','G','M','T','\0',
'G','M','T','/','B','S','T','\0',
'M','S','K','\0',
'N','Z','%','c','T','\0',
'+','1','2','4','5','/','+','1','3','4','5','\0',
'-','0','6','/','-','0','5','\0',
'+','1','1','\0',
'C','h','S','T','\0',
'H','S','T','\0',
'+','1','3','\0',
'+','1','2','\0',
'S','S','T','\0',
'+','1','0','\0',
};

const uzone_packed_t _zone_defns[76] = {
// Africa/Abidjan	0:00	-	GMT
{  0,   0,   0,   0},
// Africa/Cairo	2:00	Egypt	EE%sT
{  8,  20,   2,   4},
// Africa/Johannesburg	2:00	SA	SAST
{  8,   0,   0,  10},
// Africa/Lagos	1:00	-	WAT
{  4,   0,   0,  15},
// Africa/Maputo	2:00	-	CAT
{  8,   0,   0,  19},
// Africa/Nairobi	3:00	-	EAT
{ 12,   0,   0,  23},
// Africa/Tripoli	2:00	-	EET
{  8,   0,   0,  27},
// America/Adak	-10:00	US	H%sT
{-40,  30,   2,  31},
// America/Anchorage	-9:00	US	AK%sT
{-36,  30,   2,  36},
// America/Argentina/Buenos_Aires	-3:00	Arg	-03/-02
// America/Argentina/Cordoba	-3:00	Arg	-03/-02
// America/Sao_Paulo	-3:00	Brazil	-03/-02
{-12,   0,   0,  42},
// America/Argentina/Catamarca	-3:00	-	-03
// America/Argentina/Jujuy	-3:00	-	-03
// America/Argentina/Mendoza	-3:00	-	-03
{-12,   0,   0,  50},
// America/Chicago	-6:00	US	C%sT
// America/Indiana/Knox	-6:00	US	C%sT
{-24,  30,   2,  54},
// America/Denver	-7:00	US	M%sT
{-28,  30,   2,  59},
// America/Detroit	-5:00	US	E%sT
// America/Indiana/Indianapolis	-5:00	US	E%sT
// America/Kentucky/Louisville	-5:00	US	E%sT
// America/New_York	-5:00	US	E%sT
{-20,  30,   2,  64},
// America/Edmonton	-7:00	Canada	M%sT
{-28,   8,   2,  59},
// America/Halifax	-4:00	Canada	A%sT
{-16,   8,   2,  69},
// America/Havana	-5:00	Cuba	C%sT
{-20,  14,   2,  54},
// America/Iqaluit	-5:00	Canada	E%sT
// America/Toronto	-5:00	Canada	E%sT
{-20,   8,   2,  64},
// America/Jamaica	-5:00	-	EST
// America/Panama	-5:00	-	EST
{-20,   0,   0,  74},
// America/Los_Angeles	-8:00	US	P%sT
// America/Tijuana	-8:00	US	P%sT
{-32,  30,   2,  78},
// America/Manaus	-4:00	-	-04
{-16,   0,   0,  83},
// America/Mazatlan	-7:00	Mexico	M%sT
// America/Phoenix	-7:00	-	MST
// America/Whitehorse	-7:00	-	MST
{-28,   0,   0,  87},
// America/Mexico_City	-6:00	Mexico	C%sT
// America/Regina	-6:00	-	CST
{-24,   0,   0,  91},
// America/Noronha	-2:00	-	-02
{ -8,   0,   0,  95},
// America/Nuuk	-3:00	EU	-03/-02	2023
{-12,  16,   2,  42},
// America/Nuuk	-2:00	EU	-02/-01
{ -8,  16,   2,  99},
// America/Puerto_Rico	-4:00	-	AST
{-16,   0,   0, 107},
// America/Rio_Branco	-5:00	-	-05
{-20,   0,   0, 111},
// America/Santiago	-4:00	Chile	-04/-03
{-16,  12,   2, 115},
// America/St_Johns	-3:30	Canada	N%sT
{-14,   8,   2, 123},
// America/Vancouver	-8:00	Canada	P%sT
{-32,   8,   2,  78},
// America/Winnipeg	-6:00	Canada	C%sT
{-24,   8,   2,  54},
// Asia/Ashgabat	5:00	-	+05
// Indian/Maldives	5:00	-	+05
{ 20,   0,   0, 128},
// Asia/Bangkok	7:00	-	+07
// Asia/Ho_Chi_Minh	7:00	-	+07
{ 28,   0,   0, 132},
// Asia/Dhaka	6:00	Dhaka	+06/+07
{ 24,   0,   0, 136},
// Asia/Dubai	4:00	-	+04
{ 16,   0,   0, 144},
// Asia/Hong_Kong	8:00	HK	HK%sT
{ 32,   0,   0, 148},
// Asia/Jerusalem	2:00	Zion	I%sT
{  8,  32,   2, 153},
// Asia/Kathmandu	5:45	-	+0545
{ 23,   0,   0, 158},
// Asia/Kolkata	5:30	-	IST
{ 22,   0,   0, 164},
// Asia/Kuching	8:00	-	+08
// Asia/Singapore	8:00	-	+08
{ 32,   0,   0, 168},
// Asia/Macau	8:00	Macau	C%sT
// Asia/Shanghai	8:00	PRC	C%sT
// Asia/Taipei	8:00	Taiwan	C%sT
{ 32,   0,   0,  91},
// Asia/Makassar	8:00	-	WITA
{ 32,   0,   0, 172},
// Asia/Nicosia	2:00	EUAsia	EE%sT
{  8,  18,   2,   4},
// Asia/Qatar	3:00	-	+03
// Asia/Riyadh	3:00	-	+03
// Europe/Istanbul	3:00	-	+03
{ 12,   0,   0, 177},
// Asia/Seoul	9:00	ROK	K%sT
{ 36,   0,   0, 181},
// Asia/Tehran	3:30	Iran	+0330/+0430
{ 14,   0,   0, 185},
// Asia/Thimphu	6:00	-	+06
// Asia/Urumqi	6:00	-	+06
{ 24,   0,   0, 197},
// Asia/Tokyo	9:00	Japan	J%sT
{ 36,   0,   0, 201},
// Asia/Ulaanbaatar	8:00	Mongol	+08/+09
{ 32,   0,   0, 205},
// Asia/Yangon	6:30	-	+0630
{ 26,   0,   0, 213},
// Atlantic/Faroe	0:00	EU	WE%sT
// Europe/Lisbon	0:00	EU	WE%sT
{  0,  16,   2, 219},
// Australia/Adelaide	9:30	AS	AC%sT
// Australia/Broken_Hill	9:30	AS	AC%sT
{ 38,   2,   2, 225},
// Australia/Brisbane	10:00	AQ	AE%sT
{ 40,   0,   0, 231},
// Australia/Darwin	9:30	Aus	AC%sT
{ 38,   0,   0, 236},
// Australia/Hobart	10:00	AT	AE%sT
{ 40,   4,   2, 241},
// Australia/Lord_Howe	10:30	LH	+1030/+11
{ 42,  24,   2, 247},
// Australia/Melbourne	10:00	AV	AE%sT
{ 40,   6,   2, 241},
// Australia/Perth	8:00	AW	AW%sT
{ 32,   0,   0, 257},
// Australia/Sydney	10:00	AN	AE%sT
{ 40,   0,   2, 241},
// Europe/Belgrade	1:00	EU	CE%sT
// Europe/Berlin	1:00	EU	CE%sT
// Europe/Brussels	1:00	EU	CE%sT
// Europe/Paris	1:00	EU	CE%sT
// Europe/Prague	1:00	EU	CE%sT
// Europe/Rome	1:00	EU	CE%sT
// Europe/Warsaw	1:00	EU	CE%sT
// Europe/Zurich	1:00	EU	CE%sT
{  4,  16,   2, 262},
// Europe/Chisinau	2:00	Moldova	EE%sT
{  8,  26,   2,   4},
// Europe/Dublin	1:00	Eire	IST/GMT
{  4,  22,   2, 268},
// Europe/Helsinki	2:00	EU	EE%sT
// Europe/Kyiv	2:00	EU	EE%sT
{  8,  16,   2,   4},
// Europe/London	0:00	EU	GMT/BST
{  0,  16,   2, 276},
// Europe/Moscow	3:00	-	MSK
{ 12,   0,   0, 284},
// Pacific/Auckland	12:00	NZ	NZ%sT
{ 48,  28,   2, 288},
// Pacific/Chatham	12:45	Chatham	+1245/+1345
{ 51,  10,   2, 294},
// Pacific/Easter	-6:00	Chile	-06/-05
{-24,  12,   2, 306},
// Pacific/Guadalcanal	11:00	-	+11
{ 44,   0,   0, 314},
// Pacific/Guam	10:00	-	ChST
{ 40,   0,   0, 318},
// Pacific/Honolulu	-10:00	-	HST
{-40,   0,   0, 323},
// Pacific/Kanton	13:00	-	+13
{ 52,   0,   0, 327},
// Pacific/Kwajalein	12:00	-	+12
// Pacific/Tarawa	12:00	-	+12
{ 48,   0,   0, 331},
// Pacific/Pago_Pago	-11:00	-	SST
{-44,   0,   0, 335},
// Pacific/Port_Moresby	10:00	-	+10
{ 40,   0,   0, 339},
};

const char _zone_names[1864] = {
                                                                                          'A','f','r','i','c','a','/','A','b','i','d','j','a','n','\0',   0, // Africa/Abidjan
                                                                                                  'A','f','r','i','c','a','/','C','a','i','r','o','\0',   1, // Africa/Cairo
                                                                      'A','f','r','i','c','a','/','J','o','h','a','n','n','e','s','b','u','r','g','\0',   2, // Africa/Johannesburg
                                                                                                  'A','f','r','i','c','a','/','L','a','g','o','s','\0',   3, // Africa/Lagos
                                                                                              'A','f','r','i','c','a','/','M','a','p','u','t','o','\0',   4, // Africa/Maputo
                                                                                          'A','f','r','i','c','a','/','N','a','i','r','o','b','i','\0',   5, // Africa/Nairobi
                                                                                          'A','f','r','i','c','a','/','T','r','i','p','o','l','i','\0',   6, // Africa/Tripoli
                                                                                                  'A','m','e','r','i','c','a','/','A','d','a','k','\0',   7, // America/Adak
                                                                              'A','m','e','r','i','c','a','/','A','n','c','h','o','r','a','g','e','\0',   8, // America/Anchorage
                          'A','m','e','r','i','c','a','/','A','r','g','e','n','t','i','n','a','/','B','u','e','n','o','s','_','A','i','r','e','s','\0',   9, // America/Argentina/Buenos_Aires
                                      'A','m','e','r','i','c','a','/','A','r','g','e','n','t','i','n','a','/','C','a','t','a','m','a','r','c','a','\0',  10, // America/Argentina/Catamarca
                                              'A','m','e','r','i','c','a','/','A','r','g','e','n','t','i','n','a','/','C','o','r','d','o','b','a','\0',   9, // America/Argentina/Cordoba
                                                      'A','m','e','r','i','c','a','/','A','r','g','e','n','t','i','n','a','/','J','u','j','u','y','\0',  10, // America/Argentina/Jujuy
                                              'A','m','e','r','i','c','a','/','A','r','g','e','n','t','i','n','a','/','M','e','n','d','o','z','a','\0',  10, // America/Argentina/Mendoza
                                                                                      'A','m','e','r','i','c','a','/','C','h','i','c','a','g','o','\0',  11, // America/Chicago
                                                                                          'A','m','e','r','i','c','a','/','D','e','n','v','e','r','\0',  12, // America/Denver
                                                                                      'A','m','e','r','i','c','a','/','D','e','t','r','o','i','t','\0',  13, // America/Detroit
                                                                                  'A','m','e','r','i','c','a','/','E','d','m','o','n','t','o','n','\0',  14, // America/Edmonton
                                                                                      'A','m','e','r','i','c','a','/','H','a','l','i','f','a','x','\0',  15, // America/Halifax
                                                                                          'A','m','e','r','i','c','a','/','H','a','v','a','n','a','\0',  16, // America/Havana
                                  'A','m','e','r','i','c','a','/','I','n','d','i','a','n','a','/','I','n','d','i','a','n','a','p','o','l','i','s','\0',  13, // America/Indiana/Indianapolis
                                                                  'A','m','e','r','i','c','a','/','I','n','d','i','a','n','a','/','K','n','o','x','\0',  11, // America/Indiana/Knox
                                                                                      'A','m','e','r','i','c','a','/','I','q','a','l','u','i','t','\0',  17, // America/Iqaluit
                                                                                      'A','m','e','r','i','c','a','/','J','a','m','a','i','c','a','\0',  18, // America/Jamaica
                                      'A','m','e','r','i','c','a','/','K','e','n','t','u','c','k','y','/','L','o','u','i','s','v','i','l','l','e','\0',  13, // America/Kentucky/Louisville
                                                                      'A','m','e','r','i','c','a','/','L','o','s','_','A','n','g','e','l','e','s','\0',  19, // America/Los_Angeles
                                                                                          'A','m','e','r','i','c','a','/','M','a','n','a','u','s','\0',  20, // America/Manaus
                                                                                  'A','m','e','r','i','c','a','/','M','a','z','a','t','l','a','n','\0',  21, // America/Mazatlan
                                                                      'A','m','e','r','i','c','a','/','M','e','x','i','c','o','_','C','i','t','y','\0',  22, // America/Mexico_City
                                                                                  'A','m','e','r','i','c','a','/','N','e','w','_','Y','o','r','k','\0',  13, // America/New_York
                                                                                      'A','m','e','r','i','c','a','/','N','o','r','o','n','h','a','\0',  23, // America/Noronha
                                                                                                  'A','m','e','r','i','c','a','/','N','u','u','k','\0',  25, // America/Nuuk
                                                                                          'A','m','e','r','i','c','a','/','P','a','n','a','m','a','\0',  18, // America/Panama
                                                                                      'A','m','e','r','i','c','a','/','P','h','o','e','n','i','x','\0',  21, // America/Phoenix
                                                                      'A','m','e','r','i','c','a','/','P','u','e','r','t','o','_','R','i','c','o','\0',  26, // America/Puerto_Rico
                                                                                          'A','m','e','r','i','c','a','/','R','e','g','i','n','a','\0',  22, // America/Regina
                                                                          'A','m','e','r','i','c','a','/','R','i','o','_','B','r','a','n','c','o','\0',  27, // America/Rio_Branco
                                                                                  'A','m','e','r','i','c','a','/','S','a','n','t','i','a','g','o','\0',  28, // America/Santiago
                                                                              'A','m','e','r','i','c','a','/','S','a','o','_','P','a','u','l','o','\0',   9, // America/Sao_Paulo
                                                                                  'A','m','e','r','i','c','a','/','S','t','_','J','o','h','n','s','\0',  29, // America/St_Johns
                                                                                      'A','m','e','r','i','c','a','/','T','i','j','u','a','n','a','\0',  19, // America/Tijuana
                                                                                      'A','m','e','r','i','c','a','/','T','o','r','o','n','t','o','\0',  17, // America/Toronto
                                                                              'A','m','e','r','i','c','a','/','V','a','n','c','o','u','v','e','r','\0',  30, // America/Vancouver
                                                                          'A','m','e','r','i','c','a','/','W','h','i','t','e','h','o','r','s','e','\0',  21, // America/Whitehorse
                                                                                  'A','m','e','r','i','c','a','/','W','i','n','n','i','p','e','g','\0',  31, // America/Winnipeg
                                                                                              'A','s','i','a','/','A','s','h','g','a','b','a','t','\0',  32, // Asia/Ashgabat
                                                                                                  'A','s','i','a','/','B','a','n','g','k','o','k','\0',  33, // Asia/Bangkok
                                                                                                          'A','s','i','a','/','D','h','a','k','a','\0',  34, // Asia/Dhaka
                                                                                                          'A','s','i','a','/','D','u','b','a','i','\0',  35, // Asia/Dubai
                                                                                  'A','s','i','a','/','H','o','_','C','h','i','_','M','i','n','h','\0',  33, // Asia/Ho_Chi_Minh
                                                                                          'A','s','i','a','/','H','o','n','g','_','K','o','n','g','\0',  36, // Asia/Hong_Kong
                                                                                          'A','s','i','a','/','J','e','r','u','s','a','l','e','m','\0',  37, // Asia/Jerusalem
                                                                                          'A','s','i','a','/','K','a','t','h','m','a','n','d','u','\0',  38, // Asia/Kathmandu
                                                                                                  'A','s','i','a','/','K','o','l','k','a','t','a','\0',  39, // Asia/Kolkata
                                                                                                  'A','s','i','a','/','K','u','c','h','i','n','g','\0',  40, // Asia/Kuching
                                                                                                          'A','s','i','a','/','M','a','c','a','u','\0',  41, // Asia/Macau
                                                                                              'A','s','i','a','/','M','a','k','a','s','s','a','r','\0',  42, // Asia/Makassar
                                                                                                  'A','s','i','a','/','N','i','c','o','s','i','a','\0',  43, // Asia/Nicosia
                                                                                                          'A','s','i','a','/','Q','a','t','a','r','\0',  44, // Asia/Qatar
                                                                                                      'A','s','i','a','/','R','i','y','a','d','h','\0',  44, // Asia/Riyadh
                                                                                                          'A','s','i','a','/','S','e','o','u','l','\0',  45, // Asia/Seoul
                                                                                              'A','s','i','a','/','S','h','a','n','g','h','a','i','\0',  41, // Asia/Shanghai
                                                                                          'A','s','i','a','/','S','i','n','g','a','p','o','r','e','\0',  40, // Asia/Singapore
                                                                                                      'A','s','i','a','/','T','a','i','p','e','i','\0',  41, // Asia/Taipei
                                                                                                      'A','s','i','a','/','T','e','h','r','a','n','\0',  46, // Asia/Tehran
                                                                                                  'A','s','i','a','/','T','h','i','m','p','h','u','\0',  47, // Asia/Thimphu
                                                                                                          'A','s','i','a','/','T','o','k','y','o','\0',  48, // Asia/Tokyo
                                                                                  'A','s','i','a','/','U','l','a','a','n','b','a','a','t','a','r','\0',  49, // Asia/Ulaanbaatar
                                                                                                      'A','s','i','a','/','U','r','u','m','q','i','\0',  47, // Asia/Urumqi
                                                                                                      'A','s','i','a','/','Y','a','n','g','o','n','\0',  50, // Asia/Yangon
                                                                                          'A','t','l','a','n','t','i','c','/','F','a','r','o','e','\0',  51, // Atlantic/Faroe
                                                                          'A','u','s','t','r','a','l','i','a','/','A','d','e','l','a','i','d','e','\0',  52, // Australia/Adelaide
                                                                          'A','u','s','t','r','a','l','i','a','/','B','r','i','s','b','a','n','e','\0',  53, // Australia/Brisbane
                                                              'A','u','s','t','r','a','l','i','a','/','B','r','o','k','e','n','_','H','i','l','l','\0',  52, // Australia/Broken_Hill
                                                                                  'A','u','s','t','r','a','l','i','a','/','D','a','r','w','i','n','\0',  54, // Australia/Darwin
                                                                                  'A','u','s','t','r','a','l','i','a','/','H','o','b','a','r','t','\0',  55, // Australia/Hobart
                                                                      'A','u','s','t','r','a','l','i','a','/','L','o','r','d','_','H','o','w','e','\0',  56, // Australia/Lord_Howe
                                                                      'A','u','s','t','r','a','l','i','a','/','M','e','l','b','o','u','r','n','e','\0',  57, // Australia/Melbourne
                                                                                      'A','u','s','t','r','a','l','i','a','/','P','e','r','t','h','\0',  58, // Australia/Perth
                                                                                  'A','u','s','t','r','a','l','i','a','/','S','y','d','n','e','y','\0',  59, // Australia/Sydney
                                                                                      'E','u','r','o','p','e','/','B','e','l','g','r','a','d','e','\0',  60, // Europe/Belgrade
                                                                                              'E','u','r','o','p','e','/','B','e','r','l','i','n','\0',  60, // Europe/Berlin
                                                                                      'E','u','r','o','p','e','/','B','r','u','s','s','e','l','s','\0',  60, // Europe/Brussels
                                                                                      'E','u','r','o','p','e','/','C','h','i','s','i','n','a','u','\0',  61, // Europe/Chisinau
                                                                                              'E','u','r','o','p','e','/','D','u','b','l','i','n','\0',  62, // Europe/Dublin
                                                                                      'E','u','r','o','p','e','/','H','e','l','s','i','n','k','i','\0',  63, // Europe/Helsinki
                                                                                      'E','u','r','o','p','e','/','I','s','t','a','n','b','u','l','\0',  44, // Europe/Istanbul
                                                                                                      'E','u','r','o','p','e','/','K','y','i','v','\0',  63, // Europe/Kyiv
                                                                                              'E','u','r','o','p','e','/','L','i','s','b','o','n','\0',  51, // Europe/Lisbon
                                                                                              'E','u','r','o','p','e','/','L','o','n','d','o','n','\0',  64, // Europe/London
                                                                                              'E','u','r','o','p','e','/','M','o','s','c','o','w','\0',  65, // Europe/Moscow
                                                                                                  'E','u','r','o','p','e','/','P','a','r','i','s','\0',  60, // Europe/Paris
                                                                                              'E','u','r','o','p','e','/','P','r','a','g','u','e','\0',  60, // Europe/Prague
                                                                                                      'E','u','r','o','p','e','/','R','o','m','e','\0',  60, // Europe/Rome
                                                                                              'E','u','r','o','p','e','/','W','a','r','s','a','w','\0',  60, // Europe/Warsaw
                                                                                              'E','u','r','o','p','e','/','Z','u','r','i','c','h','\0',  60, // Europe/Zurich
                                                                                      'I','n','d','i','a','n','/','M','a','l','d','i','v','e','s','\0',  32, // Indian/Maldives
                                                                                  'P','a','c','i','f','i','c','/','A','u','c','k','l','a','n','d','\0',  66, // Pacific/Auckland
                                                                                      'P','a','c','i','f','i','c','/','C','h','a','t','h','a','m','\0',  67, // Pacific/Chatham
                                                                                          'P','a','c','i','f','i','c','/','E','a','s','t','e','r','\0',  68, // Pacific/Easter
                                                                      'P','a','c','i','f','i','c','/','G','u','a','d','a','l','c','a','n','a','l','\0',  69, // Pacific/Guadalcanal
                                                                                                  'P','a','c','i','f','i','c','/','G','u','a','m','\0',  70, // Pacific/Guam
                                                                                  'P','a','c','i','f','i','c','/','H','o','n','o','l','u','l','u','\0',  71, // Pacific/Honolulu
                                                                                          'P','a','c','i','f','i','c','/','K','a','n','t','o','n','\0',  72, // Pacific/Kanton
                                                                              'P','a','c','i','f','i','c','/','K','w','a','j','a','l','e','i','n','\0',  73, // Pacific/Kwajalein
                                                                              'P','a','c','i','f','i','c','/','P','a','g','o','_','P','a','g','o','\0',  74, // Pacific/Pago_Pago
                                                                  'P','a','c','i','f','i','c','/','P','o','r','t','_','M','o','r','e','s','b','y','\0',  75, // Pacific/Port_Moresby
                                                                                          'P','a','c','i','f','i','c','/','T','a','r','a','w','a','\0',  73, // Pacific/Tarawa
};
const urule_packed_t* zone_rules = (urule_packed_t*)  _zone_rules;
const char* zone_abrevs = (char*) _zone_abrevs;
const uzone_packed_t* zone_defns = (uzone_packed_t*) _zone_defns;
const char* zone_names = (char*) _zone_names;
