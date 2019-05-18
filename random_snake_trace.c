/*
** EPITECH PROJECT, 2018
** random_snake_trace
** File description:
** random_snake_trace
*/

#include "includes/my_screensaver.h"

void move_snake(main_t *main, coords_t *coords)
{
    if (coords->dir == 0)
        coords->x += 30;
    if (coords->dir == 1)
        coords->y += 30;
    if (coords->dir == 2)
        coords->x -= 30;
    if (coords->dir == 3)
        coords->y -= 30;
    if (coords->x < 0)
        coords->x = main->framebuffer->width - 30;
    if (coords->x > main->framebuffer->width - 30)
        coords->x = 0;
    if (coords->y < 0)
        coords->y = main->framebuffer->height - 30;
    if (coords->y > main->framebuffer->height - 30)
        coords->y = 0;
}

void set_square_snake(main_t *main, coords_t *coor, sfColor color)
{
    for (int x = 0; x < 30; x++) {
        for (int y = 0; y < 30; y++) {
            my_put_pixel(main->framebuffer, coor->x + x, coor->y + y, color);
        }
    }
}

void random_snake_trace(main_t *main)
{
    coords_t coords = {.x = rand() % main->framebuffer->width,
        .y = rand() % main->framebuffer->height, .dir = rand() % 4};
    sfColor color;
    sfColor save_color;

    set_random_color_gradient(&color);
    save_color = color;
    while (sfRenderWindow_isOpen(main->window)) {
        analyse_events(main);
        set_square_snake(main, &coords, color);
        move_snake(main, &coords);
        coords.dir = rand() % 4;
        change_random_color_gradiant(&color, save_color);
        draw_pixels(main);
    }
}