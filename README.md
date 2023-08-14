

# gbmath.h

This is a new library for GBDK that adds functions such as sin, cos, and tan to your GBDK project.


# "Installation"
Download the `gbmath.h` file, and put it in a location you can remember. 
Include it in your code via `#include <path/to/gbmath.h>`

## Functions 

|Function|Input Kind|Output Kind|Notes|
|----------------|-------------------------------|-----------------------------|-|
|`fast_sin()`|uint8_t  `angle`|int8_t `[Sin of Angle]`| is not a `GBfloat` type
|`fast_cos()`|uint8_t  `angle`|int8_t `[Cos of Angle]`| is not a `GBfloat` type
|`fast_tan()`|uint8_t  `angle`|int8_t `[Tan of Angle]`| is not a `GBfloat` type
|`GBfloatAdd()`|GBfloat `a` GBfloat `b`|GBfloat `[sum]`|not required for addition.
|`GBfloatSub()`|GBfloat `a` GBfloat `b`|GBfloat `[sum]`|not required for subtraction.
|`GBfloatMultiply()`|GBfloat `a` GBfloat `b`|GBfloat `[sum]`|this is required to multiply 2 `GBfloat` variables.
|`GBfloatDivide()`|GBfloat `top` GBfloat `bottom`|GBfloat `[sum]`|this is required to divide 2 `GBfloat` variables.
|`floatToGBfloat()`|int8_t `whole_number` uint8_t `decimal` |GBfloat `[fixed point number]`| if you want to pass `1.20` into a `GBfloat`: `floatToGBfloat(1, 20);`
|`GBfloatToInt8()`|GBfloat `number` |int8_t `[rounded_whole_number]` |will round a `GBfloat 1.51` to a `int8_t 2`.
|`GBfloatToInt16()`|GBfloat `number` |int16_t `[rounded_whole_number]` |will round a `GBfloat 1.51` to a `int16_t 2`.
|`GBfloat_sin()`|GBfloat `radians` |GBfloat `[Sin of Radian]` |will output a `GBfloat` variable type.
|`GBfloat_cos()`|GBfloat `radians` |GBfloat `[Cos of Radian]` |will output a `GBfloat` variable type.
|`GBfloat_tan()`|GBfloat `radians` |GBfloat `[Tan of Radian]` |will output a `GBfloat` variable type.
|`GBfloatDegreesToRadians()`|GBfloat `degrees` |GBfloat `radian` |will output a `GBfloat` variable type.
|`GBfloatRadiansToDegrees()`|GBfloat `radians` |GBfloat `degrees` |will output a `GBfloat` variable type.
|`angle_to_index()`|GBfloat `angle` |GBfloat `[Index for LUT]` |this does not need to be called, it is internally used.

## Defined stuff

|Thingymabob|value|usage|
|----------------|-------------------------------|-----------------------------|
|`TABLE_SIZE`|256|for various fast sin/cos/tan LUT functions
|`GBFLOAT_TABLE_SIZE`|256|for various GBfloat sin/cos/tan LUT functions
|`GB_FLOAT_FRACTIONAL_BITS`|8| for bitwise operations, feel free to change this at your own risk.|
|`GBFLOAT_PI`|3.14|for radian and degree conversion. and for your usage as well. (this is in GBfloat format)


## Examples
I have an examples folder that contains example uses for each function.
More to come soon.

#### Tank Controls
This example shows how you can use these functions to rotate a "player" (in this case a dot) 

#### GBfloats
This example shows off how to use the new `GBfloat` (`int16_t`) variable type. it lets you easily use floating point numbers in gbdk. (as of now, there is no sin, cos, or tan functions that use this variable type, this is being worked on)

## GBfloat Sin, Cos, and Tan Lookup tables:

<details>
  <summary>(Click to Show)</summary>
  
 ### SIN
 ```const GBfloat GBfloatSinTable[GBFLOAT_TABLE_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -122, -35, -35, -35, -35, -35, -35, -35, -35, -35, -35, -35, -35};```

 ### COS
 ```const GBfloat GBfloatCosTable[GBFLOAT_TABLE_SIZE] = {127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, 69, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -53, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, -83, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122};```
 
### TAN

