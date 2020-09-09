/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** mouve rect
*/

#include "my.h"
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

int move_player(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock_player);
    float seconde = time.microseconds / 1000000.0;

    if (seconde > 0.2) {
        all->rect_player.left = all->rect_player.left + 63;
        if (all->rect_player.left > 130) {
            all->rect_player.left = 0;
        }
        sfClock_restart(all->clock_player);
    }
    return (0);
}