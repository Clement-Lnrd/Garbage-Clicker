/*
** EPITECH PROJECT, 2022
** My Hunter
** File description:
** title_screen
*/

#include "../../include/my_hunter.h"

// int CSFML vector to position window at left top of screen
sc sfVector2i pos_window = {0, 0};

static void draw_elements(tekleague_t *jam)
{
    sfRenderWindow_clear(jam->window, sfBlack);
    sfRenderWindow_drawSprite(jam->window, jam->background, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.title, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.play, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.stats, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.settings, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.how_to_play, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.credits, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_ts.quit, NULL);
}

int render_title_screen(tekleague_t *jam)
{
    sfVector2i pos = {0};

    sfRenderWindow_setMouseCursorVisible(jam->window, sfTrue);
    while (sfRenderWindow_isOpen(jam->window)) {
        while (sfRenderWindow_pollEvent(jam->window, &jam->event))
            (jam->event.type == sfEvtClosed) ? (sRW_cl(jam->window)) : (0);
        draw_elements(jam);
        pos = sfMouse_getPositionRenderWindow(jam->window);
        if (set_buttons_colors(pos, jam) == 84)
            return (84);
        sfRenderWindow_display(jam->window);
    }
    return (0);
}

int title_screen(void)
{
    tekleague_t *jam = malloc(sizeof(tekleague_t));

    srand(time(NULL));
    set_struct(jam);
    if (!jam->jam_p.clock || !jam->jam_p.wand_texture || !jam->jam_p.dementor_texture
        || !jam->window || !jam->background_texture || !jam->font || !jam->music
        || !jam->hogwarts_bigroom_texture || !jam->star_back_texture)
        return (84);
    sfRenderWindow_setFramerateLimit(jam->window, 60);
    sfRenderWindow_setPosition(jam->window, pos_window);
    sfMusic_play(jam->music);
    sfMusic_setLoop(jam->music, sfTrue);
    render_elements(jam);
    if (render_title_screen(jam) == 84)
        return (84);
    destroy_tekleague(jam);
    free(jam);
    return (0);
}
