/*
** EPITECH PROJECT, 2018
** framebuffer
** File description:
** framebuffer
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <stdlib.h>
#include <SFML/Graphics.h>

typedef struct framebuffer
{
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int, unsigned int);
void framebuffer_destroy(framebuffer_t *);
void my_put_pixel(framebuffer_t *, unsigned int, unsigned int, sfColor);

#endif /* !FRAMEBUFFER_H_ */
