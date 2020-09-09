/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** set texture
*/

#include "my.h"

void set_texture(all_t *all)
{
    sfSprite_setTexture(all->s_map, all->t_map, sfTrue);
    sfSprite_setTexture(all->s_map2, all->t_map2, sfTrue);
    sfSprite_setTexture(all->s_pause, all->t_pause, sfTrue);
    sfSprite_setTexture(all->s_player, all->t_player, sfTrue);
    sfSprite_setTexture(all->s_battle, all->t_battle, sfTrue);
    sfSprite_setTexture(all->s_menu, all->t_menu, sfTrue);
    sfSprite_setTexture(all->s_bigplayer, all->t_bigplayer, sfTrue);
    sfSprite_setTexture(all->s_bulle, all->t_bulle, sfTrue);
    sfSprite_setTexture(all->s_first_battle, all->t_first_battle, sfTrue);
    sfSprite_setTexture(all->s_croco, all->t_croco, sfTrue);
    sfSprite_setTexture(all->s_fight_menu, all->t_fight_menu, sfTrue);
    sfSprite_setTexture(all->s_fight_select, all->t_fight_select, sfTrue);
    sfSprite_setTexture(all->s_cave, all->t_cave, sfTrue);
    sfSprite_setTexture(all->s_life_bar, all->t_life_bar, sfTrue);
    sfSprite_setTexture(all->s_life_bar_e, all->t_life_bar_e, sfTrue);
    sfSprite_setTexture(all->s_setcmd, all->t_setcmd, sfTrue);
    sfSprite_setTexture(all->s_setcombat, all->t_setcombat, sfTrue);
    sfSprite_setTexture(all->s_boss, all->t_boss, sfTrue);
    sfSprite_setTexture(all->s_endgame, all->t_endgame, sfTrue);
}