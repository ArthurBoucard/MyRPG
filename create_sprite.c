/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** create sprite
*/

#include "my.h"

void create_sprite(all_t *all)
{
    all->s_map = sfSprite_create();
    all->s_map2 = sfSprite_create();
    all->s_pause = sfSprite_create();
    all->s_player = sfSprite_create();
    all->s_battle = sfSprite_create();
    all->s_menu = sfSprite_create();
    all->s_bigplayer = sfSprite_create();
    all->s_bulle = sfSprite_create();
    all->s_first_battle = sfSprite_create();
    all->s_croco = sfSprite_create();
    all->s_fight_menu = sfSprite_create();
    all->s_fight_select = sfSprite_create();
    all->s_cave = sfSprite_create();
    all->s_life_bar = sfSprite_create();
    all->s_life_bar_e = sfSprite_create();
    all->s_setcmd = sfSprite_create();
    all->s_setcombat = sfSprite_create();
    all->s_boss = sfSprite_create();
    all->s_endgame = sfSprite_create();
}