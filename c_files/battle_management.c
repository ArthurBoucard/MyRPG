/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle_management
*/

#include "my.h"

sfVector2f pos_bigplayer = {350, 450};
sfVector2f pos_croco = {1300, 520};
sfVector2f pos_boss = {1300, 520};
sfVector2f pos_fight_m = {400, 800};
sfVector2f pos_rouge = {1400, 600};
sfVector2f pos_bleu = {40, 250};
sfVector2f pos_life_bar = {200, 300};
sfVector2f pos_life_bar_e = {1480, 440};

void battle_txt(all_t *all, int nb)
{
    const char *txt_p = int_to_str(all->life);
    const char *txt_e = int_to_str(all->m_life);
    const char *txt_b = int_to_str(all->b_life);

    sfText_setString(all->text_life_p, txt_p);
    if (nb == 0)
        sfText_setString(all->text_life_e, txt_e);
    else
        sfText_setString(all->text_life_e, txt_b);
}

void battle_set_pos_boss(all_t *all)
{
    sfRenderWindow_clear(all->window, sfBlack);
    sfSprite_setPosition(all->s_bigplayer, pos_bigplayer);
    sfSprite_setPosition(all->s_boss, pos_boss);
    sfSprite_setPosition(all->s_fight_menu, pos_fight_m);
    sfSprite_setPosition(all->s_life_bar, pos_life_bar);
    sfSprite_setPosition(all->s_life_bar_e, pos_life_bar_e);
}

void battle_set_pos(all_t *all)
{
    sfRenderWindow_clear(all->window, sfBlack);
    sfSprite_setPosition(all->s_bigplayer, pos_bigplayer);
    sfSprite_setPosition(all->s_croco, pos_croco);
    sfSprite_setPosition(all->s_fight_menu, pos_fight_m);
    sfSprite_setPosition(all->s_life_bar, pos_life_bar);
    sfSprite_setPosition(all->s_life_bar_e, pos_life_bar_e);
}

void battle_draw_boss(all_t *all)
{
    battle_txt(all, 1);
    sfRenderWindow_drawSprite(all->window, all->s_cave, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_bigplayer, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_boss, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_fight_menu, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_fight_select, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_life_bar, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_life_bar_e, NULL);
    sfRenderWindow_drawText(all->window, all->text_life_p, NULL);
    sfRenderWindow_drawText(all->window, all->text_life_e, NULL);
}

void battle_draw(all_t *all)
{
    battle_txt(all, 0);
    sfRenderWindow_drawSprite(all->window, all->s_cave, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_bigplayer, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_croco, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_fight_menu, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_fight_select, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_life_bar, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_life_bar_e, NULL);
    sfRenderWindow_drawText(all->window, all->text_life_p, NULL);
    sfRenderWindow_drawText(all->window, all->text_life_e, NULL);
}