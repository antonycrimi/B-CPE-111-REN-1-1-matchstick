/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** game_board.c
*/

#include "libmy.h"

int check_score(int tour, int *matchs, int nb)
{
  int i = 0;
  int score = 0;

  while (i != nb)
  {
    score = score + matchs[i];
    i++;
  }
  if (score == 0 && tour % 2 != 0)
  {
    my_putstr("You lost, too bad...");
    free(matchs);
    return 2;
  }
  if (score == 0 && tour % 2 == 0)
  {
    my_putstr("I lost... snif... but I'll get you next time!!");
    free(matchs);
    return 1;
  }
  return 0;
}

void stars(int nb)
{
  int nb_etoile = nb * 2 + 1;

  while (nb_etoile != 0)
  {
    my_putchar('*');
    nb_etoile = nb_etoile - 1;
  }
  my_putchar('\n');
}

void my_print_tab(int *val, int *tab_buf, int *matchs)
{
  my_putchar('*');
  matchs[val[6]] = tab_buf[val[6]];
  while (val[2] != 0)
  {
    if (val[5] <= val[2] && val[2] <= val[4] && matchs[val[6]] != 0)
    {
      my_putchar('|');
      val[2] = val[2] - 1;
      matchs[val[6]] = matchs[val[6]] - 1;
    }
    else
    {
      my_putchar(' ');
      val[2] = val[2] - 1;
    }
  }
}

int corps(int nb, int y, int tour, int *tab_buf)
{
  int *val = malloc(sizeof(int) * (8));
  int *matchs = fill_tab(nb);
  int return_value = check_score(tour, tab_buf, nb);

  if (return_value == 1)
    return 1;
  if (return_value == 2)
    return 2;
  my_values(val, nb);
  for (int count_line = 0; count_line != nb; count_line++)
  {
    my_print_tab(val, tab_buf, matchs);
    my_update_values(val, tab_buf, matchs);
  }
  my_print(nb);
  display_turn(tour);
  while ((val[1] = check_tour(tour, nb, y, tab_buf)) != 0)
    if (val[1] == -84)
      return -84;
  tour++;
  free(matchs);
  free(val);
  return (corps(nb, y, tour, tab_buf));
}

int main(int ac, char **av)
{
  int error_return = error_handling(ac, av);

  if (error_return == 84)
    return 84;
  else if (error_return == 1)
    return 0;
  
  int x = my_getnbr(av[1]);
  int y = my_getnbr(av[2]);
  int tour = 0;
  int *tab_buf = fill_tab(x);
  int error;

  error = corps(x, y, tour, tab_buf);
  if (error == -84)
    return 0;
  return error;
}
