/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** destroy_epi_jam
*/

#include "../include/epi_jam.h"

static void destroy_play(jam_t *jam)
{
    sfClock_destroy(jam->jam_p.clock);
    sfSprite_destroy(jam->jam_p.wand);
    sfSprite_destroy(jam->jam_p.dementor);
    sfTexture_destroy(jam->jam_p.wand_texture);
    sfTexture_destroy(jam->jam_p.dementor_texture);
    sfText_destroy(jam->jam_p.score_);
    sfText_destroy(jam->jam_p.score);
}

static void destroy_title_screen(jam_t *jam)
{
    sfText_destroy(jam->jam_ts.title);
    sfText_destroy(jam->jam_ts.play);
    sfText_destroy(jam->jam_ts.stats);
    sfText_destroy(jam->jam_ts.settings);
    sfText_destroy(jam->jam_ts.how_to_play);
    sfText_destroy(jam->jam_ts.credits);
    sfText_destroy(jam->jam_ts.quit);
}

void destroy_jam(jam_t *jam)
{
    destroy_play(jam);
    destroy_title_screen(jam);
    sfSprite_destroy(jam->star_back);
    sfTexture_destroy(jam->star_back_texture);
    sfSprite_destroy(jam->hogwarts_bigroom);
    sfTexture_destroy(jam->hogwarts_bigroom_texture);
    sfSprite_destroy(jam->background);
    sfTexture_destroy(jam->background_texture);
    sfFont_destroy(jam->font);
    sfMusic_destroy(jam->music);
    sfRenderWindow_destroy(jam->window);
}
