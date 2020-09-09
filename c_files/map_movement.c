/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_movement
*/

#include "my.h"

void find_player(char **map, int *pos)
{
    int i = 0;
    int j = 0;

    for (; map[i][j] != 'P'; j++) {
        if (map[i][j] == '\n') {
            i++;
            j = 0;
        }
    }
    pos[0] = i;
    pos[1] = j;
}

int verif_char(all_t *all, char pos)
{
    if (pos == '.')
        return 0;
    else if (pos == '!') {
        if ((rand() % 10) == 1) {
            sfMusic_stop(all->mu_cave);
            battle(all);
            sfMusic_play(all->mu_castle);
            sfMusic_setLoop(all->mu_castle, sfTrue);
        }
        return 0;
    }
    if (pos == 'G') {
        all->go_cave = pos;
        return 0;
    } else if (pos == 'E'){
        all->go_cave = pos;
        return 0;
    } else
        return 84;
}

void move_player_txt(int *old_pos, int new_pos1, int new_pos2, all_t *all)
{
    if (all->which_map == 1) {
        all->map1[old_pos[0]][old_pos[1]] = all->last_case;
        all->map1[new_pos1][new_pos2] = 'P';
    } else if (all ->which_map == 2) {
        all->map2[old_pos[0]][old_pos[1]] = all->last_case;
        all->map2[new_pos1][new_pos2] = 'P';
    }
}

int test_move2(all_t *all, int dir, int *pos, char **map)
{
    if (dir == 3) {
        all->char_val = verif_char(all, map[pos[0] + 1][pos[1]]);
        if (all->char_val == 0)
            move_player_txt(pos, pos[0] + 1, pos[1], all);
    } else if (dir == 4) {
        all->char_val = verif_char(all, map[pos[0] - 1][pos[1]]);
        if (all->char_val == 0)
            move_player_txt(pos, pos[0] - 1, pos[1], all);
    }
    return all->char_val;
}

int test_move(all_t *all, int dir, char **map)
{
    int pos[2];

    find_player(map, pos);
    if (dir == 1) {
        all->char_val = verif_char(all, map[pos[0]][pos[1] + 1]);
        if (all->char_val == 0)
            move_player_txt(pos, pos[0], pos[1] + 1, all);
    } else if (dir == 2) {
        all->char_val = verif_char(all, map[pos[0]][pos[1] - 1]);
        if (all->char_val == 0)
            move_player_txt(pos, pos[0], pos[1] - 1, all);
    } else
        all->char_val = test_move2(all, dir, pos, map);
    return all->char_val;
}