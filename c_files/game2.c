/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game2
*/

#include "my.h"

void game_cave_start(all_t *all)
{
    all->which_map = 2;
    sfMusic_stop(all->mu_castle);
    sfMusic_play(all->mu_cave);
    sfMusic_setLoop(all->mu_cave, sfTrue);
}

void game_cave_end(all_t *all, sfVector2f pos_map2)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        actions(all, all->map2);
    sfSprite_setPosition(all->s_map2, pos_map2);
    sfRenderWindow_clear(all->window, sfBlack);
    set_rect(all);
    draw_sprites_cave(all);
    sfRenderWindow_display(all->window);
}

void game_start(all_t *all)
{
    music_stop(all);
    sfMusic_play(all->mu_castle);
    sfMusic_setLoop(all->mu_castle, sfTrue);
}

void game_end(all_t *all, sfVector2f pos_map)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        actions(all, all->map1);
    sfSprite_setPosition(all->s_map, pos_map);
    sfRenderWindow_clear(all->window, sfBlack);
    set_rect(all);
    draw_sprites(all);
    sfRenderWindow_display(all->window);
}