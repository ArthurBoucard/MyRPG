/*
** EPITECH PROJECT, 2019
** fullwindow
** File description:
** window
*/

#include "my.h"

sfRenderWindow *create_my_fullwindow(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {100, 100, 32};

    window = sfRenderWindow_create(mode, "SFML window", sfFullscreen, NULL);
    return (window);
}
