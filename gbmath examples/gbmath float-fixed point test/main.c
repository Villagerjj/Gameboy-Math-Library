#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "gbmath.h"

void main() {

    SHOW_BKG;
    SHOW_SPRITES;

    uint8_t angle = 45; // Angle in degrees
    uint8_t Rangle = 1; // Angle in radians
    // Test fast_sin, fast_cos, and fast_tan
    printf("Fast Functions:\n");
    printf("Angle(R): %d\n", Rangle);
    printf("Fast sin: %d\n", fast_sin(Rangle));
    printf("Fast cos: %d\n", fast_cos(Rangle));
    printf("Fast tan: %d\n", fast_tan(Rangle));

    // Test GBfloat_sin, GBfloat_cos, and GBfloat_tan
    GBfloat gb_angle = floatToGBfloat(angle, 0);
    printf("GBfloat Functions:\n");
    printf("Angle(R): %d.%02d)\n", GBfloatToInt16(gb_angle));
    printf("GBfloat sin: %d.%02d\n", GBfloat_sin(gb_angle) / 256, GBfloat_sin(gb_angle) % 256);
    printf("GBfloat cos: %d.%02d\n", GBfloat_cos(gb_angle) / 256, GBfloat_cos(gb_angle) % 256);
    printf("GBfloat tan: %d.%02d\n", GBfloat_tan(gb_angle) / 256, GBfloat_tan(gb_angle) % 256);

    // Test GBfloat arithmetic operations
    GBfloat a = floatToGBfloat(1, 0);
    GBfloat b = floatToGBfloat(0, 50);
    uGBfloat c = floatToUGBfloat(255, 99);
    GBfloat result_add = GBfloatAdd(a, b);
    uGBfloat result_sub = uGBfloatSub(a, b);
    GBfloat result_mul = GBfloatMultiply(a, b);
    uGBfloat result_div = uGBfloatDivide(a, b);
     
    printf("GBfloat Maths:\n");
    printf("a: %d.%02d\n", a / 256, a % 256);
    printf("b: %d.%02d\n", b / 256, b % 256);
    printf("unsigned c: %d.%02d\n", c / 256, c % 256);
    printf("Addition: %d.%02d\n", result_add/ 256, result_add% 256);
    printf("Subtraction: %d.%02d\n", result_sub / 256, result_sub % 256);
    printf("Multiplication: %d.%02d\n", result_mul/ 256, result_mul% 256);
    printf("Division: %d.%02d\n", result_div/ 256, result_div% 256);


}
