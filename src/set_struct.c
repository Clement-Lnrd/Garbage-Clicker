/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** set_struct
** Initialise My Hunter structure
** jam_ts = tekleague_title_screen structure, for title screen
** jam_p = tekleague_play structure, for play menu
*/

#include "../include/my_hunter.h"

// const array which contains all assets used in this file
sc char *assets[] = {"assets/sounds/musics/hp_theme.ogg"
    , "assets/fonts/hp.ttf", "assets/textures/background.png"
    , "assets/textures/wand.png", "assets/textures/dementors.png"
    , "assets/textures/hogwarts_bigroom.png"
    , "assets/textures/star_back.png", "assets/textures/htp.png", 0};

sc tekleague_t tmp = {
    .score = 0,
    .highest_score = 0,
    .jam_ts.pos_title = {680, -20},
    .jam_ts.pos_play = {840, 275},
    .jam_ts.pos_stats = {620, 475},
    .jam_ts.pos_settings = {980, 475},
    .jam_ts.pos_how_to_play = {575, 600},
    .jam_ts.pos_credits = {1005, 600},
    .jam_ts.pos_quit = {870, 725},
    .jam_p.pos_wand = {1320, 580},
    .jam_p.pos_score_ = {20, 0},
    .jam_p.pos_score = {160, 0},
    .jam_p.wands = {0, 0, 470, 411},
    .jam_p.dementors = {0, 0, 118, 80},
    .jam_c.pos_title = {830, 350},
    .jam_c.pos_person = {770, 500},
    .jam_c.pos_other = {810, 600},
    .jam_st.pos_title = {830, 300},
    .jam_st.pos_last_score = {700, 450},
    .jam_st.pos_sbs = {700, 550},
    .jam_st.pos_atbs = {700, 650},
    .jam_st.pos_last_score_ = {930, 450},
    .jam_st.pos_sbs_ = {1080, 550},
    .jam_st.pos_atbs_ = {1100, 650},
    .jam_se.pos_wip = {850, 500}
};

void set_struct(tekleague_t *jam)
{
    sfVideoMode mode = {1920, 1080, 32};

    (*jam) = tmp;
    jam->window = sfRenderWindow_create(mode, "My Hunter", sfClose, NULL);
    jam->music = sfMusic_createFromFile(assets[0]);
    jam->font = sfFont_createFromFile(assets[1]);
    jam->background_texture = textureFromFile(assets[2], NULL);
    jam->hogwarts_bigroom_texture = textureFromFile(assets[5], NULL);
    jam->star_back_texture = textureFromFile(assets[6], NULL);
    jam->jam_p.wand_texture = textureFromFile(assets[3], NULL);
    jam->jam_p.dementor_texture = textureFromFile(assets[4], NULL);
    jam->jam_htp.htp_texture = textureFromFile(assets[7], NULL);
    jam->jam_p.clock = sfClock_create();
    jam->all_time_best_score = get_best_score();
}
