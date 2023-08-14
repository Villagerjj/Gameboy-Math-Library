#ifndef GBMATH_H
#define GBMATH_H

#include <stdint.h>
#include <stdlib.h>







#define TABLE_SIZE 256

// Lookup tables for the old sin and cos values
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

// Define the fixed-point format
#define GB_FLOAT_FRACTIONAL_BITS 8
typedef int16_t GBfloat;
#define GBFLOAT_TABLE_SIZE 256


// Lookup tables for sin and cos values
const GBfloat GBfloatSinTable[GBFLOAT_TABLE_SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-96,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-122,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35};
const GBfloat GBfloatCosTable[GBFLOAT_TABLE_SIZE] = {127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-53,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-126,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,-83,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,122,122,122,122,122,122,122,122,122,122,122,122};

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

static inline GBfloat GBfloatSub(GBfloat a, GBfloat b) {
    int32_t result = a - b;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

   

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}

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



// Conversion function
static inline GBfloat floatToGBfloat(int8_t whole_number, uint8_t decimal) {
    int16_t result;
    if (whole_number < 0) {
        result = -((abs(whole_number) << GB_FLOAT_FRACTIONAL_BITS) + (decimal & 0xFF));
    } else {
        result = (whole_number << GB_FLOAT_FRACTIONAL_BITS) + (decimal & 0xFF);
    }
    return result;
}

#define GBFLOAT_PI floatToGBfloat(3, 14)

static inline int8_t GBfloatToInt8(GBfloat value) {
    return (int8_t)(value >> GB_FLOAT_FRACTIONAL_BITS);
}

static inline int16_t GBfloatToInt16(GBfloat value) {
    return (int16_t)(value >> GB_FLOAT_FRACTIONAL_BITS);
}

// Calculate the lookup table index
GBfloat angle_to_index(GBfloat angle) {
    GBfloat angleIndex = GBfloatDivide(GBfloatMultiply(angle, GBfloatSub(floatToGBfloat(GBFLOAT_TABLE_SIZE, 0), floatToGBfloat(1, 0))), GBfloatMultiply(floatToGBfloat(2, 0), GBFLOAT_PI));
    return angleIndex;
}

// Fast approximation of sine function using lookup table
GBfloat GBfloat_sin(GBfloat angle) {
    GBfloat angleIndex = angle_to_index(angle);
    int16_t index = GBfloatToInt16(angleIndex);
    return GBfloatSinTable[index];
}

// Fast approximation of cosine function using lookup table
GBfloat GBfloat_cos(GBfloat angle) {
    GBfloat angleIndex = angle_to_index(angle);
    int16_t index = GBfloatToInt16(angleIndex);
    return GBfloatCosTable[index];
}

// Fast approximation of tangent function using lookup tables
GBfloat GBfloat_tan(GBfloat angle) {
    return GBfloatDivide(GBfloat_sin(angle), GBfloat_cos(angle));
}


GBfloat GBfloatDegreesToRadians(GBfloat degrees) {
    return GBfloatDivide(GBfloatMultiply(degrees, GBFLOAT_PI), floatToGBfloat(180, 0));
}

GBfloat GBfloatRadiansToDegrees(GBfloat radians) {
    GBfloat degrees = GBfloatDivide(GBfloatMultiply(radians, floatToGBfloat(180, 0)), GBFLOAT_PI);  // radians * 180 / pi
    return degrees;
}

#endif // GBMATH_H
