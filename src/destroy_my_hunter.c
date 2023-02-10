/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** destroy_my_hunter
*/

#include "../include/my_hunter.h"

static void destroy_play(my_hunter_t *mh)
{
    sfClock_destroy(mh->mh_p.clock);
    sfSprite_destroy(mh->mh_p.wand);
    sfSprite_destroy(mh->mh_p.dementor);
    sfTexture_destroy(mh->mh_p.wand_texture);
    sfTexture_destroy(mh->mh_p.dementor_texture);
    sfText_destroy(mh->mh_p.score_);
    sfText_destroy(mh->mh_p.score);
}

static void destroy_title_screen(my_hunter_t *mh)
{
    sfText_destroy(mh->mh_ts.title);
    sfText_destroy(mh->mh_ts.play);
    sfText_destroy(mh->mh_ts.stats);
    sfText_destroy(mh->mh_ts.settings);
    sfText_destroy(mh->mh_ts.how_to_play);
    sfText_destroy(mh->mh_ts.credits);
    sfText_destroy(mh->mh_ts.quit);
}

void destroy_my_hunter(my_hunter_t *mh)
{
    destroy_play(mh);
    destroy_title_screen(mh);
    sfSprite_destroy(mh->star_back);
    sfTexture_destroy(mh->star_back_texture);
    sfSprite_destroy(mh->hogwarts_bigroom);
    sfTexture_destroy(mh->hogwarts_bigroom_texture);
    sfSprite_destroy(mh->background);
    sfTexture_destroy(mh->background_texture);
    sfFont_destroy(mh->font);
    sfMusic_destroy(mh->music);
    sfRenderWindow_destroy(mh->window);
}
