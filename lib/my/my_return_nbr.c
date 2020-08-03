/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** int -> str
*/

#include "my.h"
#include <stdlib.h>

char *my_return_nbr(int nb)
{
    char *str = malloc(sizeof(char) *4);
    int i = 0;

    while (i > -1) {
        if (nb < 10) {
            str[i] = nb + 48;
            return (my_revstr(str));
        } else {
            str[i] = nb % 10 + 48;
            i = i + 1;
            nb = nb / 10;
        }
    }
}
