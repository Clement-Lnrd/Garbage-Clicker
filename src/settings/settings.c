/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** settings
*/

#include "../../include/my_hunter.h"

static void draw_elements(tekleague_t *jam)
{
    sfRenderWindow_clear(jam->window, sfBlack);
    sfRenderWindow_drawSprite(jam->window, jam->star_back, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.title, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_se.wip, NULL);
}

static int render_settings(tekleague_t *jam)
{
    unsigned int err = 0;

    while (sfRenderWindow_isOpen(jam->window)) {
        while (sfRenderWindow_pollEvent(jam->window, &jam->event))
            (jam->event.type == sfEvtClosed) ? (sRW_cl(jam->window)) : (0);
        draw_elements(jam);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            err = (render_title_screen(jam) == 84) ? (84) : (0);
        sfRenderWindow_display(jam->window);
    }
    return (err);
}

int settings(tekleague_t *jam)
{
    if (render_settings(jam) == 84)
        return (84);
    return (0);
}
