/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** set_struct
** Initialise Epitech JAM structure
** jam_ts = jam_title_screen structure, for title screen
** jam_p = jam_play structure, for play menu
*/

#include "../include/epi_jam.h"

// const array which contains all assets used in this file
static const char *assets[] = {"assets/sounds/musics/theme.ogg",
    "assets/fonts/marvel.ttf", "assets/textures/background.png",
    "assets/textures/waste_bags.png", "assets/textures/game_background.png",
    NULL};

static const char *assets_vacuum[] = {"assets/textures/vacuum.png",
    "assets/textures/vacuum_etchebest.png", NULL};

static const jam_t tmp = {
    .score = 0,
    .highest_score = 0,
    .jam_ts.pos_title = {580, -20},
    .jam_ts.pos_play = {840, 300},
    .jam_ts.pos_stats = {620, 500},
    .jam_ts.pos_credits = {1005, 500},
    .jam_ts.pos_quit = {870, 650},
    .jam_p.pos_vacuum = {1320, 580},
    .jam_p.pos_score_ = {20, 0},
    .jam_p.pos_score = {170, 0},
    .jam_p.pos_fail = {1870, 0},
    .jam_p.pos_fail_ = {1740, 0},
    .jam_c.pos_title = {830, 350},
    .jam_c.pos_person = {770, 500},
    .jam_c.pos_other = {810, 600},
    .jam_st.pos_title = {830, 300},
    .jam_st.pos_last_score = {700, 450},
    .jam_st.pos_sbs = {700, 550},
    .jam_st.pos_atbs = {700, 650},
    .jam_st.pos_last_score_ = {945, 450},
    .jam_st.pos_sbs_ = {1125, 550},
    .jam_st.pos_atbs_ = {1125, 650}
};

void set_struct(jam_t *jam)
{
    sfVideoMode mode = {1920, 1080, 32};

    (*jam) = tmp;
    jam->window = sfRenderWindow_create(mode, "Epitech JAM", sfClose, NULL);
    jam->music = sfMusic_createFromFile(assets[0]);
    jam->font = sfFont_createFromFile(assets[1]);
    jam->background_texture = sfTexture_createFromFile(assets[2], NULL);
    jam->game_background_texture = sfTexture_createFromFile(assets[4], NULL);
    jam->jam_p.vacuum_texture = sfTexture_createFromFile(assets_vacuum[rand() % 2], NULL);
    jam->jam_p.waste_bags_texture = sfTexture_createFromFile(assets[3], NULL);
    jam->all_time_best_score = get_best_score();
}
