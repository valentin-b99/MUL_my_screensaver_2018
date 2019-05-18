/*
** EPITECH PROJECT, 2018
** create_draw_destroy
** File description:
** creates_draw_destroy
*/

#include "includes/my_screensaver.h"

sfRenderWindow *create_windows(sfRenderWindow *window)
{
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "My ScreenSaver",
    sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 100);
    return (window);
}

int create_all(main_t *main)
{
    main->window = create_windows(main->window);
    if (!main->window)
        return (84);
    main->sprite = sfSprite_create();
    main->framebuffer = framebuffer_create(1920, 1080);
    main->texture = sfTexture_create(1920, 1080);
    if (!main->texture)
        return (84);
    sfSprite_setTexture(main->sprite, main->texture, sfTrue);
    return (0);
}

void draw_pixels(main_t *main)
{
    sfTexture_updateFromPixels(main->texture, main->framebuffer->pixels,
    1920, 1080, 0, 0);
    sfRenderWindow_clear(main->window, sfBlack);
    sfRenderWindow_drawSprite(main->window, main->sprite, NULL);
    sfRenderWindow_display(main->window);
}

void destroy_all(main_t *main)
{
    framebuffer_destroy(main->framebuffer);
    sfSprite_destroy(main->sprite);
    sfTexture_destroy(main->texture);
    sfRenderWindow_destroy(main->window);
}