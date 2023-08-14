#ifndef GBMATH_H
#define GBMATH_H
//gbmath version 2.1

#include <stdint.h>
#include <stdlib.h>
//how many numbers in the lookup tables for the fast sin/cos/tan.
#define TABLE_SIZE 256

// Lookup tables for the fast sin and cos values
const int8_t sinTable[TABLE_SIZE] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 59, 62, 65, 67, 70, 73, 75, 78, 80, 82, 85, 87, 89, 91, 94, 96, 98, 100, 102, 103, 105, 107, 108, 110, 112, 113, 114, 116, 117, 118, 119, 120, 121, 122, 123, 123, 124, 125, 125, 126, 126, 126, 126, 126, 127, 126, 126, 126, 126, 126, 125, 125, 124, 123, 123, 122, 121, 120, 119, 118, 117, 116, 114, 113, 112, 110, 108, 107, 105, 103, 102, 100, 98, 96, 94, 91, 89, 87, 85, 82, 80, 78, 75, 73, 70, 67, 65, 62, 59, 57, 54, 51, 48, 45, 42, 39, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 0, -3, -6, -9, -12, -15, -18, -21, -24, -27, -30, -33, -36, -39, -42, -45, -48, -51, -54, -57, -59, -62, -65, -67, -70, -73, -75, -78, -80, -82, -85, -87, -89, -91, -94, -96, -98, -100, -102, -103, -105, -107, -108, -110, -112, -113, -114, -116, -117, -118, -119, -120, -121, -122, -123, -123, -124, -125, -125, -126, -126, -126, -126, -126, -127, -126, -126, -126, -126, -126, -125, -125, -124, -123, -123, -122, -121, -120, -119, -118, -117, -116, -114, -113, -112, -110, -108, -107, -105, -103, -102, -100, -98, -96, -94, -91, -89, -87, -85, -82, -80, -78, -75, -73, -70, -67, -65, -62, -59, -57, -54, -51, -48, -45, -42, -39, -36, -33, -30, -27, -24, -21, -18, -15, -12, -9, -6, -3, };
const int8_t cosTable[TABLE_SIZE] = {127, 126, 126, 126, 126, 126, 125, 125, 124, 123, 123, 122, 121, 120, 119, 118, 117, 116, 114, 113, 112, 110, 108, 107, 105, 103, 102, 100, 98, 96, 94, 91, 89, 87, 85, 82, 80, 78, 75, 73, 70, 67, 65, 62, 59, 57, 54, 51, 48, 45, 42, 39, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 0, -3, -6, -9, -12, -15, -18, -21, -24, -27, -30, -33, -36, -39, -42, -45, -48, -51, -54, -57, -59, -62, -65, -67, -70, -73, -75, -78, -80, -82, -85, -87, -89, -91, -94, -96, -98, -100, -102, -103, -105, -107, -108, -110, -112, -113, -114, -116, -117, -118, -119, -120, -121, -122, -123, -123, -124, -125, -125, -126, -126, -126, -126, -126, -127, -126, -126, -126, -126, -126, -125, -125, -124, -123, -123, -122, -121, -120, -119, -118, -117, -116, -114, -113, -112, -110, -108, -107, -105, -103, -102, -100, -98, -96, -94, -91, -89, -87, -85, -82, -80, -78, -75, -73, -70, -67, -65, -62, -59, -57, -54, -51, -48, -45, -42, -39, -36, -33, -30, -27, -24, -21, -18, -15, -12, -9, -6, -3, 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 59, 62, 65, 67, 70, 73, 75, 78, 80, 82, 85, 87, 89, 91, 94, 96, 98, 100, 102, 103, 105, 107, 108, 110, 112, 113, 114, 116, 117, 118, 119, 120, 121, 122, 123, 123, 124, 125, 125, 126, 126, 126, 126, 126, };

// Fast approximation of sine function using lookup table
static inline int8_t fast_sin(uint8_t angle) {
    return sinTable[angle];
}

// Fast approximation of cosine function using lookup table
static inline int8_t fast_cos(uint8_t angle) {
    return cosTable[angle];
}

