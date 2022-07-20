/*
** EPITECH PROJECT
** LibC
** File description:
** libmy.h
*/

#ifndef LIBMY_H_
#define LIBMY_H_

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int my_cat(char *filepath);
int my_compute_factorial_rec(int nb);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
char *my_evil_str(char *str);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
char *my_int_to_string(int nb);
int my_is_prime(int nb);
bool my_is_sorted(int *array, int size);
int my_isneg(int n);
void my_putchar(char c);
int my_putnbr_base(int nb, char *base);
int my_putnbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *str);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *str, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

void display_turn(int tour);
int check_tour(int tour, int nb, int y, int *matchs);
int get_line(int nb);
int get_match(int y);
int ia_match(int *matchs);
void display_ia(int line, int *matchs);
int check_case(int line, int match, int *matchs);
int *fill_tab(int nb);
void stars(int nb);
void my_print_tab(int *val, int *tab_buf, int *matchs);
void my_update_values(int *val, int *tab_buff, int *matchs);
void my_print(int nb);
void my_values(int *val, int nb);
int random_number(int max);

#endif 