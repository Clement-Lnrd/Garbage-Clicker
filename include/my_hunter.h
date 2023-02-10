/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** tekleague
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    /* Include libraries */

    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include "my_csfml.h"
    #include "my.h"

    #define UNUSE(var) (void)(var)

    ////////////////////////////////////////////////////////////
    /// \brief Macro for static const
    ///
    ////////////////////////////////////////////////////////////
    #define sc static const



    /* My Hunter struct */

// Settings structure
typedef struct {
    sfVideoMode resolution;
    int fps;
    float volume;
    int difficulty;
} settings_t;

// Title screen menu structure
typedef struct {
    sfText *title;
    sfText *play;
    sfText *stats;
    sfText *settings;
    sfText *how_to_play;
    sfText *credits;
    sfText *quit;
    sfVector2f pos_title;
    sfVector2f pos_play;
    sfVector2f pos_stats;
    sfVector2f pos_settings;
    sfVector2f pos_how_to_play;
    sfVector2f pos_credits;
    sfVector2f pos_quit;
} jam_title_screen_t;

// Play menu structure
typedef struct {
    sfText *score_;
    sfText *score;
    sfClock *clock;
    sfTexture *wand_texture;
    sfTexture *dementor_texture;
    sfSprite *wand;
    sfSprite *dementor;
    sfVector2f pos_score_;
    sfVector2f pos_score;
    sfVector2f pos_wand;
    sfIntRect wands;
    sfIntRect dementors;
} jam_play_t;

// Statistics menu structure
typedef struct {
    sfText *title;
    sfText *last_score;
    sfText *sbs;                       // Session best score
    sfText *atbs;                      // All time best score
    sfText *last_score_;
    sfText *sbs_;
    sfText *atbs_;                     // All time best score value
    sfVector2f pos_title;
    sfVector2f pos_last_score;
    sfVector2f pos_sbs;
    sfVector2f pos_atbs;
    sfVector2f pos_last_score_;
    sfVector2f pos_sbs_;
    sfVector2f pos_atbs_;
} jam_stats_t;

// Settings menu structure
typedef struct {
    // sfText *title;
    // sfText *resolution;
    // sfText *fps;
    // sfText *volume;
    // sfText *difficulty;
    sfText *wip;
    sfVector2f pos_wip;
} jam_settings_t;

// How to play menu structure
typedef struct {
    sfTexture *htp_texture;
    sfSprite *htp;
} jam_how_to_play;

// Credits meu structure
typedef struct {
    sfText *title;
    sfText *person;
    sfText *other;
    sfVector2f pos_title;
    sfVector2f pos_person;
    sfVector2f pos_other;
} jam_credits;

// Principal My Hunter structure
typedef struct {
    long long int score;
    long long int highest_score;
    long long int all_time_best_score;
    sfRenderWindow *window;
    sfMusic *music;
    sfFont *font;
    sfEvent event;
    sfTexture *background_texture;
    sfSprite *background;
    sfTexture *hogwarts_bigroom_texture;
    sfSprite *hogwarts_bigroom;
    sfTexture *star_back_texture;
    sfSprite *star_back;
    jam_title_screen_t jam_ts;
    jam_play_t jam_p;
    jam_stats_t jam_st;
    jam_settings_t jam_se;
    jam_how_to_play jam_htp;
    jam_credits jam_c;
} tekleague_t;



void set_struct(tekleague_t *);
void display_elements(tekleague_t *);
void render_elements(tekleague_t *);

    /* Title screen */

void destroy_tekleague(tekleague_t *);
int set_buttons_colors(sfVector2i, tekleague_t *);
int render_title_screen(tekleague_t *);
int title_screen(void);



    /* Play */

long long int get_best_score(void);
void animate_dementor(tekleague_t *, sfTime);
void dementor_kill(tekleague_t *, sfVector2f, sfVector2f *, unsigned int *);
int play(tekleague_t *);



    /* Statistics */

void all_time_best_score(tekleague_t *);
int stats(tekleague_t *);



    /* Settings */

int settings(tekleague_t *);



    /* How to play */

int how_to_play(tekleague_t *);



    /* Credits */

int credits(tekleague_t *);



    /* My hunter */

int check_files(void);
void print_help(void);
int tekleague(int, char **, char **);

#endif /* !MY_HUNTER_H_ */
