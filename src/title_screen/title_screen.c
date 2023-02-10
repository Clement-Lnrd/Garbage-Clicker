/*
** EPITECH PROJECT, 2022
** My Hunter
** File description:
** title_screen
*/

#include "../../include/my_hunter.h"

// int CSFML vector to position window at left top of screen
sc sfVector2i pos_window = {0, 0};

static void draw_elements(my_hunter_t *mh)
{
    sfRenderWindow_clear(mh->window, sfBlack);
    sfRenderWindow_drawSprite(mh->window, mh->background, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.title, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.play, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.stats, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.settings, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.how_to_play, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.credits, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_ts.quit, NULL);
}

int render_title_screen(my_hunter_t *mh)
{
    sfVector2i pos = {0};

    sfRenderWindow_setMouseCursorVisible(mh->window, sfTrue);
    while (sfRenderWindow_isOpen(mh->window)) {
        while (sfRenderWindow_pollEvent(mh->window, &mh->event))
            (mh->event.type == sfEvtClosed) ? (sRW_cl(mh->window)) : (0);
        draw_elements(mh);
        pos = sfMouse_getPositionRenderWindow(mh->window);
        if (set_buttons_colors(pos, mh) == 84)
            return (84);
        sfRenderWindow_display(mh->window);
    }
    return (0);
}

int title_screen(void)
{
    my_hunter_t *mh = malloc(sizeof(my_hunter_t));

    srand(time(NULL));
    set_struct(mh);
    if (!mh->mh_p.clock || !mh->mh_p.wand_texture || !mh->mh_p.dementor_texture
        || !mh->window || !mh->background_texture || !mh->font || !mh->music
        || !mh->hogwarts_bigroom_texture || !mh->star_back_texture)
        return (84);
    sfRenderWindow_setFramerateLimit(mh->window, 60);
    sfRenderWindow_setPosition(mh->window, pos_window);
    sfMusic_play(mh->music);
    sfMusic_setLoop(mh->music, sfTrue);
    render_elements(mh);
    if (render_title_screen(mh) == 84)
        return (84);
    destroy_my_hunter(mh);
    free(mh);
    return (0);
}
