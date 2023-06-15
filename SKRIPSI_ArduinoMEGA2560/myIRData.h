//============ FAN IR RAW CODE =================
#define RAW_DATA_LEN_FAN 71

uint16_t rawDataON[71] = { 9136, 4454, 602, 558, 632, 530, 630, 532, 596, 564, 596, 1640, 598, 1640, 598, 562, 628, 534, 596, 1644, 604, 1632, 604, 1634, 604, 1634, 602, 556, 604, 556, 604, 1634, 602, 1636, 602, 1638, 600, 1638, 600, 1638, 598, 562, 598, 1642, 596, 564, 596, 564, 596, 1644, 604, 556, 604, 558, 602, 558, 602, 1636, 602, 558, 602, 1636, 600, 1638, 600, 560, 600, 39412, 9082, 2212, 596 };     // NEC CF3E916
uint16_t rawDataSWING[71] = { 9172, 4556, 600, 576, 604, 572, 608, 568, 602, 566, 602, 1646, 602, 1646, 600, 558, 602, 560, 600, 1638, 598, 1640, 606, 1632, 606, 1632, 604, 558, 602, 560, 600, 1636, 600, 1640, 598, 564, 596, 564, 606, 1632, 604, 1636, 602, 1638, 598, 562, 598, 562, 596, 1644, 602, 1642, 606, 1638, 598, 566, 604, 560, 598, 566, 604, 1642, 604, 1644, 602, 560, 600, 39552, 9090, 2216, 602 };  // NEC CF339C6
uint16_t rawDataspeed[71] = { 9080, 4476, 600, 558, 602, 558, 602, 558, 602, 560, 600, 1634, 602, 1636, 602, 556, 602, 556, 604, 1634, 604, 1634, 602, 1634, 604, 1634, 604, 556, 604, 554, 606, 1632, 604, 1632, 606, 1632, 604, 1632, 604, 1632, 604, 554, 606, 554, 604, 554, 596, 564, 596, 1642, 596, 564, 596, 564, 596, 562, 598, 1640, 596, 1640, 598, 1640, 596, 1640, 596, 562, 596, 39394, 9078, 2218, 598 };  // NEC CF3E11E

//============ AC IR RAW CODE =================
#define RAW_DATA_LEN_AC 137

//LUPA TAMBAHIN KALO SUHU KEDINGINAN, SUHU AC NAIK, MATIIN SWING MODE

//------------------------------------------------------------------------- basic - balapan room
//------------------------------------------------------------------------- FAN SPEED INCREASE

uint16_t rawon_16Fhigh_swon[137] = {9782, 9780,  9778, 9776,  4620, 2466,  382, 346,  390, 910,  386, 912,  382, 348,  388, 912,  382, 348,  388, 342,  382, 346,  390, 338,  388, 912,  384, 348,  388, 340,  384, 346,  390, 910,  386, 344,  382, 348,  388, 338,  386, 912,  382, 916,  388, 340,  384, 914,  382, 348,  386, 342,  382, 346,  388, 338,  388, 342,  382, 348,  388, 340,  384, 346,  390, 910,  386, 344,  392, 338,  386, 910,  386, 344,  392, 338,  386, 342,  382, 348,  388, 912,  384, 914,  390, 338,  386, 910,  384, 914,  390, 908,  386, 342,  382, 916,  390, 340,  384, 914,  390, 338,  386, 340,  386, 912,  382, 916,  388, 340,  384, 914,  390, 340,  384, 344,  382, 348,  388, 908,  388, 342,  382, 918,  386, 910,  384, 914,  390, 908,  386, 344,  382, 918,  388, 20234,  4608};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 16C, Fan: 2 (High), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:16, On Timer: Off, Off Timer: Off