Tan simply uses the last 2 tables in order to save space.
I am considering a separate look up table to save speed.
```GBfloatDivide(GBfloat_sin(angle), GBfloat_cos(angle));```


</details>


## Fast Sin, Cos, and Tan Lookup tables:

<details>
  <summary>(Click to Show)</summary>
  
 ### SIN
 ```const  int8_t  sinTable[TABLE_SIZE] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 59, 62, 65, 67, 70, 73, 75, 78, 80, 82, 85, 87, 89, 91, 94, 96, 98, 100, 102, 103, 105, 107, 108, 110, 112, 113, 114, 116, 117, 118, 119, 120, 121, 122, 123, 123, 124, 125, 125, 126, 126, 126, 126, 126, 127, 126, 126, 126, 126, 126, 125, 125, 124, 123, 123, 122, 121, 120, 119, 118, 117, 116, 114, 113, 112, 110, 108, 107, 105, 103, 102, 100, 98, 96, 94, 91, 89, 87, 85, 82, 80, 78, 75, 73, 70, 67, 65, 62, 59, 57, 54, 51, 48, 45, 42, 39, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 0, -3, -6, -9, -12, -15, -18, -21, -24, -27, -30, -33, -36, -39, -42, -45, -48, -51, -54, -57, -59, -62, -65, -67, -70, -73, -75, -78, -80, -82, -85, -87, -89, -91, -94, -96, -98, -100, -102, -103, -105, -107, -108, -110, -112, -113, -114, -116, -117, -118, -119, -120, -121, -122, -123, -123, -124, -125, -125, -126, -126, -126, -126, -126, -127, -126, -126, -126, -126, -126, -125, -125, -124, -123, -123, -122, -121, -120, -119, -118, -117, -116, -114, -113, -112, -110, -108, -107, -105, -103, -102, -100, -98, -96, -94, -91, -89, -87, -85, -82, -80, -78, -75, -73, -70, -67, -65, -62, -59, -57, -54, -51, -48, -45, -42, -39, -36, -33, -30, -27, -24, -21, -18, -15, -12, -9, -6, -3, };```

 ### COS
 ```const  int8_t  cosTable[TABLE_SIZE] = {127, 126, 126, 126, 126, 126, 125, 125, 124, 123, 123, 122, 121, 120, 119, 118, 117, 116, 114, 113, 112, 110, 108, 107, 105, 103, 102, 100, 98, 96, 94, 91, 89, 87, 85, 82, 80, 78, 75, 73, 70, 67, 65, 62, 59, 57, 54, 51, 48, 45, 42, 39, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 0, -3, -6, -9, -12, -15, -18, -21, -24, -27, -30, -33, -36, -39, -42, -45, -48, -51, -54, -57, -59, -62, -65, -67, -70, -73, -75, -78, -80, -82, -85, -87, -89, -91, -94, -96, -98, -100, -102, -103, -105, -107, -108, -110, -112, -113, -114, -116, -117, -118, -119, -120, -121, -122, -123, -123, -124, -125, -125, -126, -126, -126, -126, -126, -127, -126, -126, -126, -126, -126, -125, -125, -124, -123, -123, -122, -121, -120, -119, -118, -117, -116, -114, -113, -112, -110, -108, -107, -105, -103, -102, -100, -98, -96, -94, -91, -89, -87, -85, -82, -80, -78, -75, -73, -70, -67, -65, -62, -59, -57, -54, -51, -48, -45, -42, -39, -36, -33, -30, -27, -24, -21, -18, -15, -12, -9, -6, -3, 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 59, 62, 65, 67, 70, 73, 75, 78, 80, 82, 85, 87, 89, 91, 94, 96, 98, 100, 102, 103, 105, 107, 108, 110, 112, 113, 114, 116, 117, 118, 119, 120, 121, 122, 123, 123, 124, 125, 125, 126, 126, 126, 126, 126, };```
 
### TAN

Tan simply uses the last 2 tables in order to save space.
I am considering a separate look up table to save speed.
```(fast_sin(angle) <<  8) /  fast_cos(angle)```


</details>

# Contributing
if you have a new function or optimizations you want added, you can make a pull request. (or file an issue)

> **Note:** I do not promise that these functions are truly fast.
all I can advise is to not overdo the tan function, as it uses division.