// Fast approximation of tangent function using lookup tables
static inline int8_t fast_tan(uint8_t angle) {
    // Calculate tangent as sin(angle) / cos(angle)
    return (fast_sin(angle) << 8) / fast_cos(angle);
}

// Define the fractional bits for the GBfloat variable type
#define GB_FLOAT_FRACTIONAL_BITS 8
typedef int16_t GBfloat;
typedef uint16_t uGBfloat;
//how many numbers in the lookup tables for GBfloats.
#define GBFLOAT_TABLE_SIZE 256
//signed PI (GBfloat)
#define GBFLOAT_PI floatToGBfloat(3, 14)
//unsigned PI (uGBfloat)
#define UGBFLOAT_PI floatToUGBfloat(3, 14)

// Lookup tables for sin and cos values
const GBfloat GBfloatSinTable[GBFLOAT_TABLE_SIZE] = { 0,2,3,5,6,8,9,11,12,14,16,17,19,20,22,23,25,26,28,29,31,32,34,36,37,39,40,41,43,44,46,47,49,50,52,53,54,56,57,59,60,61,63,64,66,67,68,69,71,72,73,75,76,77,78,80,81,82,83,84,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,108,109,110,111,112,112,113,114,114,115,116,116,117,118,118,119,119,120,120,121,121,122,122,123,123,123,124,124,124,125,125,125,125,126,126,126,126,126,127,127,127,127,127,127,127,127,127,127,127,127,127,127,126,126,126,126,126,125,125,125,125,124,124,124,123,123,123,122,122,121,121,120,120,119,119,118,118,117,116,116,115,114,114,113,112,112,111,110,109,108,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,84,83,82,81,80,78,77,76,75,73,72,71,69,68,67,66,64,63,61,60,59,57,56,54,53,52,50,49,47,46,44,43,41,40,39,37,36,34,32,31,29,28,26,25,23,22,20,19,17,16,14,12,11,9,8,6,5,3,2,0,};
const GBfloat GBfloatCosTable[GBFLOAT_TABLE_SIZE] = { 127,127,127,127,127,127,127,127,126,126,126,126,126,125,125,125,125,124,124,124,123,123,122,122,121,121,121,120,120,119,118,118,117,117,116,115,115,114,113,113,112,111,110,110,109,108,107,106,105,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,88,87,86,85,84,83,81,80,79,78,77,75,74,73,71,70,69,68,66,65,63,62,61,59,58,57,55,54,52,51,50,48,47,45,44,42,41,39,38,36,35,33,32,30,29,27,26,24,23,21,19,18,16,15,13,12,10,9,7,5,4,2,1,-1,-2,-4,-5,-7,-9,-10,-12,-13,-15,-16,-18,-19,-21,-23,-24,-26,-27,-29,-30,-32,-33,-35,-36,-38,-39,-41,-42,-44,-45,-47,-48,-50,-51,-52,-54,-55,-57,-58,-59,-61,-62,-64,-65,-66,-68,-69,-70,-71,-73,-74,-75,-77,-78,-79,-80,-81,-83,-84,-85,-86,-87,-88,-90,-91,-92,-93,-94,-95,-96,-97,-98,-99,-100,-101,-102,-103,-104,-105,-105,-106,-107,-108,-109,-110,-110,-111,-112,-113,-113,-114,-115,-115,-116,-117,-117,-118,-118,-119,-120,-120,-121,-121,-121,-122,-122,-123,-123,-124,-124,-124,-125,-125,-125,-125,-126,-126,-126,-126,-126,-127,-127,-127,-127,-127,-127,-127,-127};
const uGBfloat uGBfloatSinTable[GBFLOAT_TABLE_SIZE] = { 0,401,801,1201,1602,2001,2401,2800,3199,3598,3995,4393,4789,5185,5580,5974,6367,6760,7151,7541,7930,8318,8705,9090,9474,9856,10237,10616,10994,11370,11745,12117,12488,12857,13224,13589,13952,14312,14671,15027,15381,15733,16082,16429,16774,17115,17455,17791,18125,18456,18785,19110,19433,19752,20069,20383,20693,21000,21305,21606,21903,22198,22489,22776,23060,23341,23618,23891,24161,24427,24690,24948,25203,25455,25702,25945,26185,26420,26651,26879,27102,27321,27536,27747,27954,28156,28354,28548,28738,28923,29104,29280,29452,29619,29782,29940,30094,30244,30388,30528,30664,30795,30921,31042,31159,31271,31378,31481,31578,31671,31759,31843,31921,31995,32063,32127,32186,32240,32290,32334,32373,32408,32437,32462,32482,32497,32506,32511,32511,32506,32497,32482,32462,32437,32408,32373,32334,32290,32240,32186,32127,32063,31995,31921,31843,31759,31671,31578,31481,31378,31271,31159,31042,30921,30795,30664,30528,30388,30244,30094,29940,29782,29619,29452,29280,29104,28923,28738,28548,28354,28156,27954,27747,27536,27321,27102,26879,26651,26420,26185,25945,25702,25455,25203,24948,24690,24427,24161,23891,23618,23341,23060,22776,22489,22198,21903,21606,21305,21000,20693,20383,20069,19752,19433,19110,18785,18456,18125,17791,17455,17115,16774,16429,16082,15733,15381,15027,14671,14312,13952,13589,13224,12857,12488,12117,11745,11370,10994,10616,10237,9856,9474,9090,8705,8318,7930,7541,7151,6760,6367,5974,5580,5185,4789,4393,3995,3598,3199,2800,2401,2001,1602,1201,801,401,0};
const uGBfloat uGBfloatCosTable[GBFLOAT_TABLE_SIZE] = { 32512,32510,32502,32490,32473,32450,32423,32391,32354,32312,32266,32214,32157,32096,32030,31958,31882,31802,31716,31625,31530,31430,31325,31215,31101,30982,30858,30730,30597,30459,30317,30170,30018,29862,29701,29536,29366,29192,29014,28831,28643,28452,28256,28056,27851,27642,27429,27212,26991,26766,26536,26303,26065,25824,25579,25329,25076,24820,24559,24295,24027,23755,23480,23201,22919,22633,22343,22051,21755,21455,21153,20847,20538,20226,19911,19593,19272,18948,18621,18291,17958,17623,17285,16945,16602,16256,15908,15557,15204,14849,14492,14132,13770,13407,13041,12673,12303,11931,11558,11182,10806,10427,10047,9665,9282,8897,8511,8124,7736,7346,6955,6564,6171,5777,5382,4987,4591,4194,3797,3398,3000,2601,2201,1802,1401,1001,601,200,65336,64935,64535,64135,63734,63335,62935,62536,62138,61739,61342,60945,60549,60154,59759,59365,58972,58581,58190,57800,57412,57025,56639,56254,55871,55489,55109,54730,54354,53978,53605,53233,52863,52495,52129,51766,51404,51044,50687,50332,49979,49628,49280,48934,48591,48251,47913,47578,47245,46915,46588,46264,45943,45625,45310,44998,44689,44383,44081,43781,43485,43193,42903,42617,42335,42056,41781,41509,41241,40977,40716,40460,40207,39957,39712,39471,39233,39000,38770,38545,38324,38107,37894,37685,37480,37280,37084,36893,36705,36522,36344,36170,36000,35835,35674,35518,35366,35219,35077,34939,34806,34678,34554,34435,34321,34211,34106,34006,33911,33820,33734,33654,33578,33506,33440,33379,33322,33270,33224,33182,33145,33113,33086,33063,33046,33034,33026,33024};
// Basic arithmetic operations for the GBfloat variable type
static inline GBfloat GBfloatAdd(GBfloat a, GBfloat b) {
    int32_t result = a + b;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    if (fractionalPart >= 100 ) {
        integerPart += fractionalPart / 100;
        fractionalPart %= 100;
    }

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}
// Subtract 2 signed GBfloats
static inline GBfloat GBfloatSub(GBfloat a, GBfloat b)
{
    int32_t result = a - b;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}
