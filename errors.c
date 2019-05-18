/*
** EPITECH PROJECT, 2018
** errors
** File description:
** errors
*/

#include "includes/my_functions.h"
#include "includes/my_screensaver.h"

int bad_arguments(int ac, char *av)
{
    write(2, av, my_strlen(av));
    write(2, ": bad arguments: ", 17);
    write(2, int_to_char(ac - 1), my_strlen(int_to_char(ac - 1)));
    write(2, " given but 1 is required\nRetry with -h\n", 39);
    return (84);
}

int h_argument(char *av)
{
    write(1, "Animation rendering in a CSFML window.\n\n", 40);
    write(1, "USAGE\n\t", 7);
    write(1, av, my_strlen(av));
    write(1, " [OPTIONS]  animation_id\n\tanimation_id                ", 54);
    write(1, "ID of the animation to process (between 1 and 8).\n\n", 51);
    write(1, "OPTIONS\n\t-d\t\t\t    Print the description of all", 46);
    write(1, " the animations and quit.\n\t-h\t\t\t    ", 36);
    write(1, "Print the usage and quit.\n\n", 27);
    write(1, "USER INTERACTIONS\n\tLeft Arrow\t\t    ", 35);
    write(1, "Switch to the previous animation.\n", 34);
    write(1, "\tRight Arrow\t\t    Switch to the next animation.\n", 49);
    write(1, "\tSpace Bar\t\t    Reset the animation.\n", 37);
    return (0);
}

int d_argument(void)
{
    write(1, "1: Pop random pixels with random color.\n", 40);
    write(1, "2: Trace random line direction with random color.\n", 50);
    write(1, "3: Pop random horizontal white lines.\n", 38);
    write(1, "4: Draw the way of square which move randomly with ", 51);
    write(1, "gradient color.\n", 16);
    write(1, "5: Pop quadrilateral with random color.\n", 40);
    write(1, "6: Draw circles which overlap.\n", 31);
    write(1, "7: Draw zoom circles with random color.\n", 40);
    write(1, "8: Pop random circles with random color.\n", 41);
    return (0);
}