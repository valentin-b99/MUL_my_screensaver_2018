/*
** EPITECH PROJECT, 2018
** random_lines_trace
** File description:
** random_lines_trace
*/

#include "includes/my_screensaver.h"

void display_line_h(main_t *main, coords_t *coords, sfColor color, int neg)
{
    my_put_pixel(main->framebuffer, coords->x, coords->y, color);
    my_put_pixel(main->framebuffer, coords->x + neg * 1, coords->y, color);
    my_put_pixel(main->framebuffer, coords->x + neg * 2, coords->y, color);
    my_put_pixel(main->framebuffer, coords->x + neg * 3, coords->y, color);
    my_put_pixel(main->framebuffer, coords->x + neg * 4, coords->y, color);
    coords->x += neg * 5;
}

void display_line_v(main_t *main, coords_t *coords, sfColor color, int neg)
{
    my_put_pixel(main->framebuffer, coords->x, coords->y, color);
    my_put_pixel(main->framebuffer, coords->x, coords->y + neg * 1, color);
    my_put_pixel(main->framebuffer, coords->x, coords->y + neg * 2, color);
    my_put_pixel(main->framebuffer, coords->x, coords->y + neg * 3, color);
    my_put_pixel(main->framebuffer, coords->x, coords->y + neg * 4, color);
    coords->y += neg * 5;
}

int test_where_is_pixel(main_t *main, coords_t *coords)
{
    if (coords->dir == 0 && coords->x >= main->framebuffer->width)
        return (1);
    if (coords->dir == 1 && coords->y >= main->framebuffer->height)
        return (1);
    if (coords->dir == 2 && coords->x < 0)
        return (1);
    if (coords->dir == 3 && coords->y < 0)
        return (1);
    return (0);
}

void set_dir_color(main_t *main, coords_t *coords, sfColor *color)
{
    coords->dir = rand() % 4;
    set_random_color(color);
    if (coords->dir == 0) {
        coords->x = 0;
        coords->y = rand() % main->framebuffer->height + 1;
    }
    if (coords->dir == 1) {
        coords->y = 0;
        coords->x = rand() % main->framebuffer->width + 1;
    }
    if (coords->dir == 2) {
        coords->x = main->framebuffer->width - 1;
        coords->y = rand() % main->framebuffer->height + 1;
    }
    if (coords->dir == 3) {
        coords->y = main->framebuffer->height - 1;
        coords->x = rand() % main->framebuffer->width + 1;
    }
}

void random_lines_trace(main_t *main)
{
    coords_t coords;
    sfColor color;

    set_dir_color(main, &coords, &color);
    while (sfRenderWindow_isOpen(main->window)) {
        analyse_events(main);
        if (coords.dir == 0)
            display_line_h(main, &coords, color, 1);
        if (coords.dir == 1)
            display_line_v(main, &coords, color, 1);
        if (coords.dir == 2)
            display_line_h(main, &coords, color, -1);
        if (coords.dir == 3)
            display_line_v(main, &coords, color, -1);
        if (test_where_is_pixel(main, &coords))
            set_dir_color(main, &coords, &color);
        draw_pixels(main);
    }
}