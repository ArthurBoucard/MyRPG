/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** music_stop
*/

#include "my.h"

void music_stop(all_t *all)
{
    sfMusic_stop(all->mu_castle);
    sfMusic_stop(all->mu_battle);
    sfMusic_stop(all->mu_intro);
    sfMusic_stop(all->mu_cave);
    sfMusic_stop(all->mu_boss_battle);
}