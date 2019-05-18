/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** my_screensaver
*/

#include "includes/my_functions.h"
#include "includes/my_screensaver.h"
#include "includes/id_screensavers.h"
#include <time.h>

void analyse_events_next(main_t *main, sfEvent event)
{
    if (event.key.code == sfKeyRight && event.type == sfEvtKeyPressed) {
        TEST_SUP_ID;
        main->framebuffer = framebuffer_create(1920, 1080);
        id_ss[main->id].func(main);
    }
    if (event.key.code == sfKeyLeft && event.type == sfEvtKeyPressed) {
        TEST_NEG_ID;
        main->framebuffer = framebuffer_create(1920, 1080);
        id_ss[main->id].func(main);
    }
}

void analyse_events(main_t *main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(main->window);
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(main->window);
        if (event.key.code == sfKeySpace && event.type == sfEvtKeyPressed) {
            main->framebuffer = framebuffer_create(1920, 1080);
            id_ss[main->id].func(main);
        }
        analyse_events_next(main, event);
    }
}

int my_screensaver(int id_give)
{
    main_t main;
    main.id = 0;

    while (id_ss[main.id].id != id_give)
        main.id += 1;
    srand(time(NULL));
    if (create_all(&main) == 84)
        return (84);
    id_ss[main.id].func(&main);
    destroy_all(&main);
    return (0);
}

int main(int ac, char **av)
{
    int id;

    if (ac != 2)
        return (bad_arguments(ac, av[0]));
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (h_argument(av[0]));
    if (av[1][0] == '-' && av[1][1] == 'd')
        return (d_argument());
    id = my_getnbr(av[1]);
    if (id < 1 || id > 8)
        return (84);
    my_screensaver(id);
}