uint16_t rawon_16Fmed_swon[137] = {9778, 9772,  9776, 9790,  4626, 2470,  390, 366,  358, 918,  440, 864,  390, 368,  358, 916,  388, 372,  364, 366,  358, 374,  360, 366,  358, 916,  388, 370,  364, 366,  358, 372,  362, 370,  356, 918,  388, 372,  364, 364,  362, 916,  388, 910,  386, 372,  362, 912,  392, 366,  358, 372,  362, 368,  356, 370,  364, 366,  358, 372,  362, 368,  356, 374,  360, 914,  390, 366,  358, 372,  362, 910,  386, 374,  362, 370,  354, 376,  360, 372,  364, 912,  382, 918,  386, 372,  362, 908,  386, 916,  390, 910,  384, 372,  364, 908,  386, 370,  364, 906,  388, 368,  358, 370,  366, 906,  388, 912,  384, 372,  362, 910,  384, 374,  362, 368,  358, 372,  364, 906,  388, 370,  366, 908,  386, 912,  384, 916,  388, 370,  356, 916,  388, 912,  382, 20252,  4622};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 16C, Fan: 4 (Medium), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:16, On Timer: Off, Off Timer: Off

uint16_t rawon_16Flow_swon[137] = {9782, 9774,  9782, 9778,  4618, 2472,  388, 342,  382, 916,  388, 912,  382, 348,  388, 912,  382, 348,  388, 342,  382, 346,  388, 338,  386, 912,  382, 348,  388, 346,  378, 348,  388, 344,  380, 348,  386, 914,  380, 346,  390, 910,  384, 916,  390, 340,  384, 914,  390, 340,  384, 344,  390, 340,  386, 340,  436, 294,  390, 340,  384, 344,  390, 340,  386, 912,  382, 346,  388, 342,  384, 912,  382, 348,  386, 342,  382, 346,  388, 340,  384, 916,  388, 908,  386, 346,  378, 914,  392, 908,  386, 914,  380, 348,  386, 912,  384, 346,  388, 908,  386, 344,  380, 346,  390, 910,  386, 914,  380, 348,  386, 912,  382, 348,  388, 342,  382, 346,  388, 908,  388, 344,  390, 910,  384, 914,  392, 908,  386, 344,  390, 340,  386, 344,  390, 20260,  4614};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 16C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:16, On Timer: Off, Off Timer: Off


//----------------------------------------------------------------------------- SUHU NAIKIN 

uint16_t rawon_17Flow_swon[137] = {9794, 9794,  9804, 9802,  4624, 2480,  390, 340,  384, 918,  388, 916,  390, 342,  384, 918,  386, 346,  388, 342,  384, 346,  388, 340,  384, 918,  386, 346,  390, 342,  384, 348,  386, 344,  390, 340,  384, 918,  388, 340,  384, 918,  386, 916,  388, 342,  382, 920,  386, 346,  388, 342,  382, 348,  386, 342,  382, 348,  386, 346,  390, 340,  384, 348,  388, 914,  382, 348,  386, 344,  390, 908,  386, 344,  390, 340,  384, 346,  390, 342,  382, 918,  386, 914,  390, 340,  384, 914,  382, 920,  384, 918,  388, 344,  390, 912,  384, 348,  386, 914,  390, 340,  384, 914,  390, 912,  382, 920,  384, 346,  388, 914,  382, 350,  384, 346,  390, 342,  382, 916,  388, 342,  382, 920,  384, 918,  388, 344,  392, 912,  382, 348,  386, 344,  390, 20286,  4618};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 17C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:16, On Timer: Off, Off Timer: Off - 2D17576120168216

