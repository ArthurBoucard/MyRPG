/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_actions
*/

#include "my.h"

sfVector2f pos_bulle = {500, 800};

char verif_next_char(all_t *all, char **map)
{
    int i = 0;
    int j = 0;

    for (; map[i][j] != 'P'; j++) {
        if (map[i][j] == '\n') {
            i++;
            j = 0;
        }
    }
    if (all->facing == 1)
        return map[i][j + 1];
    else if (all->facing == 2)
        return map[i][j - 1];
    if (all->facing == 3)
        return map[i + 1][j];
    else if (all->facing == 4)
        return map[i - 1][j];
}

const char *verif_obj2(all_t *all, char obj)
{
    if (obj == 'L')
        return "Lucas la Terreur:\n\tJe me serais volontiers occupe de ces \
putrelles, mais j'ai joute la.";
    else if (obj == 'W')
        return "Clara l'Inocente:\n\tXi wo jiba.";
    if (obj == 'H') {
        all->life = all->life_f;
        return "Guerisseuse:\n\tVous voila comme neuf.";
    } else if (obj == 'M') {
        battle_boss(all);
        return NULL;
    } else
        return NULL;
}

const char *verif_obj(all_t *all, char obj)
{
    if (obj == 'S')
        return "Souheil le Tavernier:\n\tQui voudrait aller a la Kolok \
ce soir ?";
    else if (obj == 'B')
        return "Basile le Paume:\n\tEst-ce que c'est moitie prix a la Kolok du \
coup pour le deuil ?";
    if (obj == 'C')
        return "Camille la Machine de Guerre:\n\tAttention, je vais courir !";
    else if (obj == 'T')
        return "Thibault le Voyageur:\n\tA cause de ca j'ai rate ma caleche";
    if (obj == 'Y')
        return "Aymeric le Bagarreur:\n\tHey les gars, qui est chaud pour se \
marquer au fer rouge avec moi ?";
    else if (obj == 'A')
        return "Bouboule le Pignouf:\n\tIls cassent les baloches a voler \
la princess eux !";
    else
    return verif_obj2(all, obj);
}

int actions(all_t *all, char **map)
{
    char obj = verif_next_char(all, map);
    int i = 0;
    const char *txt;

    sfSprite_setPosition(all->s_bulle, pos_bulle);
    if ((txt = verif_obj(all, obj)) != NULL) {
        while ((sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse &&
                sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse &&
                sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse &&
                sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse) || i == 1) {
            while (sfRenderWindow_pollEvent(all->window, &all->event))
                i = close_win(all);
            if (i == 4)
                return (84);
            sfRenderWindow_drawSprite(all->window, all->s_bulle, NULL);
            set_string(all, txt);
            sfRenderWindow_drawText(all->window, all->text, NULL);
            sfRenderWindow_display(all->window);
            }
        }
}