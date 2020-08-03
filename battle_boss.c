/*
** EPITECH PROJECT, 2020
** my _rpg
** File description:
** boss
*/

#include "my.h"

sfVector2f pos_fight_boss = {430, 820};

int action_b(all_t *all, int act)
{
    int i;

    if (act == 0) {
        i = p_attack_b(all);
        if (i == 84)
            return 8;
        sfClock_restart(all->clock_fight);
        while (sfClock_getElapsedTime(all->clock_fight).microseconds
            <= 1000000);
        i = m_attack_b(all);
        if (i == 84)
            return 7;
        return 0;
    } else if (act == 1)
        if ((rand() % 3) == 1)
            return 84;
        else
            i = m_attack_b(all);
            if (i == 84)
                return 7;
    return 0;
}

int selection_b(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue &&
        pos_fight_boss.x != 810)
        pos_fight_boss.x += 380;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue &&
        pos_fight_boss.x != 430)
        pos_fight_boss.x -= 380;
    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) {
        if (pos_fight_boss.x == 430)
            return action_b(all, 0);
        else if (pos_fight_boss.x == 810)
            return action_b(all, 1);
    }
    return 0;
}

void test_return_boss(all_t *all, int i)
{
    if (i == 7) {
        music_stop(all);
        sfRenderWindow_clear(all->window, sfBlack);
        make_all_map(all);
        game_cave(all);
    } else if (i == 8) {
        music_stop(all);
        sfMusic_play(all->mu_castle);
        sfMusic_setLoop(all->mu_castle, sfTrue);
        sfRenderWindow_clear(all->window, sfBlack);
        sfRenderWindow_drawSprite(all->window, all->s_endgame, NULL);
        sfRenderWindow_display(all->window);
        while (sfKeyboard_isKeyPressed(sfKeyEnter) == sfFalse);
        menu(all);
    }
    sfClock_restart(all->clock_fight);
}

void setup_boss(all_t *all)
{
    sfMusic_play(all->mu_boss_battle);
    sfMusic_setLoop(all->mu_boss_battle, sfTrue);
    battle_set_pos_boss(all);
    sfClock_restart(all->clock_fight);
    all->m_life = all->m_life_f;
}

int battle_boss(all_t *all)
{
    int i = 0;

    setup_boss(all);
    while (i == 0) {
        while (sfRenderWindow_pollEvent(all->window, &all->event))
            i = close_win(all);
        if (i == 4)
            return (84);
        if (i == 3)
            i = 0;
        battle_draw_boss(all);
        sfRenderWindow_drawSprite(all->window, all->s_boss, NULL);
        if (sfClock_getElapsedTime(all->clock_fight).microseconds >= 100000) {
            i = selection_b(all);
            test_return_boss(all, i);
        }
        sfSprite_setPosition(all->s_fight_select, pos_fight_boss);
        sfRenderWindow_display(all->window);
    }
    sfMusic_stop(all->mu_battle);
    sfRenderWindow_clear(all->window, sfBlack);
}