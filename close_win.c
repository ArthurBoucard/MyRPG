/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** close window
*/

#include "my.h"

int close_win(all_t *all)
{
    if (all->event.type == sfEvtClosed) {
        sfRenderWindow_close(all->window);
        return (4);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDelete) == sfTrue) {
        sfRenderWindow_close(all->window);
        return (4);
    }
    return (0);
}
