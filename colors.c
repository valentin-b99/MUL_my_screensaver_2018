/*
** EPITECH PROJECT, 2018
** colors
** File description:
** colors
*/

#include "includes/my_screensaver.h"

void set_random_color(sfColor *color)
{
    color->r = rand() % 256;
    color->g = rand() % 256;
    color->b = rand() % 256;
    color->a = 255;
}

void set_random_color_gradient(sfColor *color)
{
    color->r = rand() % 156 + 50;
    color->g = rand() % 156 + 50;
    color->b = rand() % 156 + 50;
    color->a = 255;
}

void change_random_color_gradiant(sfColor *color, sfColor save_color)
{
    if (color->r < save_color.r - 50)
        color->r += rand() % 3;
    else if (color->r > save_color.r + 50)
        color->r -= rand() % 3;
    else
        color->r += rand() % 5 - 2;
    if (color->g < save_color.g - 50)
        color->g += rand() % 3;
    else if (color->g > save_color.g + 50)
        color->g -= rand() % 3;
    else
        color->g += rand() % 5 - 2;
    if (color->b < save_color.b - 50)
        color->b += rand() % 3;
    else if (color->b > save_color.b + 50)
        color->b -= rand() % 3;
    else
        color->b += rand() % 5 - 2;
}

void set_color_black(sfColor *color)
{
    color->r = 0;
    color->g = 0;
    color->b = 0;
    color->a = 0;
}

void set_color_white(sfColor *color)
{
    color->r = 255;
    color->g = 255;
    color->b = 255;
    color->a = 255;
}