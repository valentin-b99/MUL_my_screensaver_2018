/*
** EPITECH PROJECT, 2018
** random_pixels
** File description:
** random_pixels
*/

#include "includes/my_screensaver.h"

void random_pixels(main_t *main)
{
    int x;
    int y;
    sfColor color;

    while (sfRenderWindow_isOpen(main->window)) {
        analyse_events(main);
        x = rand() % main->framebuffer->width;
        y = rand() % main->framebuffer->height;
        set_random_color(&color);
        my_put_pixel(main->framebuffer, x, y, color);
        draw_pixels(main);
    }
}