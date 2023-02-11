/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** how_to_play
*/

#include "../../include/epi_jam.h"

static void draw_elements(jam_t *jam)
{
    sfRenderWindow_clear(jam->window, sfBlack);
    sfRenderWindow_drawSprite(jam->window, jam->background, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.title, NULL);
    sfRenderWindow_drawSprite(jam->window, jam->jam_htp.htp, NULL);
}

static int render_how_to_play(jam_t *jam)
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

int how_to_play(jam_t *jam)
{
    if (render_how_to_play(jam) == 84)
        return (84);
    return (0);
}
