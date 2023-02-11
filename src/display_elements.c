/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** render_elements_2
*/

#include <sys/types.h>
#include "../include/epi_jam.h"

static void make_sprite(sfSprite **sprite, sfTexture *texture)
{
    (*sprite) = sfSprite_create();
    sfSprite_setTexture((*sprite), texture, sfTrue);
}

static void make_text(sfText **text, const char *str, sfFont *font, int size)
{
    (*text) = sfText_create();
    sfText_setString((*text), str);
    sfText_setFont((*text), font);
    sfText_setCharacterSize((*text), size);
}

static void create_waste_bags(jam_t *jam)
{
    jam->jam_p.waste_bags = malloc(sizeof(sprite_t) * 6);

    for (u_int i = 0; i < 5; ++i) {
        make_sprite(&jam->jam_p.waste_bags[i].sprite, jam->jam_p.waste_bags_texture);
        jam->jam_p.waste_bags[i].pos = (sfVector2f){0, 0};
        jam->jam_p.waste_bags[i].initial_pos = (sfVector2f){0, 0};
        jam->jam_p.waste_bags[i].mov = (sfVector2f){0, 0};
        sfSprite_setTextureRect(jam->jam_p.waste_bags[i].sprite, (sfIntRect){(rand() % 5) * 28, 0, 28, 27});
        sfSprite_setScale(jam->jam_p.waste_bags[i].sprite, (sfVector2f){2, 2});
    }
    jam->jam_p.waste_bags[5] = (sprite_t){NULL, {0, 0}, {0, 0}};
}

static void display_elements_2(jam_t *jam)
{
    make_text(&jam->jam_st.title, "Statistics", jam->font, 100);
    make_text(&jam->jam_st.last_score, "Last score:", jam->font, 70);
    make_text(&jam->jam_st.sbs, "Session best score:", jam->font, 70);
    make_text(&jam->jam_st.atbs, "All time best score:", jam->font, 70);
    make_text(&jam->jam_st.last_score_, "0", jam->font, 70);
    make_text(&jam->jam_st.sbs_, "0", jam->font, 70);
    make_text(&jam->jam_st.atbs_, "0", jam->font, 70);
    make_text(&jam->jam_se.wip, "WIP", jam->font, 150);
}

void display_elements(jam_t *jam)
{
    make_sprite(&jam->background, jam->background_texture);
    make_sprite(&jam->game_background, jam->game_background_texture);
    make_sprite(&jam->jam_p.vacuum, jam->jam_p.vacuum_texture);
    create_waste_bags(jam);
    make_sprite(&jam->jam_htp.htp, jam->jam_htp.htp_texture);
    make_text(&jam->jam_ts.title, "Epitech JAM", jam->font, 200);
    make_text(&jam->jam_ts.play, "Play", jam->font, 150);
    make_text(&jam->jam_ts.stats, "Statistics", jam->font, 100);
    make_text(&jam->jam_ts.settings, "Settings", jam->font, 100);
    make_text(&jam->jam_ts.how_to_play, "How to play", jam->font, 100);
    make_text(&jam->jam_ts.credits, "Credits", jam->font, 100);
    make_text(&jam->jam_ts.quit, "Quit", jam->font, 100);
    make_text(&jam->jam_p.score_, "Score:", jam->font, 70);
    make_text(&jam->jam_p.score, "0", jam->font, 70);
    make_text(&jam->jam_p.fail_, "Fails:", jam->font, 70);
    make_text(&jam->jam_p.fail, "0", jam->font, 70);
    make_text(&jam->jam_c.title, "Credits", jam->font, 100);
    make_text(&jam->jam_c.person, "Clement Lienard", jam->font, 70);
    make_text(&jam->jam_c.other, "Warner Bros", jam->font, 70);
    display_elements_2(jam);
}
