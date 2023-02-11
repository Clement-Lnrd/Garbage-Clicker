/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** stats
*/

#include "../../include/epi_jam.h"

static void draw_stats(jam_t *jam)
{
    char *score = malloc(sizeof(char) * 21);
    sfText_setString(jam->jam_st.last_score_, my_int_to_str(jam->score, score));
    sfRenderWindow_drawText(jam->window, jam->jam_st.last_score_, NULL);
    sfText_setString(jam->jam_st.sbs_, my_int_to_str(jam->highest_score, score));
    sfRenderWindow_drawText(jam->window, jam->jam_st.sbs_, NULL);
    sfText_setString(jam->jam_st.atbs_, my_int_to_str(jam->all_time_best_score
        , score));
    sfRenderWindow_drawText(jam->window, jam->jam_st.atbs_, NULL);
    free(score);
}

static void draw_elements(jam_t *jam)
{
    sfRenderWindow_clear(jam->window, sfBlack);
    sfRenderWindow_drawSprite(jam->window, jam->star_back, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.title, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_st.title, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_st.last_score, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_st.sbs, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_st.atbs, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_st.last_score_, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_st.sbs_, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_st.atbs_, NULL);
    draw_stats(jam);
}

static int render_stats(jam_t *jam)
{
    unsigned int err = 0;

    while (sfRenderWindow_isOpen(jam->window)) {
        check_closing_event(jam);
        draw_elements(jam);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            err = (render_title_screen(jam) == 84) ? (84) : (0);
        sfRenderWindow_display(jam->window);
    }
    return (err);
}

int stats(jam_t *jam)
{
    if (render_stats(jam) == 84)
        return (84);
    return (0);
}