uint16_t rawon_18Flow_swon[137] = {9808, 9794,  9794, 9798,  4618, 2482,  388, 342,  392, 910,  384, 920,  384, 348,  388, 914,  390, 342,  382, 348,  386, 346,  390, 338,  386, 918,  388, 344,  390, 340,  384, 348,  388, 344,  390, 340,  384, 920,  386, 344,  396, 908,  384, 920,  386, 344,  390, 914,  392, 340,  384, 348,  388, 342,  382, 346,  388, 344,  382, 350,  386, 346,  390, 342,  382, 920,  386, 346,  390, 342,  384, 916,  388, 344,  392, 340,  384, 346,  390, 342,  382, 922,  384, 918,  386, 344,  390, 908,  386, 918,  388, 916,  390, 340,  384, 920,  386, 346,  388, 914,  392, 338,  386, 342,  382, 350,  386, 344,  390, 912,  382, 918,  386, 346,  390, 340,  384, 346,  388, 912,  382, 350,  386, 918,  388, 914,  390, 912,  382, 920,  386, 344,  390, 342,  382, 20294,  4622};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 18C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:16, On Timer: Off, Off Timer: Off - 3D18576120168216

uint16_t rawon_19Flow_swon[137] = {9794, 9776,  9782, 9768,  4618, 2466,  392, 364,  362, 910,  384, 914,  390, 366,  360, 912,  392, 366,  360, 370,  356, 374,  360, 366,  360, 910,  384, 374,  362, 366,  358, 372,  364, 366,  358, 372,  364, 908,  388, 908,  386, 912,  384, 916,  390, 368,  356, 914,  392, 366,  358, 370,  366, 364,  360, 366,  360, 370,  364, 366,  358, 370,  364, 364,  360, 910,  384, 374,  362, 368,  356, 912,  384, 374,  362, 370,  356, 374,  360, 368,  356, 916,  390, 908,  386, 370,  364, 904,  392, 908,  388, 912,  382, 374,  362, 910,  384, 374,  362, 908,  386, 370,  354, 914,  390, 366,  358, 372,  364, 906,  388, 910,  384, 374,  362, 368,  356, 372,  362, 904,  390, 366,  358, 914,  390, 908,  388, 912,  384, 374,  360, 910,  386, 372,  362, 20234,  4620};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 19C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:17, On Timer: Off, Off Timer: Off - 5D19576120178216

uint16_t rawon_20Flow_swon[137] = {9782, 9764,  9784, 9766,  4620, 2468,  392, 364,  360, 912,  392, 906,  388, 368,  356, 916,  390, 368,  356, 372,  362, 368,  358, 370,  366, 906,  388, 370,  354, 374,  362, 368,  356, 374,  360, 368,  356, 916,  390, 906,  390, 910,  386, 912,  382, 374,  360, 910,  384, 374,  362, 368,  356, 372,  362, 364,  360, 370,  366, 364,  360, 370,  356, 374,  360, 912,  384, 372,  362, 368,  358, 910,  384, 374,  362, 368,  356, 372,  362, 368,  358, 914,  390, 908,  386, 372,  364, 904,  390, 908,  386, 912,  382, 374,  360, 910,  384, 374,  362, 908,  388, 368,  356, 370,  364, 364,  360, 370,  354, 374,  362, 368,  356, 914,  390, 366,  360, 370,  354, 912,  392, 366,  360, 910,  384, 914,  392, 908,  388, 370,  354, 916,  390, 910,  384, 20230,  4612};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 20C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:17, On Timer: Off, Off Timer: Off - DD20576120178216

uint16_t rawon_21Flow_swon[137] = {9802, 9790,  9800, 9796,  4620, 2480,  390, 340,  384, 944,  362, 942,  364, 340,  384, 918,  388, 346,  388, 342,  382, 350,  386, 344,  382, 918,  386, 346,  388, 342,  382, 350,  384, 348,  388, 344,  392, 908,  386, 940,  366, 936,  358, 946,  360, 346,  390, 910,  384, 350,  386, 346,  388, 342,  382, 346,  388, 346,  390, 342,  384, 348,  388, 344,  380, 922,  384, 348,  388, 342,  382, 916,  388, 344,  390, 342,  382, 348,  388, 344,  390, 910,  384, 942,  364, 342,  382, 942,  362, 940,  366, 938,  358, 348,  386, 942,  364, 344,  380, 946,  360, 346,  390, 936,  358, 348,  386, 346,  390, 342,  384, 348,  386, 942,  364, 342,  382, 350,  384, 938,  356, 350,  384, 944,  362, 914,  392, 342,  392, 934,  360, 916,  390, 914,  390, 20288,  4628};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 21C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:17, On Timer: Off, Off Timer: Off - ED21576120178216

