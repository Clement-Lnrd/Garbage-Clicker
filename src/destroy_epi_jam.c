/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** destroy_epi_jam
*/

#include "../include/epi_jam.h"

static void destroy_play(jam_t *jam)
{
    for (u_int i = 0; jam->jam_p.waste_bags[i].sprite; ++i) {
        sfSprite_destroy(jam->jam_p.waste_bags[i].sprite);
        sfClock_destroy(jam->jam_p.waste_bags[i].clock);
    }
    free(jam->jam_p.waste_bags);
    sfTexture_destroy(jam->jam_p.waste_bags_texture);
    sfText_destroy(jam->jam_p.score_);
    sfText_destroy(jam->jam_p.score);
    sfText_destroy(jam->jam_p.fail_);
    sfText_destroy(jam->jam_p.fail);
}

static void destroy_title_screen(jam_t *jam)
{
    sfText_destroy(jam->jam_ts.title);
    sfText_destroy(jam->jam_ts.play);
    sfText_destroy(jam->jam_ts.stats);
    sfText_destroy(jam->jam_ts.credits);
    sfText_destroy(jam->jam_ts.quit);
}

void destroy_jam(jam_t *jam)
{
    destroy_play(jam);
    destroy_title_screen(jam);
    sfSprite_destroy(jam->background);
    sfTexture_destroy(jam->background_texture);
    sfSprite_destroy(jam->game_background);
    sfTexture_destroy(jam->game_background_texture);
    sfFont_destroy(jam->font);
    sfMusic_destroy(jam->music);
    sfRenderWindow_destroy(jam->window);
}
