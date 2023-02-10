/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** how_to_play
*/

#include "../../include/my_hunter.h"

static void draw_elements(my_hunter_t *mh)
{
    sfRenderWindow_clear(mh->window, sfBlack);
    sfRenderWindow_drawSprite(mh->window, mh->star_back, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.title, NULL);
    sfRenderWindow_drawSprite(mh->window, mh->mh_htp.htp, NULL);
}

static int render_how_to_play(my_hunter_t *mh)
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

int how_to_play(my_hunter_t *mh)
{
    if (render_how_to_play(mh) == 84)
        return (84);
    return (0);
}
