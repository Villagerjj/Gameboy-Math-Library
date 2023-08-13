#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "gbmath.h"

// Screen dimensions
#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 144

// Tank pixel position and angle
int8_t tank_x = SCREEN_WIDTH / 2;
int8_t tank_y = SCREEN_HEIGHT / 2;
uint8_t tank_angle = 0; // Angle in degrees (0-255 corresponds to 0-360 degrees)

void move_tank(int8_t dx, int8_t dy)
{
    tank_x += dx;
    tank_y += dy;

    // Clamp tank position within screen bounds
    if (tank_x < 0)
        tank_x = 0;
    if (tank_x >= SCREEN_WIDTH)
        tank_x = SCREEN_WIDTH - 1;
    if (tank_y < 0)
        tank_y = 0;
    if (tank_y >= SCREEN_HEIGHT)
        tank_y = SCREEN_HEIGHT - 1;

    // Draw tank pixel at the new position
    plot_point(tank_x, tank_y);
}

void rotate_tank(int8_t rotation)
{
    tank_angle = (tank_angle + rotation) % 256;
}

int main()
{

    while (1)
    {
        uint8_t cur = joypad();

        if (cur & J_UP)
        {
            int8_t move_dx = fast_cos(tank_angle) >> 6; // Adjust the scale as needed
            int8_t move_dy = fast_sin(tank_angle) >> 6; // Adjust the scale as needed
            move_tank(move_dx, move_dy);
        }
        else if (cur & J_DOWN)
        {
            int8_t move_dx = -fast_cos(tank_angle) >> 6; // Adjust the scale as needed
            int8_t move_dy = -fast_sin(tank_angle) >> 6; // Adjust the scale as needed
            move_tank(move_dx, move_dy);
        }

        if (cur & J_LEFT)
        {
            rotate_tank(-10); // Adjust the rotation amount as needed
        }
        else if (cur & J_RIGHT)
        {
            rotate_tank(10); // Adjust the rotation amount as needed
        }
        delay(100);
        // Feel free to change the delay. it is only here because the tank controls run so well.
    }

    return 0;
}