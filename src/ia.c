/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** ia.c
*/

#include "libmy.h"

int ia_match(int *matchs, int x, int y)
{
    int j = rand() % 3;
    int i = 0;

    while (matchs[i] == 0) {
        i++;
    }
    if (check_case(i, j, matchs) == -1)
        return (-1);
    display_ia(i, matchs, x, y);
    return 0;
}

void fill_values(int *value, int nb)
{
    value[0] = nb + (nb - 1);
    value[1] = 0;
    value[2] = 0;
    value[3] = value[0];
    value[4] = nb;
    value[5] = nb;
    value[6] = '\0';
}

int *fill_tab(int nb)
{
    int *matchs = malloc(sizeof(int) * (nb + 1));
    int *value = malloc(sizeof(int) * (6 + 1));
    fill_values(value, nb);

    for (int count_line = 0; count_line != nb; count_line++) {
      while (value[0] != 0) {
        if (value[5] <= value[0] && value[0] <= value[4])
	  value[1] = value[1] + 1;
        value[0] = value[0] - 1;
      }
      matchs[value[2]] = value[1];
      value[0] = value[3];
      value[4] = value[4] + 1;
      value[5] = value[5] - 1;
      value[2] = value[2] + 1;
      value[1] = 0;
    }
    free(value);
    return (matchs);
}

int random_number(int x, int y, int line, int nb_match) {
    int rand_nb = rand_nb = rand() % (y) + 1;

    while (nb_match - rand_nb < 0)
    {
        rand_nb = rand() % (y) + 1;
    }
    
    srand(time(0));
    return (rand_nb);
}