uint16_t rawon_22Flow_swon[137] = {9798, 9804,  9804, 9798,  4628, 2474,  384, 346,  388, 914,  392, 912,  382, 348,  388, 916,  390, 344,  380, 350,  384, 372,  366, 336,  386, 916,  388, 344,  382, 348,  386, 346,  390, 344,  390, 340,  384, 918,  386, 912,  382, 922,  384, 918,  386, 344,  390, 912,  384, 348,  386, 344,  392, 340,  384, 344,  390, 342,  384, 374,  360, 344,  392, 340,  384, 918,  388, 344,  390, 366,  358, 914,  390, 368,  358, 348,  388, 344,  392, 340,  384, 920,  386, 916,  390, 368,  358, 916,  388, 914,  392, 912,  384, 374,  360, 916,  388, 344,  382, 920,  386, 346,  390, 338,  386, 916,  390, 368,  356, 376,  360, 346,  390, 914,  390, 340,  384, 374,  362, 912,  382, 376,  360, 918,  386, 916,  390, 914,  390, 914,  382, 920,  384, 920,  386, 20312,  4624};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 22C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:17, On Timer: Off, Off Timer: Off - FD22576120178216

uint16_t rawon_23Flow_swon[137] = {9806, 9788,  9798, 9800,  4626, 2474,  386, 374,  362, 914,  392, 912,  392, 366,  358, 916,  388, 372,  364, 340,  384, 374,  360, 368,  356, 918,  386, 374,  360, 344,  392, 342,  382, 348,  386, 370,  364, 910,  386, 914,  390, 912,  394, 910,  386, 372,  362, 914,  392, 368,  358, 346,  388, 370,  356, 346,  388, 344,  392, 340,  384, 372,  362, 370,  366, 908,  386, 372,  364, 368,  358, 914,  390, 368,  356, 374,  360, 344,  392, 340,  384, 918,  388, 914,  392, 368,  356, 914,  390, 912,  384, 918,  386, 372,  362, 912,  392, 368,  358, 916,  390, 370,  354, 918,  388, 914,  390, 370,  356, 376,  360, 372,  362, 910,  384, 372,  362, 370,  354, 916,  390, 370,  366, 910,  386, 916,  388, 372,  364, 368,  356, 348,  388, 344,  390, 20284,  4620};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 23C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:17, On Timer: Off, Off Timer: Off - D23576120178216

uint16_t rawoff_24Flow_swon[137] = {9772, 9774,  9772, 9772,  4612, 2468,  382, 346,  388, 912,  382, 916,  388, 340,  384, 914,  392, 338,  386, 344,  382, 346,  388, 338,  386, 912,  384, 346,  390, 340,  384, 344,  390, 340,  386, 344,  390, 908,  388, 908,  388, 342,  382, 916,  388, 340,  386, 912,  382, 918,  388, 340,  384, 344,  380, 346,  388, 342,  384, 346,  390, 338,  386, 344,  390, 908,  388, 342,  384, 350,  386, 906,  388, 342,  384, 346,  388, 340,  384, 346,  390, 910,  386, 912,  382, 348,  388, 906,  388, 912,  384, 916,  410, 320,  384, 914,  390, 340,  386, 912,  382, 346,  388, 338,  386, 344,  382, 918,  388, 342,  382, 348,  386, 912,  384, 346,  390, 340,  384, 910,  384, 344,  390, 908,  386, 342,  382, 916,  388, 342,  382, 346,  390, 910,  384, 20234,  4610};  
// DAIKIN64 Power Toggle: Off, Mode: 2 (Cool), Temp: 24C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:35, On Timer: Off, Off Timer: Off - 9524576120358216

