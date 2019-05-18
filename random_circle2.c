/*
** EPITECH PROJECT, 2018
** random_circle2
** File description:
** random_circle2
*/

#include "includes/my_screensaver.h"

void generate_coords_circle(circle_co_t *circle, int x, int y, coords_t coords)
{
    circle->xxyy_x = x + coords.x;
    circle->xxyy_y = y + coords.y;
    circle->yxxy_x = y + coords.x;
    circle->yxxy_y = x + coords.y;
    circle->mxxyy_x = -x + coords.x;
    circle->mxxyy_y = y + coords.y;
    circle->myxxy_x = -y + coords.x;
    circle->myxxy_y = x + coords.y;
    circle->xxmyy_x = x + coords.x;
    circle->xxmyy_y = -y + coords.y;
    circle->yxmxy_x = y + coords.x;
    circle->yxmxy_y = -x + coords.y;
    circle->mxxmyy_x = -x + coords.x;
    circle->mxxmyy_y = -y + coords.y;
    circle->myxmxy_x = -y + coords.x;
    circle->myxmxy_y = -x + coords.y;
}

void put_circle_pixels(main_t *main, circle_co_t crcl, sfColor color)
{
    my_put_pixel(main->framebuffer, crcl.xxmyy_x, crcl.xxyy_y, color);
    my_put_pixel(main->framebuffer, crcl.yxxy_x, crcl.yxxy_y, color);
    my_put_pixel(main->framebuffer, crcl.mxxyy_x, crcl.mxxyy_y, color);
    my_put_pixel(main->framebuffer, crcl.myxxy_x, crcl.myxxy_y, color);
    my_put_pixel(main->framebuffer, crcl.xxmyy_x, crcl.xxmyy_y, color);
    my_put_pixel(main->framebuffer, crcl.yxmxy_x, crcl.yxmxy_y, color);
    my_put_pixel(main->framebuffer, crcl.mxxmyy_x, crcl.mxxmyy_y, color);
    my_put_pixel(main->framebuffer, crcl.myxmxy_x, crcl.myxmxy_y, color);
}

void set_circle(main_t *main, coords_t coords, int rayon, sfColor color)
{
    circle_co_t circle;
    int x = 0;
    int y = rayon;
    int d = rayon - 1;

    while (x <= y) {
        generate_coords_circle(&circle, x, y, coords);
        put_circle_pixels(main, circle, color);
        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        } else if (d < 2 * (rayon - y)) {
            d += 2 * y - 1;
            y--;
        } else {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}