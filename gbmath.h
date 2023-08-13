#ifndef GBMATH_H
#define GBMATH_H

#include <stdint.h>
#include <stdlib.h>

#define TABLE_SIZE 256



// Fast approximation of sine function using lookup table
int8_t fast_sin(uint8_t angle)
{
    return sinTable[angle];
}

// Fast approximation of cosine function using lookup table
int8_t fast_cos(uint8_t angle)
{
    return cosTable[angle];
}

// Fast approximation of tangent function using lookup tables
int8_t fast_tan(uint8_t angle)
{
    // Calculate tangent as sin(angle) / cos(angle)
    return (fast_sin(angle) << 8) / fast_cos(angle);
}

// Define the fixed-point format
#define GB_FLOAT_FRACTIONAL_BITS 8
typedef int16_t GBfloat;

// Basic arithmetic operations for the GBfloat variable type
static inline GBfloat GBfloatAdd(GBfloat a, GBfloat b)
{
    int32_t result = a + b;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    if (fractionalPart >= 100 || fractionalPart <= -100)
    {
        integerPart += fractionalPart / 100;
        fractionalPart %= 100;
    }

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}

static inline GBfloat GBfloatSub(GBfloat a, GBfloat b)
{
    int32_t result = a - b;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    if (fractionalPart >= 100 || fractionalPart <= -100)
    {
        integerPart += fractionalPart / 100;
        fractionalPart %= 100;
    }

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}

static inline GBfloat GBfloatMultiply(GBfloat a, GBfloat b)
{
    int32_t result = ((int32_t)a * b + (1 << (GB_FLOAT_FRACTIONAL_BITS - 1))) >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    if (fractionalPart >= 100 || fractionalPart <= -100)
    {
        integerPart += fractionalPart / 100;
        fractionalPart %= 100;
    }

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}

static inline GBfloat GBfloatDivide(GBfloat a, GBfloat b)
{
    int32_t result = ((int32_t)a << GB_FLOAT_FRACTIONAL_BITS) / b;
    int16_t integerPart = result >> GB_FLOAT_FRACTIONAL_BITS;
    int16_t fractionalPart = result & 0xFF;

    // Round the fractional part
    fractionalPart = (fractionalPart * 100 + b / 2) / b;

    // Check if the fractional part is greater or equal to 100
    if (fractionalPart >= 100)
    {
        integerPart++;
        fractionalPart -= 100;
    }

    return (GBfloat)((integerPart << GB_FLOAT_FRACTIONAL_BITS) + fractionalPart);
}

// Conversion function
static inline GBfloat floatToGBfloat(int8_t whole_number, uint8_t decimal)
{
    int16_t result;
    if (whole_number < 0)
    {
        result = -((abs(whole_number) << GB_FLOAT_FRACTIONAL_BITS) + (decimal & 0xFF));
    }
    else
    {
        result = (whole_number << GB_FLOAT_FRACTIONAL_BITS) + (decimal & 0xFF);
    }
    return result;
}

static inline int8_t GBfloatToInt8(GBfloat value)
{
    return (int8_t)(value >> GB_FLOAT_FRACTIONAL_BITS);
}

#endif // GBMATH_H
