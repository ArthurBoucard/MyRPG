/*
** EPITECH PROJECT, 2019
** create_window
** File description:
** window
*/

#include "my.h"

sfRenderWindow *create_my_window(int a, int b)
{
    sfRenderWindow *window;
    sfVideoMode mode = {a, b, 32};

    window = sfRenderWindow_create(mode, "My_Rpg", sfDefaultStyle, NULL);
    return (window);
}
