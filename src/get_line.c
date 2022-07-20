/*
** EPITECH PROJECT, 2020
** Matchstick
** File description:
** get_line.c
*/

#include "libmy.h"

int line_confirm(int i, char *line, int nb)
{
    if (line[i] >= '1' && line[i] <= '9')
        if (my_getnbr(line) <= nb && my_getnbr(line) >= 1)
            return 0;
        else {
                write(1, "Error: this line is out of range\n", 33);
                return (-1);
            }
    else {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (-1);
    }
}

int get_line(int nb)
{
    int bytes_read;
    size_t nbytes = 100;
    char *line = (char *) malloc (nbytes + 1);
    int buf = 0;

    write(1, "Line: ", 6);
    bytes_read = getline(&line, &nbytes, stdin);
    if (bytes_read == -1)
        return -84;
    for (int i = 0; i != 2; i++) {
        buf = line_confirm(i, line, nb);
        if (buf == 0)
            break;
        if (buf == -1)
            return (-1);
    }
    buf = my_getnbr(line) - 1;
    free(line);
    return (buf);
}

int match_confirm(int i, char *match, int y)
{
    if (match[i] >= '0' && match[i] <= '9') {
        if (my_getnbr(match) <= y && my_getnbr(match) >= 1)
            return (0);
        if (my_getnbr(match) == 0) {
            write(1, "Error: you have to remove at least one match\n", 45);
            return (-1);
        } else {
            write(1, "Error: not enough matches on this line\n", 39);
            return (-1);
        }
    } else {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (-1);
    }
}

int get_match(int y)
{
    int bytes_read;
    size_t nbytes = 100;
    char *match = (char *) malloc (nbytes + 1);
    int buf;

    write(1, "Matches: ", 9);
    bytes_read = getline(&match, &nbytes, stdin);
    if (bytes_read == -1)
        return -84;
    for (int i = 0; i != 2; i++) {
        buf = match_confirm(i, match, y);
        if (buf == 0)
            break;
        if (buf == -1)
            return (-1);
    }
    buf = my_getnbr(match);
    free(match);
    return (buf);
}
