/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** render_elements_2
*/

#include "../include/my_hunter.h"

static void display_elements_2(my_hunter_t *mh)
{
    dispText(mh->mh_st.title, "Statistics", mh->font, 100);
    dispText(mh->mh_st.last_score, "Last score:", mh->font, 70);
    dispText(mh->mh_st.sbs, "Session best score:", mh->font, 70);
    dispText(mh->mh_st.atbs, "All time best score:", mh->font, 70);
    dispText(mh->mh_st.last_score_, "0", mh->font, 70);
    dispText(mh->mh_st.sbs_, "0", mh->font, 70);
    dispText(mh->mh_st.atbs_, "0", mh->font, 70);
    dispText(mh->mh_se.wip, "WIP", mh->font, 150);
}

void display_elements(my_hunter_t *mh)
{
    dispSprite(mh->background, mh->background_texture);
    dispSprite(mh->hogwarts_bigroom, mh->hogwarts_bigroom_texture);
    dispSprite(mh->star_back, mh->star_back_texture);
    dispSprite(mh->mh_p.wand, mh->mh_p.wand_texture);
    dispSprite(mh->mh_p.dementor, mh->mh_p.dementor_texture);
    dispSprite(mh->mh_htp.htp, mh->mh_htp.htp_texture);
    dispText(mh->mh_ts.title, "My Hunter", mh->font, 200);
    dispText(mh->mh_ts.play, "Play", mh->font, 150);
    dispText(mh->mh_ts.stats, "Statistics", mh->font, 100);
    dispText(mh->mh_ts.settings, "Settings", mh->font, 100);
    dispText(mh->mh_ts.how_to_play, "How to play", mh->font, 100);
    dispText(mh->mh_ts.credits, "Credits", mh->font, 100);
    dispText(mh->mh_ts.quit, "Quit", mh->font, 100);
    dispText(mh->mh_p.score_, "Score:", mh->font, 70);
    dispText(mh->mh_p.score, "0", mh->font, 70);
    dispText(mh->mh_c.title, "Credits", mh->font, 100);
    dispText(mh->mh_c.person, "Clement Lienard", mh->font, 70);
    dispText(mh->mh_c.other, "Warner Bros", mh->font, 70);
    display_elements_2(mh);
}
