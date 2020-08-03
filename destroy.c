/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** destruct 1
*/

#include "my.h"

void destroy(all_t *all)
{
    sfMusic_destroy(all->mu_menu);
    sfMusic_destroy(all->mu_battle);
    sfMusic_destroy(all->mu_intro);
    sfMusic_destroy(all->mu_castle);
    sfMusic_destroy(all->mu_cave);
    sfMusic_destroy(all->mu_boss_battle);
    sfSound_destroy(all->sd_first_battle);
    sfSoundBuffer_destroy(all->sb_first_battle);
}