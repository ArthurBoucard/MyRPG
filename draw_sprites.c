/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_sprites
*/

#include "my.h"

void set_rect(all_t *all)
{
    sfSprite_setTextureRect(all->s_player, all->rect_player);
}

void draw_sprites_cave(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->s_map2, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_player, NULL);
}

void draw_sprites(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->s_map, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_player, NULL);
}