// Multiply 2 signed GBfloats
static inline GBfloat GBfloatMultiply(GBfloat a, GBfloat b) {
    int32_t result = ((int32_t)a * b + (1 << (GB_FLOAT_FRACTIONAL_BITS - 1))) >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    if (fractionalPart >= 100) {
        integerPart += fractionalPart / 100;
        fractionalPart %= 100;
    }

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}
// Divide 2 signed GBfloats 
static inline GBfloat GBfloatDivide(GBfloat a, GBfloat b) {
    int32_t result = ((int32_t)a << GB_FLOAT_FRACTIONAL_BITS) / b;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    // Round the fractional part
    fractionalPart = (fractionalPart * 100 + b / 2) / b;

    // Check if the fractional part is greater or equal to 100
    if (fractionalPart >= 100) {
        integerPart++;
        fractionalPart -= 100;
    }

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}
// Convert a "floating" number into a signed GBfloat
static inline GBfloat floatToGBfloat(int8_t whole_number, uint8_t decimal) {
    int16_t result;
    if (whole_number < 0) {
        result = -((abs(whole_number) << GB_FLOAT_FRACTIONAL_BITS) + (decimal & 0xFF));
    } else {
        result = (whole_number << GB_FLOAT_FRACTIONAL_BITS) + (decimal & 0xFF);
    }
    return result;
}

