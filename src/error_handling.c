/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** error_handling.c
*/

#include "libmy.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./matchstick x y\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    lines   number of lines in the game\n");
    my_putstr("    matchs  maximum number of match you can remove\n");
}

int error_handling(int ac, char **av)
{
    if (ac == 2 && (my_strcmp("-h", av[1]) == 0)) {
        usage();
        return(1);
    }
    if (ac != 3)
        return 84;
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 99)
        return 84;
    return 0;
}