uint16_t rawon_24Flow_swon[137] = {9780, 9780,  9776, 9778,  4618, 2468,  382, 346,  390, 910,  386, 916,  390, 340,  384, 914,  390, 340,  384, 346,  390, 340,  386, 342,  382, 918,  388, 342,  382, 346,  388, 342,  382, 348,  388, 342,  382, 918,  386, 910,  384, 346,  388, 912,  382, 348,  388, 912,  382, 918,  388, 342,  382, 348,  388, 340,  386, 346,  390, 340,  384, 346,  390, 340,  384, 916,  390, 340,  386, 344,  390, 908,  388, 342,  384, 346,  388, 342,  382, 348,  388, 912,  382, 916,  390, 340,  384, 914,  392, 908,  386, 914,  390, 338,  386, 914,  390, 340,  384, 914,  390, 338,  386, 342,  384, 346,  388, 912,  382, 346,  388, 342,  382, 918,  388, 342,  384, 346,  388, 910,  384, 346,  390, 912,  384, 916,  388, 912,  382, 350,  386, 344,  390, 338,  386, 20262,  4622};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 24C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:35, On Timer: Off, Off Timer: Off - 1D24576120358216

uint16_t rawon_25Flow_swon[137] = {9800, 9784,  9794, 9794,  4622, 2474,  384, 372,  364, 910,  384, 918,  386, 372,  364, 910,  384, 374,  360, 344,  392, 366,  358, 370,  364, 908,  386, 374,  362, 342,  392, 366,  358, 374,  360, 344,  392, 910,  386, 370,  364, 368,  356, 918,  388, 370,  364, 910,  386, 916,  388, 370,  366, 338,  386, 370,  356, 348,  386, 346,  390, 366,  358, 346,  388, 912,  382, 374,  360, 344,  390, 906,  388, 370,  364, 342,  384, 346,  388, 342,  392, 908,  386, 916,  390, 368,  356, 916,  390, 912,  394, 910,  386, 372,  362, 912,  392, 366,  358, 916,  390, 368,  356, 914,  390, 368,  356, 918,  388, 370,  366, 338,  386, 914,  390, 368,  356, 348,  388, 910,  386, 374,  360, 914,  392, 910,  384, 918,  388, 372,  364, 366,  358, 346,  388, 20282,  4622};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 25C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:34, On Timer: Off, Off Timer: Off - 1D25576120348216

uint16_t rawon_26Flow_swon[137] = {9780, 9768,  9778, 9772,  4612, 2474,  386, 370,  366, 908,  386, 914,  390, 340,  386, 914,  392, 366,  358, 370,  364, 366,  360, 342,  384, 918,  386, 344,  382, 348,  388, 368,  356, 348,  388, 342,  382, 916,  388, 340,  386, 370,  364, 366,  358, 914,  390, 910,  386, 370,  364, 340,  386, 344,  390, 336,  388, 342,  382, 348,  386, 342,  382, 348,  388, 910,  384, 344,  390, 338,  386, 912,  384, 346,  388, 342,  382, 346,  388, 340,  384, 916,  388, 910,  384, 344,  380, 916,  390, 910,  384, 916,  388, 366,  358, 914,  390, 366,  358, 914,  390, 338,  386, 366,  358, 916,  388, 912,  384, 346,  390, 366,  358, 916,  388, 340,  386, 344,  390, 906,  388, 342,  382, 918,  388, 912,  384, 348,  388, 344,  380, 918,  386, 344,  382, 20250,  4612};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 26C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:18, On Timer: Off, Off Timer: Off - 4D26576120188216

