/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** stats
*/

#include "../../include/my_hunter.h"

static void draw_stats(my_hunter_t *mh)
{
    char *score = malloc(sizeof(char) * 21);
    sfText_setString(mh->mh_st.last_score_, my_int_to_str(mh->score, score));
    sfRenderWindow_drawText(mh->window, mh->mh_st.last_score_, NULL);
    sfText_setString(mh->mh_st.sbs_, my_int_to_str(mh->highest_score, score));
    sfRenderWindow_drawText(mh->window, mh->mh_st.sbs_, NULL);
    sfText_setString(mh->mh_st.atbs_, my_int_to_str(mh->all_time_best_score
        , score));
    sfRenderWindow_drawText(mh->window, mh->mh_st.atbs_, NULL);
    free(score);
}

static void draw_elements(my_hunter_t *mh)
{
    sfRenderWindow_clear(mh->window, sfBlack);
    sfRenderWindow_drawSprite(mh->window, mh->star_back, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.title, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_st.title, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_st.last_score, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_st.sbs, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_st.atbs, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_st.last_score_, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_st.sbs_, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_st.atbs_, NULL);
    draw_stats(mh);
}

static int render_stats(my_hunter_t *mh)
{
    unsigned int err = 0;

    while (sfRenderWindow_isOpen(mh->window)) {
        while (sfRenderWindow_pollEvent(mh->window, &mh->event))
            (mh->event.type == sfEvtClosed) ? (sRW_cl(mh->window)) : (0);
        draw_elements(mh);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            err = (render_title_screen(mh) == 84) ? (84) : (0);
        sfRenderWindow_display(mh->window);
    }
    return (err);
}

int stats(my_hunter_t *mh)
{
    if (render_stats(mh) == 84)
        return (84);
    return (0);
}
