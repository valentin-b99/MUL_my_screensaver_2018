/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** my_screensaver
*/

#ifndef MY_SCREENSAVER_H_
#define MY_SCREENSAVER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "framebuffer.h"
#include <unistd.h>

#define TEST_NEG_ID (main->id == 0) ? (main->id = 7) : (main->id -= 1)
#define TEST_SUP_ID (main->id == 7) ? (main->id = 0) : (main->id += 1)

typedef struct main
{
    sfRenderWindow *window;
    framebuffer_t *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    int id;
} main_t;

typedef struct coords
{
    int dir;
    int x;
    int y;
} coords_t;

typedef struct size_s
{
    int x;
    int y;
} size_s_t;

typedef struct circle_co
{
    int xxyy_x;
    int xxyy_y;
    int yxxy_x;
    int yxxy_y;
    int mxxyy_x;
    int mxxyy_y;
    int myxxy_x;
    int myxxy_y;
    int xxmyy_x;
    int xxmyy_y;
    int yxmxy_x;
    int yxmxy_y;
    int mxxmyy_x;
    int mxxmyy_y;
    int myxmxy_x;
    int myxmxy_y;
} circle_co_t;

typedef struct circle
{
    coords_t coords;
    int rayon;
    sfColor color;
    int size;
    int speed;
} circle_t;

int bad_arguments(int, char *);
int h_argument(char *);
int d_argument(void);

int my_screensaver(int);
int create_all(main_t *);
sfRenderWindow *create_windows(sfRenderWindow *);
void analyse_events(main_t *);
void analyse_events_next(main_t *, sfEvent);
void draw_pixels(main_t *);
void destroy_all(main_t *);


void set_random_color(sfColor *);
void set_random_color_gradient(sfColor *);
void change_random_color_gradiant(sfColor *, sfColor);
void set_color_black(sfColor *);
void set_color_white(sfColor *);

void random_pixels(main_t *);

void random_lines_trace(main_t *);
void display_line_h(main_t *, coords_t *, sfColor, int);
void display_line_v(main_t *, coords_t *, sfColor, int);
int test_where_is_pixel(main_t *, coords_t *);
void set_dir_color(main_t *, coords_t *, sfColor *);

void random_verticals_lines(main_t *);
void set_line(main_t *, int, sfColor);

void random_snake_trace(main_t *);
void set_square_snake(main_t *, coords_t *, sfColor);
void move_snake(main_t *, coords_t *);

void random_square(main_t *);
void set_square(main_t *, coords_t *, size_s_t, sfColor);
void set_random_size_and_coords(main_t *, size_s_t *, coords_t *);

void draw_all_circles(main_t *, circle_t *, circle_t *, circle_t *);

void random_circle(main_t *);
void draw_circle(main_t *, circle_t *);
void set_param_circle(circle_t *);
void set_random_coords(coords_t *);
void set_circle(main_t *, coords_t, int, sfColor);
void put_circle_pixels(main_t *, circle_co_t, sfColor);
void generate_coords_circle(circle_co_t *, int, int, coords_t);

void random_circle_zoom(main_t *);

void random_circle_speed(main_t *);

#endif /* !MY_SCREENSAVER_H_ */
