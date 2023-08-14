#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "gbmath.h" 



uint8_t main() {
    // Raw fixed-point values (1.45 and 0.10 as 8-bit fixed-point)
    GBfloat angle = floatToGBfloat(69, 00);  // 1.45 in 8-bit fixed-point 
    GBfloat sinValue = GBfloat_sin(angle);
    GBfloat cosValue = GBfloat_cos(angle);
    GBfloat tanValue = GBfloat_tan(angle);
    GBfloat FastsinValue = fast_sin(GBfloatToInt8(angle));
    GBfloat FastcosValue = fast_cos(GBfloatToInt8(angle));
    GBfloat FasttanValue = fast_tan(GBfloatToInt8(angle));
 
    GBfloat IncreaseBy = floatToGBfloat(0, 10);  // 0.10 in 8-bit fixed-point 
    GBfloat DecreaseBy = floatToGBfloat(0, 1);  // 0.10 in 8-bit fixed-point 
      
    GBfloat TestNumber = floatToGBfloat(5, 50);
    
   


    printf("test: %d.%02d\n", TestNumber / 256, TestNumber % 256);
    printf("test (rounded): %d\n", GBfloatToInt8(TestNumber));

 
    // Add
    GBfloat newAngle = GBfloatAdd(TestNumber, IncreaseBy);
    printf("add .10: %d.%02d\n", newAngle / 256, newAngle % 256);

    // Subtract
    GBfloat decreasedAngle = GBfloatSub(newAngle, DecreaseBy);
    printf("subtract .01: %d.%02d\n", decreasedAngle / 256, decreasedAngle % 256);

    // Multiply
    GBfloat multipliedAngle = GBfloatMultiply(TestNumber, floatToGBfloat(2, 0));
    printf("test x 2: %d.%02d\n", multipliedAngle / 256, multipliedAngle % 256);

    // Divide
    GBfloat dividedAngle = GBfloatDivide(TestNumber, floatToGBfloat(2, 0));
    printf("test / 2: %d.%02d\n", dividedAngle / 256, dividedAngle % 256);
   
    printf("Angle(D): %d.%02d\n", angle / 256, angle % 256); 
    printf("Angle(R): %d.%02d\n", GBfloatDegreesToRadians(angle) / 256, GBfloatDegreesToRadians(angle) % 256); 
    printf("Angle(Rounded): %d\n", GBfloatToInt8(angle));
    printf("FloatSin(D): %d.%02d\n", GBfloatRadiansToDegrees(sinValue) / 256, GBfloatRadiansToDegrees(sinValue) % 256);
    printf("FloatCos(R): %d.%02d\n", cosValue / 256, cosValue % 256);
    printf("FloatTan(R): %d.%02d\n", tanValue / 256, tanValue % 256);
    printf("FastSin(D): %d.%02d\n", GBfloatRadiansToDegrees(FastsinValue) / 256, GBfloatRadiansToDegrees(FastsinValue) % 256);
    printf("FastCos(R): %d.%02d\n", FastcosValue / 256, FastcosValue % 256);
    printf("FastTan(R): %d.%02d\n", FasttanValue / 256, FasttanValue % 256);
       
    return 0;
}