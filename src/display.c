/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** display.c
*/

#include "libmy.h"

void display_turn(int tour)
{
    if (tour % 2 == 0)
        my_putstr("Your turn:\n");
    else
        my_putstr("Ai's turn...\n");
}

void display_play(int line, int match)
{
    my_putstr("Player removed ");
    my_putnbr(match);
    my_putstr(" match(es) from line ");
    my_putnbr(line + 1);
    my_putchar('\n');
    my_putchar('\n');
}

void display_ia(int line, int *matchs, int x, int y)
{
    int rand = random_number(x, y, line, matchs[line]);
    my_putstr("AI removed ");
    my_putnbr(rand);
    my_putstr(" match(es) from line ");
    my_putnbr(line+1);
    my_putchar('\n');
    my_putchar('\n');
    matchs[line] = matchs[line] - rand;
}

int check_case(int line, int match, int *matchs)
{
    if (matchs[line] < match) {
        my_putstr("Error: not enough matches on this line");
        return (-1);
    }
    else
        return 0;

}

int check_tour(int tour, int nb, int y, int *matchs)
{
    int line;
    int match; 
    int check;

    if (tour % 2 == 0) {
        if ((line = get_line(nb)) < 0)
            return (line);
        if ((match = get_match(y)) < 0)
            return (match);
        if ((check = check_case(line, match, matchs)) < 0)
            return (check);
        display_play(line, match);
    }
    else {
        ia_match(matchs, nb, y);
        return (0);
    }
    matchs[line] = matchs[line] - match;
    return (check);
}
