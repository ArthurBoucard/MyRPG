/*
** EPITECH PROJECT, 2020
** defenders
** File description:
** menu
*/

#include "my.h"

sfVector2f pos_mouse = {0.00, 0.00};

int settings(all_t *all)
{
    int i = 0;

    all->setings = 1;
    pos_mouse.y = 800.0;
    while (sfClock_getElapsedTime(all->clock_set).microseconds < 500000);
    sfClock_restart(all->clock_set);
    while (i == 0) {
        while (sfRenderWindow_pollEvent(all->window, &all->event)) {
            i = close_win(all);
        }
        if (i == 4)
            return (84);
        sfRenderWindow_clear(all->window, sfBlack);
        if (all->setings == 1) {
            sfRenderWindow_drawSprite(all->window, all->s_setcmd, NULL);
        } else {
            sfRenderWindow_drawSprite(all->window, all->s_setcombat, NULL);
        }
        sfRenderWindow_display(all->window);
        pos_mouse.x = all->event.mouseButton.x;
        pos_mouse.y = all->event.mouseButton.y;
        if (pos_mouse.x > 55 && pos_mouse.x < 150 &&
        pos_mouse.y > 50 && pos_mouse.y < 185)
            return 0;
        if (sfClock_getElapsedTime(all->clock_set).microseconds > 1000000 &&
        pos_mouse.x > 1500 && pos_mouse.x < 1880 &&
        pos_mouse.y > 900 && pos_mouse.y < 1025) {
            all->setings = all->setings * (-1);
            sfClock_restart(all->clock_set);
        }
    }
    return 0;
}

int mouse_menu(all_t *all)
{
    pos_mouse.x = all->event.mouseButton.x;
    pos_mouse.y = all->event.mouseButton.y;
    if (pos_mouse.x > 780 && pos_mouse.x < 1200 &&
    pos_mouse.y > 780 && pos_mouse.y < 950) {
        sfMusic_stop(all->mu_menu);
        if (all->intro == 0) {
            intro(all);
        } else {
            make_all_map(all);
            game(all);
        }
        return 1;
    }
    if (pos_mouse.x > 1590 && pos_mouse.x < 1720 &&
    pos_mouse.y > 30 && pos_mouse.y < 170) {
        sfMusic_stop(all->mu_menu);
        sfClock_restart(all->clock_set);
        return settings(all);
    }
    if (pos_mouse.x > 1750 && pos_mouse.x < 1860 &&
    pos_mouse.y > 30 && pos_mouse.y < 170) {
        sfMusic_stop(all->mu_menu);
        sfRenderWindow_close(all->window);
        return 4;
    }
    return 0;
}

int menu(all_t *all)
{
    int i = 0;

    music_stop(all);
    sfMusic_play(all->mu_menu);
    sfMusic_setLoop(all->mu_menu, sfTrue);
    while (i == 0) {
        while (sfRenderWindow_pollEvent(all->window, &all->event)) {
            i = close_win(all);
        }
        if (i == 4)
            return (84);
        sfRenderWindow_clear(all->window, sfBlack);
        sfRenderWindow_drawSprite(all->window, all->s_menu, NULL);
        i = mouse_menu(all);
        sfRenderWindow_display(all->window);
    }
    return (i);
}