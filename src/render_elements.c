/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** render_elements
** Display sprites, texts, set textures rectangles, and set elements positions
*/

#include "../include/my_hunter.h"

// float CSFML vector to resize magic wand
sc sfVector2f size_wand = {0.5, 0.5};

sc sfColor gold = {255, 215, 0, 255};

static void set_textures_rects(my_hunter_t *mh)
{
    sfSprite_setTextureRect(mh->mh_p.wand, mh->mh_p.wands);
    sfSprite_setTextureRect(mh->mh_p.dementor, mh->mh_p.dementors);
}

static void scale_elements(my_hunter_t *mh)
{
    sfSprite_scale(mh->mh_p.wand, size_wand);
}

static void set_elements_positions_2(my_hunter_t *mh)
{
    sfText_setPosition(mh->mh_st.last_score, mh->mh_st.pos_last_score);
    sfText_setPosition(mh->mh_st.sbs, mh->mh_st.pos_sbs);
    sfText_setPosition(mh->mh_st.atbs, mh->mh_st.pos_atbs);
    sfText_setPosition(mh->mh_st.last_score_, mh->mh_st.pos_last_score_);
    sfText_setPosition(mh->mh_st.sbs_, mh->mh_st.pos_sbs_);
    sfText_setPosition(mh->mh_st.atbs_, mh->mh_st.pos_atbs_);
    sfText_setPosition(mh->mh_se.wip, mh->mh_se.pos_wip);
    sfSprite_setColor(mh->mh_htp.htp, gold);
    sfText_setColor(mh->mh_st.last_score, gold);
    sfText_setColor(mh->mh_st.sbs, gold);
    sfText_setColor(mh->mh_st.atbs, gold);
    sfText_setColor(mh->mh_st.last_score_, gold);
    sfText_setColor(mh->mh_st.sbs_, gold);
    sfText_setColor(mh->mh_st.atbs_, gold);
    sfText_setColor(mh->mh_se.wip, gold);
}

static void set_elements_positions(my_hunter_t *mh)
{
    sfSprite_setPosition(mh->mh_p.wand, mh->mh_p.pos_wand);
    sfText_setPosition(mh->mh_ts.title, mh->mh_ts.pos_title);
    sfText_setPosition(mh->mh_ts.play, mh->mh_ts.pos_play);
    sfText_setPosition(mh->mh_ts.stats, mh->mh_ts.pos_stats);
    sfText_setPosition(mh->mh_ts.settings, mh->mh_ts.pos_settings);
    sfText_setPosition(mh->mh_ts.how_to_play, mh->mh_ts.pos_how_to_play);
    sfText_setPosition(mh->mh_ts.credits, mh->mh_ts.pos_credits);
    sfText_setPosition(mh->mh_ts.quit, mh->mh_ts.pos_quit);
    sfText_setPosition(mh->mh_p.score_, mh->mh_p.pos_score_);
    sfText_setPosition(mh->mh_p.score, mh->mh_p.pos_score);
    sfText_setPosition(mh->mh_c.title, mh->mh_c.pos_title);
    sfText_setPosition(mh->mh_c.person, mh->mh_c.pos_person);
    sfText_setPosition(mh->mh_c.other, mh->mh_c.pos_other);
    sfText_setPosition(mh->mh_st.title, mh->mh_st.pos_title);
    sfText_setColor(mh->mh_c.title, gold);
    sfText_setColor(mh->mh_c.person, gold);
    sfText_setColor(mh->mh_c.other, gold);
    sfText_setColor(mh->mh_st.title, gold);
    set_elements_positions_2(mh);
}

void render_elements(my_hunter_t *mh)
{
    display_elements(mh);
    set_textures_rects(mh);
    scale_elements(mh);
    set_elements_positions(mh);
}
