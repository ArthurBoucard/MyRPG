/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** sound create
*/

#include "my.h"

void create_sound(all_t *all)
{
    all->mu_menu = sfMusic_createFromFile("data/music/menu.ogg");
    all->mu_battle = sfMusic_createFromFile("data/music/battle.ogg");
    all->mu_intro = sfMusic_createFromFile("data/music/intro.ogg");
    all->mu_castle = sfMusic_createFromFile("data/music/castle.ogg");
    all->mu_boss_battle = sfMusic_createFromFile("data/music/boss_battle.ogg");
    all->mu_cave = sfMusic_createFromFile("data/music/cave.ogg");
    all->sb_first_battle =
        sfSoundBuffer_createFromFile("data/sound/first_battle.ogg");
    all->sd_first_battle = sfSound_create();
    sfSound_setBuffer(all->sd_first_battle, all->sb_first_battle);
}
