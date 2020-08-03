/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** battle
*/

#include "my.h"

sfVector2f pos_fight_s = {430, 820};
sfVector2f pos_bull_win = {500, 800};

int action(all_t *all, int act)
{
    int i;

    if (act == 0) {
        i = p_attack(all);
        if (i == 84)
            return 8;
        sfClock_restart(all->clock_fight);
        while (sfClock_getElapsedTime(all->clock_fight).microseconds
            <= 1000000);
        i = m_attack(all);
        if (i == 84)
            return 7;
        return 0;
    } else if (act == 1)
        if ((rand() % 3) == 1)
            return 84;
        else
            i = m_attack(all);
            if (i == 84)
                return 7;
    return 0;
}

int selection(all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue &&
        pos_fight_s.x != 810)
        pos_fight_s.x += 380;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue &&
        pos_fight_s.x != 430)
        pos_fight_s.x -= 380;
    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) {
        if (pos_fight_s.x == 430)
            return action(all, 0);
        else if (pos_fight_s.x == 810)
            return action(all, 1);
    }
    return 0;
}

int return_test(all_t *all, int i)
{
    i = selection(all);
    if (i == 7) {
        music_stop(all);
        sfRenderWindow_clear(all->window, sfBlack);
        make_all_map(all);
        game_cave(all);
    } else if (i == 8) {
        sfSprite_setPosition(all->s_bulle, pos_bull_win);
        sfRenderWindow_drawSprite(all->window, all->s_bulle, NULL);
        set_string(all, "\tBravo, vous obtenez +5 PV !");
        sfRenderWindow_drawText(all->window, all->text_win, NULL);
        sfRenderWindow_display(all->window);
        sfClock_restart(all->clock_fight);
        while (sfClock_getElapsedTime(all->clock_fight).microseconds
            <= 1000000);
        all->life_f += 5;
        all->life += 5;
    }
    sfClock_restart(all->clock_fight);
    return i;
}

void setup(all_t *all)
{
    music_stop(all);
    sfMusic_play(all->mu_battle);
    sfMusic_setLoop(all->mu_battle, sfTrue);
    battle_set_pos(all);
    sfClock_restart(all->clock_fight);
    all->m_life = all->m_life_f;
}

int battle(all_t *all)
{
    int i = 0;

    setup(all);
    while (i == 0) {
        while (sfRenderWindow_pollEvent(all->window, &all->event))
            i = close_win(all);
        if (i == 4)
            return (84);
        if (i == 3)
            i = 0;
        battle_draw(all);
        sfRenderWindow_drawSprite(all->window, all->s_croco, NULL);
        if (sfClock_getElapsedTime(all->clock_fight).microseconds >= 100000) {
            i = return_test(all, i);
        }
        sfSprite_setPosition(all->s_fight_select, pos_fight_s);
        sfRenderWindow_display(all->window);
    }
    sfMusic_stop(all->mu_battle);
    sfRenderWindow_clear(all->window, sfBlack);
}
