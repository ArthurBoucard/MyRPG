/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_txt
*/

#include "my.h"

sfVector2f pos_txt = {530, 820};
sfVector2f pos_txt_win = {530, 820};
sfVector2f pos_txt_p = {210, 308};
sfVector2f pos_txt_e = {1490, 445};

void set_string(all_t *all, const char *txt)
{
    sfText_setString(all->text, txt);
    sfText_setString(all->text_win, txt);
}

void create_txt2(all_t *all)
{
    sfText_setFont(all->text_win, all->font);
    sfText_setColor(all->text_win, sfBlack);
    sfText_setCharacterSize(all->text_win, 30);
    sfText_setPosition(all->text_win, pos_txt_win);
}

void create_txt(all_t *all)
{
    all->text = sfText_create();
    all->text_win = sfText_create();
    all->text_life_p = sfText_create();
    all->text_life_e = sfText_create();
    all->font = sfFont_createFromFile("data/font/arial.otf");
    sfText_setFont(all->text, all->font);
    sfText_setColor(all->text, sfBlack);
    sfText_setCharacterSize(all->text, 30);
    sfText_setPosition(all->text, pos_txt);
    sfText_setFont(all->text_life_p, all->font);
    sfText_setColor(all->text_life_p, sfBlack);
    sfText_setCharacterSize(all->text_life_p, 30);
    sfText_setPosition(all->text_life_p, pos_txt_p);
    sfText_setFont(all->text_life_e, all->font);
    sfText_setColor(all->text_life_e, sfBlack);
    sfText_setCharacterSize(all->text_life_e, 30);
    sfText_setPosition(all->text_life_e, pos_txt_e);
    create_txt2(all);
}