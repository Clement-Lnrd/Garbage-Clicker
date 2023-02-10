/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** render_elements_2
*/

#include "../include/my_hunter.h"

static void display_elements_2(tekleague_t *jam)
{
    dispText(jam->jam_st.title, "Statistics", jam->font, 100);
    dispText(jam->jam_st.last_score, "Last score:", jam->font, 70);
    dispText(jam->jam_st.sbs, "Session best score:", jam->font, 70);
    dispText(jam->jam_st.atbs, "All time best score:", jam->font, 70);
    dispText(jam->jam_st.last_score_, "0", jam->font, 70);
    dispText(jam->jam_st.sbs_, "0", jam->font, 70);
    dispText(jam->jam_st.atbs_, "0", jam->font, 70);
    dispText(jam->jam_se.wip, "WIP", jam->font, 150);
}

void display_elements(tekleague_t *jam)
{
    dispSprite(jam->background, jam->background_texture);
    dispSprite(jam->hogwarts_bigroom, jam->hogwarts_bigroom_texture);
    dispSprite(jam->star_back, jam->star_back_texture);
    dispSprite(jam->jam_p.wand, jam->jam_p.wand_texture);
    dispSprite(jam->jam_p.dementor, jam->jam_p.dementor_texture);
    dispSprite(jam->jam_htp.htp, jam->jam_htp.htp_texture);
    dispText(jam->jam_ts.title, "My Hunter", jam->font, 200);
    dispText(jam->jam_ts.play, "Play", jam->font, 150);
    dispText(jam->jam_ts.stats, "Statistics", jam->font, 100);
    dispText(jam->jam_ts.settings, "Settings", jam->font, 100);
    dispText(jam->jam_ts.how_to_play, "How to play", jam->font, 100);
    dispText(jam->jam_ts.credits, "Credits", jam->font, 100);
    dispText(jam->jam_ts.quit, "Quit", jam->font, 100);
    dispText(jam->jam_p.score_, "Score:", jam->font, 70);
    dispText(jam->jam_p.score, "0", jam->font, 70);
    dispText(jam->jam_c.title, "Credits", jam->font, 100);
    dispText(jam->jam_c.person, "Clement Lienard", jam->font, 70);
    dispText(jam->jam_c.other, "Warner Bros", jam->font, 70);
    display_elements_2(jam);
}
