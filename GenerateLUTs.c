#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef int32_t GBfloat16;
typedef uint32_t uGBfloat16;

#define LUT_SIZE 360
#define FIXED_POINT_SHIFT 16

GBfloat16 floatToGBfloat16(int16_t whole_number, uint16_t decimal) {
    GBfloat16 fixedValue = (GBfloat16)whole_number << FIXED_POINT_SHIFT;
    fixedValue += (GBfloat16)(decimal << FIXED_POINT_SHIFT) / 100;
    return fixedValue;
}

int main() {
    GBfloat16 sin_lut[LUT_SIZE];
    GBfloat16 cos_lut[LUT_SIZE];
    GBfloat16 tan_lut[LUT_SIZE];

    for (int i = 0; i < LUT_SIZE; i++) {
        double radians = i * M_PI / 180.0;

        double sin_value = sin(radians);
        double cos_value = cos(radians);
        double tan_value = tan(radians);

        // Convert to 16.16 fixed-point notation
        sin_lut[i] = floatToGBfloat16((int16_t)(sin_value * (1 << FIXED_POINT_SHIFT)),
                                      (uint16_t)(((sin_value * (1 << FIXED_POINT_SHIFT)) - (int16_t)(sin_value * (1 << FIXED_POINT_SHIFT))) * 100));

        cos_lut[i] = floatToGBfloat16((int16_t)(cos_value * (1 << FIXED_POINT_SHIFT)),
                                      (uint16_t)(((cos_value * (1 << FIXED_POINT_SHIFT)) - (int16_t)(cos_value * (1 << FIXED_POINT_SHIFT))) * 100));

        tan_lut[i] = floatToGBfloat16((int16_t)(tan_value * (1 << FIXED_POINT_SHIFT)),
                                      (uint16_t)(((tan_value * (1 << FIXED_POINT_SHIFT)) - (int16_t)(tan_value * (1 << FIXED_POINT_SHIFT))) * 100));
    }

    // Print the LUTs
    printf("const GBfloat16 sin_lut[LUT_SIZE] = {\n");
    for (int i = 0; i < LUT_SIZE; i++) {
        printf("%d, ", sin_lut[i]);
    }
    printf("};\n\n");

    printf("const GBfloat16 cos_lut[LUT_SIZE] = {\n");
    for (int i = 0; i < LUT_SIZE; i++) {
        printf("%d, ", cos_lut[i]);
    }
    printf("};\n\n");

    printf("const GBfloat16 tan_lut[LUT_SIZE] = {\n");
    for (int i = 0; i < LUT_SIZE; i++) {
        printf("%d, ", tan_lut[i]);
    }
    printf("};\n");

    return 0;
}
