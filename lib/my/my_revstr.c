/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse
*/

#include <stdlib.h>
#include "my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    int j = 0;
    char *res = malloc(sizeof(char) * i);

    i = i - 1;
    while (i > -1) {
        res[j] = str[i];
        i = i - 1;
        j = j + 1;
    }
    return (res);
}
