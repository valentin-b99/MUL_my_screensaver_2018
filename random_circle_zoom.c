/*
** EPITECH PROJECT, 2018
** random_circle_zoom
** File description:
** random_circle_zoom
*/

#include "includes/my_screensaver.h"

void random_circle_zoom(main_t *main)
{
    circle_t circles[3];
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    set_param_circle(&circles[0]);
    set_param_circle(&circles[1]);
    set_param_circle(&circles[2]);
    while (sfRenderWindow_isOpen(main->window)) {
        analyse_events(main);
        draw_all_circles(main, &circles[0], &circles[1], &circles[2]);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.3) {
            set_param_circle(&circles[0]);
            set_param_circle(&circles[1]);
            set_param_circle(&circles[2]);
            sfClock_restart(clock);
        }
    }
}