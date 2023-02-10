/*
** EPITECH PROJECT, 2022
** My Hunter
** File description:
** buttons
*/

#include "../../include/my_hunter.h"

int set_play_color(sfVector2i pos, tekleague_t *jam)
{
    sfFloatRect p = sfText_getGlobalBounds(jam->jam_ts.play);
    unsigned int err = 0;

    if (pos.x > p.left && pos.x < (p.left + p.width)
        && pos.y > p.top && pos.y < (p.top + p.height)) {
        sfText_setColor(jam->jam_ts.play, sfYellow);
        if (jam->event.type == sEMBP
            && jam->event.mouseButton.button == sML)
            err = (play(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.play, sfWhite);
    return (err);
}

int set_stats_settings_color(sfVector2i pos, tekleague_t *jam)
{
    sfFloatRect st = sfText_getGlobalBounds(jam->jam_ts.stats);
    sfFloatRect se = sfText_getGlobalBounds(jam->jam_ts.settings);
    unsigned int err = 0;

    if (pos.x > st.left && pos.x < (st.left + st.width)
        && pos.y > st.top && pos.y < (st.top + st.height)) {
        sfText_setColor(jam->jam_ts.stats, sfYellow);
        if (jam->event.type == sEMBP
            && jam->event.mouseButton.button == sML)
            err = (stats(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.stats, sfWhite);
    if (pos.x > se.left && pos.x < (se.left + se.width)
        && pos.y > se.top && pos.y < (se.top + se.height)) {
        sfText_setColor(jam->jam_ts.settings, sfYellow);
        if (jam->event.type == sEMBP && jam->event.mouseButton.button == sML)
            err = (settings(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.settings, sfWhite);
    return (err);
}

int set_htp_credits_color(sfVector2i pos, tekleague_t *jam)
{
    sfFloatRect h = sfText_getGlobalBounds(jam->jam_ts.how_to_play);
    sfFloatRect c = sfText_getGlobalBounds(jam->jam_ts.credits);
    unsigned int err = 0;

    if (pos.x > h.left && pos.x < (h.left + h.width)
        && pos.y > h.top && pos.y < (h.top + h.height)) {
        sfText_setColor(jam->jam_ts.how_to_play, sfYellow);
        if (jam->event.type == sEMBP && jam->event.mouseButton.button == sML)
            err = (how_to_play(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.how_to_play, sfWhite);
    if (pos.x > c.left && pos.x < (c.left + c.width)
        && pos.y > c.top && pos.y < (c.top + c.height)) {
        sfText_setColor(jam->jam_ts.credits, sfYellow);
        if (jam->event.type == sEMBP && jam->event.mouseButton.button == sML)
            err = (credits(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.credits, sfWhite);
    return (err);
}

void set_quit_color(sfVector2i pos, tekleague_t *jam)
{
    sfFloatRect q = sfText_getGlobalBounds(jam->jam_ts.quit);

    if (pos.x > q.left && pos.x < (q.left + q.width)
        && pos.y > q.top && pos.y < (q.top + q.height)) {
        sfText_setColor(jam->jam_ts.quit, sfRed);
        if (jam->event.type == sEMBP && jam->event.mouseButton.button == sML)
            sfRenderWindow_close(jam->window);
    } else
        sfText_setColor(jam->jam_ts.quit, sfWhite);
}

int set_buttons_colors(sfVector2i pos, tekleague_t *jam)
{
    if (set_play_color(pos, jam) == 84)
        return (84);
    if (set_stats_settings_color(pos, jam) == 84)
        return (84);
    if (set_htp_credits_color(pos, jam) == 84)
        return (84);
    set_quit_color(pos, jam);
    return (0);
}
