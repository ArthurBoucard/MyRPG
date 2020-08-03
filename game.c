/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_map
*/

#include "my.h"

sfVector2f pos_map = {-3250, -2200};
sfVector2f pos_map2 = {-400, 300};
sfVector2f pos_player = {850, 500};

void mouse_event2(all_t *all, char **map, int nb)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        all->rect_player.top = 0;
        all->facing = 3;
        if (test_move(all, 3, map) == 0) {
            if (nb == 1)
                pos_map.y = pos_map.y - 90;
            else
                pos_map2.y = pos_map2.y - 90;
            move_player(all);
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        all->rect_player.top = 186;
        all->facing = 4;
        if (test_move(all, 4, map) == 0) {
            if (nb == 1)
                pos_map.y = pos_map.y + 90;
            else
                pos_map2.y = pos_map2.y + 90;
            move_player(all);
        }
    }
}

void mouse_event(all_t *all, char **map, int nb)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        all->rect_player.top = 124;
        all->facing = 1;
        if (test_move(all, 1, map) == 0) {
            if (nb == 1)
                pos_map.x = pos_map.x - 90;
            else
                pos_map2.x = pos_map2.x - 90;
            move_player(all);
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        all->rect_player.top = 62;
        all->facing = 2;
        if (test_move(all, 2, map) == 0) {
            if (nb == 1)
                pos_map.x = pos_map.x + 90;
            else
                pos_map2.x = pos_map2.x + 90;
            move_player(all);
        }
    } else
        mouse_event2(all, map, nb);
}

void game_cave(all_t *all)
{
    game_cave_start(all);
    pos_map2.x = -400;
    pos_map2.y = 300;
    all->life = all->life_f;
    while (sfRenderWindow_isOpen(all->window)) {
        while (sfRenderWindow_pollEvent(all->window, &all->event)) {
            close_win(all);
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
                menu_pause(all, all->s_map2);
        }
        if (sfClock_getElapsedTime(all->clock_mvt).microseconds >= 100000) {
            mouse_event(all, all->map2, 2);
            sfClock_restart(all->clock_mvt);
            if (all->go_cave == 'E') {
                music_stop(all);
                return;
            }
        }
        game_cave_end(all, pos_map2);
    }
}

void game(all_t *all)
{
    game_start(all);
    sfSprite_setPosition(all->s_player, pos_player);
    pos_map.x = -3250;
    pos_map.y = -2200;
    while (sfRenderWindow_isOpen(all->window)) {
        while (sfRenderWindow_pollEvent(all->window, &all->event)) {
            close_win(all);
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
                menu_pause(all, all->s_map);
        }
        if (sfClock_getElapsedTime(all->clock_mvt).microseconds >= 100000) {
            mouse_event(all, all->map1, 1);
            sfClock_restart(all->clock_mvt);
            if (all->go_cave == 'G') {
                all->go_cave == 'x';
                game_cave(all);
            }
        }
        game_end(all, pos_map);
    }
}