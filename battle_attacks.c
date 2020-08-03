/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle_attacks
*/

#include "my.h"

sfVector2f pos_p_attack = {450, 450};
sfVector2f pos_e_attack = {1200, 520};

int m_attack(all_t *all)
{
    sfSprite_setColor(all->s_bigplayer, sfRed);
    sfSprite_setPosition(all->s_croco, pos_e_attack);
    battle_draw(all);
    sfRenderWindow_display(all->window);
    sfClock_restart(all->clock_fight);
    while (sfClock_getElapsedTime(all->clock_fight).microseconds <= 1000000);
    battle_set_pos(all);
    sfSprite_setColor(all->s_bigplayer, sfWhite);
    all->life -= ((100 + all->m_life_f) / 20) * ((rand() % 2) + 1);
    if (all->life <= 0)
        return 84;
    battle_draw(all);
    sfRenderWindow_display(all->window);
    return 0;
}

int p_attack(all_t *all)
{
    sfSprite_setColor(all->s_croco, sfRed);
    sfSprite_setPosition(all->s_bigplayer, pos_p_attack);
    battle_draw(all);
    sfRenderWindow_display(all->window);
    sfClock_restart(all->clock_fight);
    while (sfClock_getElapsedTime(all->clock_fight).microseconds <= 1000000);
    battle_set_pos(all);
    sfSprite_setColor(all->s_croco, sfWhite);
    all->m_life -= ((all->life_f + all->m_life_f) / 20) * ((rand() % 2) + 1);
    if (all->m_life <= 0)
        return 84;
    battle_draw(all);
    sfRenderWindow_display(all->window);
    return 0;
}

int m_attack_b(all_t *all)
{
    sfSprite_setColor(all->s_bigplayer, sfRed);
    sfSprite_setPosition(all->s_boss, pos_e_attack);
    battle_draw_boss(all);
    sfRenderWindow_display(all->window);
    sfClock_restart(all->clock_fight);
    while (sfClock_getElapsedTime(all->clock_fight).microseconds <= 1000000);
    battle_set_pos_boss(all);
    sfSprite_setColor(all->s_bigplayer, sfWhite);
    all->life -= ((100 + all->b_life_f) / 20) * ((rand() % 2) + 1);
    if (all->life <= 0)
        return 84;
    battle_draw_boss(all);
    sfRenderWindow_display(all->window);
    return 0;
}

int p_attack_b(all_t *all)
{
    sfSprite_setColor(all->s_boss, sfRed);
    sfSprite_setPosition(all->s_bigplayer, pos_p_attack);
    battle_draw_boss(all);
    sfRenderWindow_display(all->window);
    sfClock_restart(all->clock_fight);
    while (sfClock_getElapsedTime(all->clock_fight).microseconds <= 1000000);
    battle_set_pos_boss(all);
    sfSprite_setColor(all->s_boss, sfWhite);
    all->b_life -= ((all->life_f + all->m_life_f) / 20) * ((rand() % 2) + 1);
    if (all->b_life <= 0)
        return 84;
    battle_draw_boss(all);
    sfRenderWindow_display(all->window);
    return 0;
}