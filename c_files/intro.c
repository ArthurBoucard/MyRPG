/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** intro
*/

#include "my.h"

sfVector2f pos_bulle_intro = {500, 800};

void first_battle(all_t *all)
{
    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_drawSprite(all->window, all->s_battle, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_first_battle, NULL);
    sfRenderWindow_drawSprite(all->window, all->s_bulle, NULL);
    set_string(all, "\tVous et le reste de la garde decidez de lancer un \
\nassaut contre les ogres. Malheureusement, les ogres etant\nbien plus \
nombreux et prepare que vous, n'ont eu aucun mal a contrer votre attaque.");
    sfRenderWindow_drawText(all->window, all->text, NULL);
    sfRenderWindow_display(all->window);
}

void draw_intro(all_t *all, int i)
{
    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_drawSprite(all->window, all->s_bulle, NULL);
    set_string(all, which_txt(all, i));
    sfRenderWindow_drawText(all->window, all->text, NULL);
    sfRenderWindow_display(all->window);
}

void intro(all_t *all)
{
    all->intro = 1;
    sfMusic_play(all->mu_intro);
    sfMusic_setLoop(all->mu_intro, sfTrue);
    sfClock_restart(all->clock_intro);
    sfSprite_setPosition(all->s_bulle, pos_bulle_intro);
    while (sfRenderWindow_isOpen(all->window)) {
        while (sfRenderWindow_pollEvent(all->window, &all->event))
            close_win(all);
        for (int i = 0; i <= 11;) {
            draw_intro(all, i);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
            sfClock_getElapsedTime(all->clock_intro).microseconds >= 500000) {
                i++;
                sfClock_restart(all->clock_intro);
            }
        }
        sfMusic_stop(all->mu_intro);
        make_all_map(all);
        game(all);
    }
}