/*
** EPITECH PROJECT, 2018
** random_circle
** File description:
** random_circle
*/

#include "includes/my_screensaver.h"

void set_random_coords(coords_t *coords)
{
    coords->x = rand() % 1920;
    coords->y = rand() % 1080;
}

void set_param_circle(circle_t *circle)
{
    circle->rayon = 0;
    circle->size = rand() % 1000 + 920;
    circle->speed = rand() % 7 + 1;
    set_random_coords(&circle->coords);
    set_random_color(&circle->color);
}

void draw_circle(main_t *main, circle_t *circle)
{
    for (int i = 0; i < circle->speed; i++) {
        set_circle(main, circle->coords, circle->rayon, circle->color);
        circle->rayon++;
    }
    if (circle->rayon > circle->size) {
        circle->rayon = 0;
        set_random_color(&circle->color);
        set_random_coords(&circle->coords);
        circle->size = rand() % 1000 + 920;
        circle->speed = rand() % 7 + 1;
    }
}

void random_circle(main_t *main)
{
    circle_t circles[3];

    set_param_circle(&circles[0]);
    set_param_circle(&circles[1]);
    set_param_circle(&circles[2]);
    while (sfRenderWindow_isOpen(main->window)) {
        analyse_events(main);
        draw_circle(main, &circles[0]);
        draw_circle(main, &circles[1]);
        draw_circle(main, &circles[2]);
        draw_pixels(main);
    }
}