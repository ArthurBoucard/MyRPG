/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** int_to_str
*/

#include <stdlib.h>

char *int_to_str(int nb)
{
    int nb_cp = nb;
    int i = 0;
    char *str;

    for (; nb_cp != 0; nb_cp /= 10, i++);
    str = malloc(sizeof(char) * i);
    str[i] = '\0';
    for (i-- ; nb > 0; i--) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
    }
    return str;
}