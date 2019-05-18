/*
** EPITECH PROJECT, 2018
** random_verticals_lines
** File description:
** random_verticals_lines
*/

#include "includes/my_screensaver.h"

void set_line(main_t *main, int y, sfColor color)
{
    for (int x = 0; x < main->framebuffer->width; x++) {
        my_put_pixel(main->framebuffer, x, y, color);
    }
}

void random_verticals_lines(main_t *main)
{
    sfColor color;
    int y;

    while (sfRenderWindow_isOpen(main->window)) {
        analyse_events(main);
        y = rand() % main->framebuffer->height;
        set_color_white(&color);
        set_line(main, y, color);
        for (int i = 0; i < 20; i++) {
            y = rand() % main->framebuffer->height;
            set_color_black(&color);
            set_line(main, y, color);
        }
        draw_pixels(main);
    }
}