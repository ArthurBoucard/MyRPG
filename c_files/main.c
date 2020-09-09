/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** hunter
*/

#include "my.h"

void make_all_map(all_t *all)
{
    int fd1 = open("./map_txt/map1.txt", O_RDWR);
    int fd2 = open("./map_txt/map2.txt", O_RDWR);

    all->map1 = malloc(sizeof(char *) * 33);
    for (int i = 0; i < 33; all->map1[i] = malloc(sizeof(char) * 45), i++);
    for (int i = 0; i < 33; read(fd1, all->map1[i], 44), i++);
    all->map2 = malloc(sizeof(char *) * 33);
    for (int i = 0; i < 32; all->map2[i] = malloc(sizeof(char) * 56), i++);
    for (int i = 0; i < 32; read(fd2, all->map2[i], 55), i++);
    all->last_case = '.';
    all->go_cave = 'x';
}

void create_all(all_t *all)
{
    all->window = create_my_window(1920, 1080);
    create_sprite(all);
    create_rect(all);
    create_sound(all);
    create_texture(all);
    create_txt(all);
    set_texture(all);
    all->clock_player = sfClock_create();
    all->clock_mvt = sfClock_create();
    all->clock_set = sfClock_create();
    all->clock_intro = sfClock_create();
    all->clock_fight = sfClock_create();
    all->life_f = 100;
    all->life = all->life_f;
    all->m_life_f = 80;
    all->m_life = all->m_life_f;
    all->b_life_f = 300;
    all->b_life = all->b_life_f;
    all->which_map = 1;
}

int main(int ac)
{
    all_t all;

    all.intro = 0;
    all.commande = 0;
    srand(time(NULL));
    make_all_map(&all);
    if (ac == 1) {
        create_all(&all);
        menu(&all);
    } else {
        return (84);
    }
    destroy(&all);
    return (0);
}