// Convert a signed GBfloat into a signed int8_t
static inline int8_t GBfloatToInt8(GBfloat value) {
    return (int8_t)(value >> GB_FLOAT_FRACTIONAL_BITS);
}
// Convert a signed GBfloat into a signed int16_t
static inline int16_t GBfloatToInt16(GBfloat value) {
    return (int16_t)(value >> GB_FLOAT_FRACTIONAL_BITS);
}

// Internal function for calculating lookup table indexes
GBfloat angle_to_index(GBfloat angle) {
    GBfloat angleIndex = GBfloatDivide(GBfloatMultiply(angle, GBfloatSub(floatToGBfloat(GBFLOAT_TABLE_SIZE, 0), floatToGBfloat(1, 0))), GBfloatMultiply(floatToGBfloat(2, 0), GBFLOAT_PI));
    return angleIndex;
}

// Accurate approximation of sine function using signed GBfloats
GBfloat GBfloat_sin(GBfloat angle) {
    GBfloat angleIndex = angle_to_index(angle);
    int16_t index = GBfloatToInt16(angleIndex);
    return GBfloatSinTable[index];
}

// Accurate approximation of cosine function using signed GBfloats
GBfloat GBfloat_cos(GBfloat angle) {
    GBfloat angleIndex = angle_to_index(angle);
    int16_t index = GBfloatToInt16(angleIndex);
    return GBfloatCosTable[index];
}

// Accurate approximation of tangent function using signed GBfloats
GBfloat GBfloat_tan(GBfloat angle) {
    return GBfloatDivide(GBfloat_sin(angle), GBfloat_cos(angle));
}

//convert signed GBfloat degrees to radians
GBfloat GBfloatDegreesToRadians(GBfloat degrees) {
    return GBfloatDivide(GBfloatMultiply(degrees, GBFLOAT_PI), floatToGBfloat(180, 0));
}
//convert signed GBfloat radians to degrees
GBfloat GBfloatRadiansToDegrees(GBfloat radians) {
    GBfloat degrees = GBfloatDivide(GBfloatMultiply(radians, floatToGBfloat(180, 0)), GBFLOAT_PI);  // radians * 180 / pi
    return degrees;
}



