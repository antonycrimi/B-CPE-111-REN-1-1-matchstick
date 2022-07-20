/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** game_board.c
*/

#include "libmy.h"

void my_values(int *val, int nb)
{
  val[0] = 4;
  val[1] = 7;
  val[2] = nb + (nb - 1);
  val[3] = val[2];
  val[4] = nb;
  val[5] = nb;
  val[6] = 0;
  val[7] = '\0';
  stars(nb);
}

void my_print(int nb)
{
  stars(nb);
  my_putchar('\n');
}

void my_update_values(int *val, int *tab_buf, int *matchs)
{
  my_putchar('*');
  my_putchar('\n');
  val[2] = val[3];
  val[4] = val[4] + 1;
  val[5] = val[5] - 1;
  matchs[val[6]] = tab_buf[val[6]];
  val[6] = val[6] + 1;
}
