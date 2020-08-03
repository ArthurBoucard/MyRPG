/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** lib
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct all
{
    sfRenderWindow *window;
    sfEvent event;

    sfTexture *t_map;
    sfSprite *s_map;
    sfTexture *t_map2;
    sfSprite *s_map2;

    sfTexture *t_pause;
    sfSprite *s_pause;

    sfTexture *t_battle;
    sfSprite *s_battle;

    sfTexture *t_boss;
    sfSprite *s_boss;

    sfTexture *t_menu;
    sfSprite *s_menu;
    sfMusic *mu_menu;
    sfTexture *t_setcmd;
    sfSprite *s_setcmd;
    sfTexture *t_setcombat;
    sfSprite *s_setcombat;

    sfTexture *t_intro1;
    sfSprite *s_intro1;
    sfMusic *mu_intro;
    sfClock *clock_intro;

    sfTexture *t_first_battle;
    sfSprite *s_first_battle;

    sfMusic *mu_battle;
    sfMusic *mu_boss_battle;
    sfMusic *mu_castle;
    sfMusic *mu_cave;

    sfTexture *t_player;
    sfSprite *s_player;
    sfIntRect rect_player;
    sfClock *clock_player;
    sfClock *clock_mvt;
    int facing;
    int life_f;
    int life;

    sfTexture *t_bigplayer;
    sfSprite *s_bigplayer;
    sfTexture *t_croco;
    sfSprite *s_croco;
    sfTexture *t_fight_menu;
    sfSprite *s_fight_menu;
    sfTexture *t_fight_select;
    sfSprite *s_fight_select;
    sfTexture *t_life_bar;
    sfSprite *s_life_bar;
    sfTexture *t_life_bar_e;
    sfSprite *s_life_bar_e;
    sfClock *clock_fight;
    int m_life_f;
    int m_life;
    int b_life_f;
    int b_life;

    sfTexture *t_endgame;
    sfSprite *s_endgame;

    sfClock *clock_set;

    sfTexture *t_cave;
    sfSprite *s_cave;

    char **map1;
    char **map2;
    char last_case;
    int char_val;
    int which_map;
    char go_cave;

    sfText *text;
    sfText *text_win;
    sfText *text_life_p;
    sfText *text_life_e;
    sfFont *font;
    sfTexture *t_bulle;
    sfSprite *s_bulle;

    sfSound *sd_first_battle;
    sfSoundBuffer *sb_first_battle;

    int intro;
    int commande;
    int frappe;
    int setings;
}all_t;

sfRenderWindow *create_my_fullwindow(void);
sfRenderWindow *create_my_window(int a, int b);

int menu(all_t *all);
int close_win(all_t *all);
int menu_pause(all_t *all, sfSprite *sprite);
void game(all_t *all);
int move_player(all_t *all);
int test_move(all_t *all, int dir, char **map);
int actions(all_t *all, char **map);
int battle (all_t *all);
void first_battle(all_t *all);
void intro(all_t *all);
const char *which_txt(all_t *all, int i);
int p_attack(all_t *all);
int m_attack(all_t *all);
void make_all_map(all_t *all);
int selection(all_t *all);
int battle_boss(all_t *all);
int p_attack_b(all_t *all);
int m_attack_b(all_t *all);
void game_cave(all_t *all);

void create_texture(all_t *all);
void create_sprite(all_t *all);
void create_rect(all_t *all);
void create_txt(all_t *all);
void create_sound(all_t *all);
void set_texture(all_t *all);
void draw_sprites(all_t *all);
void set_rect(all_t *all);
void create(all_t *all);
void set_string(all_t *all, const char *txt);
void battle_draw(all_t *all);
void battle_draw_boss(all_t *all);
void battle_set_pos(all_t *all);
void battle_set_pos_boss(all_t *all);
void draw_sprites_cave(all_t *all);
void game_start(all_t *all);
void game_end(all_t *all, sfVector2f pos_map);
void game_cave_start(all_t *all);
void game_cave_end(all_t *all, sfVector2f pos_map2);

void music_stop(all_t *all);
void destroy(all_t *all);

void my_putstr(char const *str);
char *my_revstr(char *str);
char *my_return_nbr(int nb);
int my_strlen(char const *str);
char *int_to_str(int nb);