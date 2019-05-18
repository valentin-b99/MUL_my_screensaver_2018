/*
** EPITECH PROJECT, 2018
** framebuffer
** File description:
** framebuffer
*/

#include "includes/framebuffer.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(sizeof(sfUint8) * (width * height * 4 + 1));
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor color)
{
    if (x > 0 && x < framebuffer->width && y > 0 && y < framebuffer->height) {
        framebuffer->pixels[framebuffer->width * y * 4 + x * 4] = color.r;
        framebuffer->pixels[framebuffer->width * y * 4 + x * 4 + 1] = color.g;
        framebuffer->pixels[framebuffer->width * y * 4 + x * 4 + 2] = color.b;
        framebuffer->pixels[framebuffer->width * y * 4 + x * 4 + 3] = color.a;
    }
}