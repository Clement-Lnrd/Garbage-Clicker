/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** epi_jam header
*/

#ifndef EPI_JAM_H_
    #define EPI_JAM_H_

    /* Include libraries */

    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "my.h"

    /* Epitech JAM struct */

// Settings structure
typedef struct settings {
    sfVideoMode resolution;
    int fps;
    float volume;
    int difficulty;
} settings_t;

// Title screen menu structure
typedef struct jam_title_screen {
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
typedef struct jam_play {
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
typedef struct jam_stats {
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
typedef struct jam_settings {
    // sfText *title;
    // sfText *resolution;
    // sfText *fps;
    // sfText *volume;
    // sfText *difficulty;
    sfText *wip;
    sfVector2f pos_wip;
} jam_settings_t;

// How to play menu structure
typedef struct jam_how_to_play {
    sfTexture *htp_texture;
    sfSprite *htp;
} jam_how_to_play;

// Credits meu structure
typedef struct jam_credits {
    sfText *title;
    sfText *person;
    sfText *other;
    sfVector2f pos_title;
    sfVector2f pos_person;
    sfVector2f pos_other;
} jam_credits;

// Principal Epitech JAM structure
typedef struct jam {
    long long int score;
    long long int highest_score;
    long long int all_time_best_score;
    sfRenderWindow *window;
    sfMusic *music;
    sfFont *font;
    sfEvent event;
    sfTexture *background_texture;
    sfSprite *background;
    sfTexture *game_background_texture;
    sfSprite *game_background;
    jam_title_screen_t jam_ts;
    jam_play_t jam_p;
    jam_stats_t jam_st;
    jam_settings_t jam_se;
    jam_how_to_play jam_htp;
    jam_credits jam_c;
} jam_t;

void set_struct(jam_t *);
void display_elements(jam_t *);
void render_elements(jam_t *);
void destroy_jam(jam_t *);
int set_buttons_colors(sfVector2i, jam_t *);
int render_title_screen(jam_t *);
int title_screen(void);
long long int get_best_score(void);
void animate_dementor(jam_t *, sfTime);
void dementor_kill(jam_t *, sfVector2f, sfVector2f *, unsigned int *);
int play(jam_t *);
void all_time_best_score(jam_t *);
int stats(jam_t *);
int settings(jam_t *);
int how_to_play(jam_t *);
int credits(jam_t *);
void check_closing_event(jam_t *jam);
int check_files(void);
int jam(int, char **, char **);

#endif /* !EPI_JAM_H_ */
