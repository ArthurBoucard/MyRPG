/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create texture
*/

#include "my.h"

void create_texture2(all_t *all)
{
    all->t_life_bar = sfTexture_createFromFile("data/life_bar.png", NULL);
    all->t_life_bar_e = sfTexture_createFromFile("data/life_bar.png", NULL);
    all->t_setcmd = sfTexture_createFromFile("data/settings_cmd.png", NULL);
    all->t_boss = sfTexture_createFromFile("data/gringork.png", NULL);
    all->t_setcombat = sfTexture_createFromFile("data/settings_combat.png",
        NULL);
    all->t_endgame = sfTexture_createFromFile("data/bg/endgame.png", NULL);
}

void create_texture(all_t *all)
{
    all->t_map = sfTexture_createFromFile("data/bg/map_city_rpg.png", NULL);
    all->t_map2 = sfTexture_createFromFile("data/bg/map_cave.jpg", NULL);
    all->t_pause = sfTexture_createFromFile("data/bg/pause-menu.png", NULL);
    all->t_player = sfTexture_createFromFile("data/player.png", NULL);
    all->t_battle = sfTexture_createFromFile("data/bg/battle_test.png", NULL);
    all->t_menu = sfTexture_createFromFile("data/bg/menu_rpg.png", NULL);
    all->t_bigplayer = sfTexture_createFromFile("data/bigplayer.png", NULL);
    all->t_bulle = sfTexture_createFromFile("data/bulle.png", NULL);
    all->t_first_battle = sfTexture_createFromFile("data/first_battle.png",
        NULL);
    all->t_croco = sfTexture_createFromFile("data/croco.png", NULL);
    all->t_fight_menu = sfTexture_createFromFile("data/fight_menu.png", NULL);
    all->t_fight_select = sfTexture_createFromFile("data/fight_sel.png", NULL);
    all->t_cave = sfTexture_createFromFile("data/bg/cave_bg.jpg", NULL);
    create_texture2(all);
}