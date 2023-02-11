/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** render_elements_2
*/

#include "../include/epi_jam.h"

static void display_sprite(sfSprite **sprite, sfTexture *texture)
{
    (*sprite) = sfSprite_create();
    sfSprite_setTexture((*sprite), texture, sfTrue);
}

static void display_text(sfText **text, const char *str, sfFont *font, int size)
{
    (*text) = sfText_create();
    sfText_setString((*text), str);
    sfText_setFont((*text), font);
    sfText_setCharacterSize((*text), size);
}

static void display_elements_2(jam_t *jam)
{
    display_text(&jam->jam_st.title, "Statistics", jam->font, 100);
    display_text(&jam->jam_st.last_score, "Last score:", jam->font, 70);
    display_text(&jam->jam_st.sbs, "Session best score:", jam->font, 70);
    display_text(&jam->jam_st.atbs, "All time best score:", jam->font, 70);
    display_text(&jam->jam_st.last_score_, "0", jam->font, 70);
    display_text(&jam->jam_st.sbs_, "0", jam->font, 70);
    display_text(&jam->jam_st.atbs_, "0", jam->font, 70);
    display_text(&jam->jam_se.wip, "WIP", jam->font, 150);
}

void display_elements(jam_t *jam)
{
    display_sprite(&jam->background, jam->background_texture);
    display_sprite(&jam->game_background, jam->game_background_texture);
    display_sprite(&jam->jam_p.vacuum, jam->jam_p.vacuum_texture);
    display_sprite(&jam->jam_p.waste_bags, jam->jam_p.waste_bags_texture);
    display_sprite(&jam->jam_htp.htp, jam->jam_htp.htp_texture);
    display_text(&jam->jam_ts.title, "Epitech JAM", jam->font, 200);
    display_text(&jam->jam_ts.play, "Play", jam->font, 150);
    display_text(&jam->jam_ts.stats, "Statistics", jam->font, 100);
    display_text(&jam->jam_ts.settings, "Settings", jam->font, 100);
    display_text(&jam->jam_ts.how_to_play, "How to play", jam->font, 100);
    display_text(&jam->jam_ts.credits, "Credits", jam->font, 100);
    display_text(&jam->jam_ts.quit, "Quit", jam->font, 100);
    display_text(&jam->jam_p.score_, "Score:", jam->font, 70);
    display_text(&jam->jam_p.score, "0", jam->font, 70);
    display_text(&jam->jam_c.title, "Credits", jam->font, 100);
    display_text(&jam->jam_c.person, "Clement Lienard", jam->font, 70);
    display_text(&jam->jam_c.other, "Warner Bros", jam->font, 70);
    display_elements_2(jam);
}
