/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** set_struct
** Initialise My Hunter structure
** mh_ts = my_hunter_title_screen structure, for title screen
** mh_p = my_hunter_play structure, for play menu
*/

#include "../include/my_hunter.h"

// const array which contains all assets used in this file
sc char *assets[] = {"assets/sounds/musics/hp_theme.ogg"
    , "assets/fonts/hp.ttf", "assets/textures/background.png"
    , "assets/textures/wand.png", "assets/textures/dementors.png"
    , "assets/textures/hogwarts_bigroom.png"
    , "assets/textures/star_back.png", "assets/textures/htp.png", 0};

sc my_hunter_t tmp = {
    .score = 0,
    .highest_score = 0,
    .mh_ts.pos_title = {680, -20},
    .mh_ts.pos_play = {840, 275},
    .mh_ts.pos_stats = {620, 475},
    .mh_ts.pos_settings = {980, 475},
    .mh_ts.pos_how_to_play = {575, 600},
    .mh_ts.pos_credits = {1005, 600},
    .mh_ts.pos_quit = {870, 725},
    .mh_p.pos_wand = {1320, 580},
    .mh_p.pos_score_ = {20, 0},
    .mh_p.pos_score = {160, 0},
    .mh_p.wands = {0, 0, 470, 411},
    .mh_p.dementors = {0, 0, 118, 80},
    .mh_c.pos_title = {830, 350},
    .mh_c.pos_person = {770, 500},
    .mh_c.pos_other = {810, 600},
    .mh_st.pos_title = {830, 300},
    .mh_st.pos_last_score = {700, 450},
    .mh_st.pos_sbs = {700, 550},
    .mh_st.pos_atbs = {700, 650},
    .mh_st.pos_last_score_ = {930, 450},
    .mh_st.pos_sbs_ = {1080, 550},
    .mh_st.pos_atbs_ = {1100, 650},
    .mh_se.pos_wip = {850, 500}
};

void set_struct(my_hunter_t *mh)
{
    sfVideoMode mode = {1920, 1080, 32};

    (*mh) = tmp;
    mh->window = sfRenderWindow_create(mode, "My Hunter", sfClose, NULL);
    mh->music = sfMusic_createFromFile(assets[0]);
    mh->font = sfFont_createFromFile(assets[1]);
    mh->background_texture = textureFromFile(assets[2], NULL);
    mh->hogwarts_bigroom_texture = textureFromFile(assets[5], NULL);
    mh->star_back_texture = textureFromFile(assets[6], NULL);
    mh->mh_p.wand_texture = textureFromFile(assets[3], NULL);
    mh->mh_p.dementor_texture = textureFromFile(assets[4], NULL);
    mh->mh_htp.htp_texture = textureFromFile(assets[7], NULL);
    mh->mh_p.clock = sfClock_create();
    mh->all_time_best_score = get_best_score();
}
