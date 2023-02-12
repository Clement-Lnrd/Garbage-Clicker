/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** buttons
*/

#include "../../include/epi_jam.h"

static const sfColor blue = {81, 140, 202, 255};

int set_play_color(sfVector2i pos, jam_t *jam)
{
    sfFloatRect p = sfText_getGlobalBounds(jam->jam_ts.play);
    unsigned int err = 0;

    if (pos.x > p.left && pos.x < (p.left + p.width)
        && pos.y > p.top && pos.y < (p.top + p.height)) {
        sfText_setColor(jam->jam_ts.play, blue);
        if (jam->event.type == sfEvtMouseButtonPressed
            && jam->event.mouseButton.button == sfMouseLeft)
            err = (play(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.play, sfWhite);
    return (err);
}

int set_stats_color(sfVector2i pos, jam_t *jam)
{
    sfFloatRect st = sfText_getGlobalBounds(jam->jam_ts.stats);
    unsigned int err = 0;

    if (pos.x > st.left && pos.x < (st.left + st.width)
        && pos.y > st.top && pos.y < (st.top + st.height)) {
        sfText_setColor(jam->jam_ts.stats, blue);
        if (jam->event.type == sfEvtMouseButtonPressed
            && jam->event.mouseButton.button == sfMouseLeft)
            err = (stats(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.stats, sfWhite);
    return (err);
}

int set_credits_color(sfVector2i pos, jam_t *jam)
{
    sfFloatRect c = sfText_getGlobalBounds(jam->jam_ts.credits);
    unsigned int err = 0;

    if (pos.x > c.left && pos.x < (c.left + c.width)
        && pos.y > c.top && pos.y < (c.top + c.height)) {
        sfText_setColor(jam->jam_ts.credits, blue);
        if (jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
            err = (credits(jam) == 84) ? (84) : (0);
    } else
        sfText_setColor(jam->jam_ts.credits, sfWhite);
    return (err);
}

void set_quit_color(sfVector2i pos, jam_t *jam)
{
    sfFloatRect q = sfText_getGlobalBounds(jam->jam_ts.quit);

    if (pos.x > q.left && pos.x < (q.left + q.width)
        && pos.y > q.top && pos.y < (q.top + q.height)) {
        sfText_setColor(jam->jam_ts.quit, (sfColor){226, 54, 54, 255});
        if (jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
            sfRenderWindow_close(jam->window);
    } else
        sfText_setColor(jam->jam_ts.quit, sfWhite);
}

int set_buttons_colors(sfVector2i pos, jam_t *jam)
{
    if (set_play_color(pos, jam) == 84)
        return (84);
    if (set_stats_color(pos, jam) == 84)
        return (84);
    if (set_credits_color(pos, jam) == 84)
        return (84);
    set_quit_color(pos, jam);
    return (0);
}
