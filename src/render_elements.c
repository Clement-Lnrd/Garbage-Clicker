/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** render_elements
** Display sprites, texts, set textures rectangles, and set elements positions
*/

#include "../include/epi_jam.h"

static void set_elements_positions_2(jam_t *jam)
{
    sfText_setColor(jam->jam_c.title, sfWhite);
    sfText_setColor(jam->jam_c.person, sfWhite);
    sfText_setColor(jam->jam_c.other, sfWhite);
    sfText_setColor(jam->jam_st.title, sfWhite);
    sfText_setPosition(jam->jam_st.last_score, jam->jam_st.pos_last_score);
    sfText_setPosition(jam->jam_st.sbs, jam->jam_st.pos_sbs);
    sfText_setPosition(jam->jam_st.atbs, jam->jam_st.pos_atbs);
    sfText_setPosition(jam->jam_st.last_score_, jam->jam_st.pos_last_score_);
    sfText_setPosition(jam->jam_st.sbs_, jam->jam_st.pos_sbs_);
    sfText_setPosition(jam->jam_st.atbs_, jam->jam_st.pos_atbs_);
    sfText_setPosition(jam->jam_se.wip, jam->jam_se.pos_wip);
    sfSprite_setColor(jam->jam_htp.htp, sfWhite);
    sfText_setColor(jam->jam_st.last_score, sfWhite);
    sfText_setColor(jam->jam_st.sbs, sfWhite);
    sfText_setColor(jam->jam_st.atbs, sfWhite);
    sfText_setColor(jam->jam_st.last_score_, sfWhite);
    sfText_setColor(jam->jam_st.sbs_, sfWhite);
    sfText_setColor(jam->jam_st.atbs_, sfWhite);
    sfText_setColor(jam->jam_se.wip, sfWhite);
}

static void set_elements_positions(jam_t *jam)
{
    sfSprite_setOrigin(jam->jam_p.vacuum, (sfVector2f){160, 140});
    sfSprite_setPosition(jam->jam_p.vacuum, jam->jam_p.pos_vacuum);
    sfText_setPosition(jam->jam_ts.title, jam->jam_ts.pos_title);
    sfText_setPosition(jam->jam_ts.play, jam->jam_ts.pos_play);
    sfText_setPosition(jam->jam_ts.stats, jam->jam_ts.pos_stats);
    sfText_setPosition(jam->jam_ts.settings, jam->jam_ts.pos_settings);
    sfText_setPosition(jam->jam_ts.how_to_play, jam->jam_ts.pos_how_to_play);
    sfText_setPosition(jam->jam_ts.credits, jam->jam_ts.pos_credits);
    sfText_setPosition(jam->jam_ts.quit, jam->jam_ts.pos_quit);
    sfText_setPosition(jam->jam_p.score_, jam->jam_p.pos_score_);
    sfText_setPosition(jam->jam_p.score, jam->jam_p.pos_score);
    sfText_setPosition(jam->jam_p.fail, jam->jam_p.pos_fail);
    sfText_setPosition(jam->jam_p.fail_, jam->jam_p.pos_fail_);
    sfText_setPosition(jam->jam_c.title, jam->jam_c.pos_title);
    sfText_setPosition(jam->jam_c.person, jam->jam_c.pos_person);
    sfText_setPosition(jam->jam_c.other, jam->jam_c.pos_other);
    sfText_setPosition(jam->jam_st.title, jam->jam_st.pos_title);
    set_elements_positions_2(jam);
}

void render_elements(jam_t *jam)
{
    display_elements(jam);
    set_elements_positions(jam);
}