uint16_t rawon_27Flow_swon[137] = {9768, 9764,  9770, 9768,  4608, 2472,  386, 366,  358, 912,  382, 918,  388, 340,  384, 914,  392, 338,  386, 342,  382, 372,  362, 338,  388, 912,  382, 348,  388, 340,  384, 344,  390, 366,  358, 344,  392, 908,  388, 340,  384, 344,  390, 340,  386, 912,  382, 916,  390, 340,  384, 344,  390, 338,  386, 340,  384, 346,  388, 340,  384, 344,  390, 340,  386, 914,  390, 336,  388, 342,  384, 912,  382, 348,  388, 368,  356, 346,  390, 340,  384, 914,  380, 916,  388, 340,  386, 910,  384, 914,  390, 908,  388, 340,  384, 914,  390, 366,  360, 910,  384, 344,  380, 914,  390, 908,  386, 912,  382, 346,  388, 342,  384, 916,  390, 338,  386, 342,  382, 912,  382, 348,  386, 912,  384, 914,  390, 908,  386, 344,  380, 918,  388, 342,  382, 20224,  4618};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 27C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:18, On Timer: Off, Off Timer: Off - 5D27576120188216


//----------------------------------------------------------------------------- ON OFF AT 16 DEGREE

uint16_t OFF16_Alter[137] = {9772, 9760,  9774, 9760,  4604, 2474,  384, 342,  382, 916,  390, 908,  386, 342,  382, 916,  388, 342,  384, 344,  390, 338,  386, 340,  384, 914,  390, 340,  384, 344,  382, 348,  388, 342,  382, 346,  388, 910,  386, 342,  382, 346,  388, 340,  384, 914,  392, 908,  388, 342,  434, 294,  440, 288,  384, 342,  382, 346,  388, 340,  384, 344,  390, 340,  390, 910,  380, 348,  386, 342,  382, 912,  382, 348,  388, 342,  382, 346,  390, 340,  384, 914,  380, 918,  388, 342,  382, 914,  382, 918,  388, 910,  384, 344,  390, 908,  386, 344,  382, 916,  388, 340,  384, 344,  382, 916,  388, 910,  384, 346,  390, 908,  386, 344,  380, 348,  388, 342,  382, 914,  382, 348,  386, 912,  382, 348,  388, 912,  384, 914,  390, 338,  386, 914,  382, 20238,  4614};  
// DAIKIN64 Power Toggle: Off, Mode: 2 (Cool), Temp: 16C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:18, On Timer: Off, Off Timer: Off - B516576120188216

uint16_t ON16_Alt[137] = {9776, 9764,  9782, 9766,  4608, 2474,  386, 342,  382, 918,  388, 912,  384, 346,  388, 910,  386, 344,  390, 338,  386, 342,  382, 344,  390, 910,  384, 346,  410, 318,  386, 344,  390, 340,  416, 312,  382, 918,  418, 878,  386, 344,  390, 340,  416, 882,  382, 920,  386, 344,  412, 318,  386, 342,  412, 314,  390, 342,  382, 348,  420, 310,  384, 346,  390, 910,  414, 314,  390, 340,  416, 878,  416, 316,  390, 340,  414, 316,  388, 342,  382, 918,  418, 880,  414, 314,  410, 886,  418, 882,  412, 888,  416, 312,  412, 888,  418, 312,  412, 888,  418, 312,  412, 316,  388, 912,  414, 886,  418, 310,  414, 884,  388, 344,  416, 314,  418, 310,  414, 882,  412, 318,  418, 882,  412, 886,  388, 344,  390, 340,  416, 882,  392, 338,  386, 20244,  4616};  
// DAIKIN64 Power Toggle: On, Mode: 2 (Cool), Temp: 16C, Fan: 8 (Low), Turbo: Off, Quiet: Off, Swing(V): On, Sleep: Off, Clock: 20:19, On Timer: Off, Off Timer: Off - 4D16576120198216