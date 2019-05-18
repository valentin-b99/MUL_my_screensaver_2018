/*
** EPITECH PROJECT, 2018
** random_square
** File description:
** random_square
*/

#include "includes/my_screensaver.h"

void set_random_size_and_coords(main_t *main, size_s_t *size, coords_t *coords)
{
    size->x = rand() % 200;
    size->y = rand() % 200;
    coords->x = rand() % (main->framebuffer->width - size->x);
    coords->y = rand() % (main->framebuffer->height - size->y);
}

void set_square(main_t *main, coords_t *coor, size_s_t size, sfColor color)
{
    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            my_put_pixel(main->framebuffer, coor->x + x, coor->y + y, color);
        }
    }
}

void random_square(main_t *main)
{
    coords_t coords;
    size_s_t size;
    sfColor color;

    while (sfRenderWindow_isOpen(main->window)) {
        analyse_events(main);
        set_random_color(&color);
        set_random_size_and_coords(main, &size, &coords);
        set_square(main, &coords, size, color);
        draw_pixels(main);
    }
}