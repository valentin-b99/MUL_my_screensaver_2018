/*
** EPITECH PROJECT, 2018
** id_screensavers
** File description:
** id_screensavers
*/

#ifndef ID_SCREENSAVERS_H_
#define ID_SCREENSAVERS_H_

#include "my_screensaver.h"

struct id_screensavers_s
{
    int id;
    void (*func)(main_t *);
};

struct id_screensavers_s id_ss[] =
{
    {1, &random_pixels},
    {2, &random_lines_trace},
    {3, &random_verticals_lines},
    {4, &random_snake_trace},
    {5, &random_square},
    {6, &random_circle},
    {7, &random_circle_zoom},
    {8, &random_circle_speed}
};

#endif /* !ID_SCREENSAVERS_H_ */