// Add 2 unsigned GBfloats (uGBfloat)
static inline uGBfloat uGBfloatAdd(uGBfloat a, uGBfloat b) {
    uint32_t result = a + b;
    uint16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    uint16_t fractionalPart = result & 0xFF;

    if (fractionalPart >= 100) {
        integerPart += fractionalPart / 100;
        fractionalPart %= 100;
    }

    return (uGBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}
// Subtract 2 unsigned GBfloats (uGBfloat)
static inline uGBfloat uGBfloatSub(uGBfloat a, uGBfloat b) {
    uGBfloat result;

    uint16_t diffInteger = (a / 256) - (b / 256);
    uint16_t diffFraction = (a % 256) - (b % 256);

    result = diffInteger * 256 + diffFraction;

    return result;
}
// Multiply 2 unsigned GBfloats (uGBfloat)
static inline uGBfloat uGBfloatMultiply(uGBfloat a, uGBfloat b) {
    uint32_t result = ((uint32_t)a * b + (1 << (GB_FLOAT_FRACTIONAL_BITS - 1))) >> GB_FLOAT_FRACTIONAL_BITS;
    uint16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    uint16_t fractionalPart = result & 0xFF;

    if (fractionalPart >= 100) {
        integerPart += fractionalPart / 100;
        fractionalPart %= 100;
    }

    return (uGBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}
// Divide 2 unsigned GBfloats (uGBfloat)
static inline uGBfloat uGBfloatDivide(uGBfloat a, uGBfloat b) {
    uint32_t result = ((uint32_t)a << GB_FLOAT_FRACTIONAL_BITS) / b;
    uint16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    uint16_t fractionalPart = result & 0xFF;

    // Round the fractional part
    fractionalPart = (fractionalPart * 100 + b / 2) / b;

    // Check if the fractional part is greater or equal to 100
    if (fractionalPart >= 100) {
        integerPart++;
        fractionalPart -= 100;
    }

    return (uGBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}
// Convert a "floating" number into an unsigned GBfloat (uGBfloat)
static inline uGBfloat floatToUGBfloat(int8_t whole_number, uint8_t decimal) {
    return (uGBfloat)((whole_number << GB_FLOAT_FRACTIONAL_BITS) + (decimal & 0xFF));
}

// Convert an unsigned GBfloat (uGBfloat) into an unsigned uint8_t
static inline uint8_t uGBfloatToUint8(uGBfloat value) {
    return (uint8_t)(value >> GB_FLOAT_FRACTIONAL_BITS);
}
// Convert an unsigned GBfloat (uGBfloat) into an unsigned uint16_t
static inline uint16_t uGBfloatToUint16(uGBfloat value) {
    return (uint16_t)(value >> GB_FLOAT_FRACTIONAL_BITS);
}

//convert unsigned GBfloat degrees to radians
uGBfloat uGBfloatDegreesToRadians(uGBfloat degrees) {
    return uGBfloatDivide(GBfloatMultiply(degrees, UGBFLOAT_PI), floatToGBfloat(180, 0));
}
//convert signed GBfloat radians to degrees
uGBfloat uGBfloatRadiansToDegrees(uGBfloat radians) {
    uGBfloat degrees = uGBfloatDivide(uGBfloatMultiply(radians, floatToUGBfloat(180, 0)), UGBFLOAT_PI);  // radians * 180 / pi
    return degrees;
}

// Internal function for calculating lookup table indexes
uGBfloat unsigned_angle_to_index(uGBfloat angle) {
    uGBfloat angleIndex = uGBfloatDivide(uGBfloatMultiply(angle, uGBfloatSub(floatToUGBfloat(GBFLOAT_TABLE_SIZE, 0), floatToUGBfloat(1, 0))), uGBfloatMultiply(floatToUGBfloat(2, 0), UGBFLOAT_PI));
    return angleIndex;
}

// Accurate approximation of sine function using unsigned GBfloats
uGBfloat uGBfloat_sin(uGBfloat angle) {
    GBfloat angleIndex = unsigned_angle_to_index(angle);
    uint16_t index = uGBfloatToUint16(angleIndex);
    return uGBfloatSinTable[index];
}

// Accurate approximation of cosine function using unsigned GBfloats
uGBfloat uGBfloat_cos(uGBfloat angle) {
    uGBfloat angleIndex = unsigned_angle_to_index(angle);
    uint16_t index = uGBfloatToUint16(angleIndex);
    return uGBfloatCosTable[index];
}

// Accurate approximation of tangent function using unsigned GBfloats
uGBfloat uGBfloat_tan(GBfloat angle) {
    return uGBfloatDivide(uGBfloat_sin(angle), uGBfloat_cos(angle));
}

#endif // GBMATH_H
