/*
** EPITECH PROJECT, 2022
** My Hunter
** File description:
** play
*/

#include "../../include/my_hunter.h"

static void handle_dementors(my_hunter_t *mh, sfVector2i pos, sfVector2f *dpos
    , unsigned int *fails)
{
    sfTime time = sfClock_getElapsedTime(mh->mh_p.clock);
    sfVector2f fpos = {pos.x - 20, pos.y - 13};

    dpos->x = (((time.microseconds / 2000) - 250) + time.microseconds / 8000);
    sfSprite_setPosition(mh->mh_p.wand, fpos);
    sfSprite_setPosition(mh->mh_p.dementor, (*dpos));
    if (mh->event.type == sEMBP && mh->event.mouseButton.button == sML)
        mh->mh_p.wands.left = 488;
    else
        mh->mh_p.wands.left = 0;
    sfSprite_setTextureRect(mh->mh_p.wand, mh->mh_p.wands);
    dementor_kill(mh, fpos, dpos, fails);
    animate_dementor(mh, time);
}

static void draw_elements(my_hunter_t *mh, char *score)
{
    sfRenderWindow_clear(mh->window, sfBlack);
    sfRenderWindow_drawSprite(mh->window, mh->hogwarts_bigroom, NULL);
    sfRenderWindow_drawSprite(mh->window, mh->mh_p.dementor, NULL);
    sfRenderWindow_drawSprite(mh->window, mh->mh_p.wand, NULL);
    sfRenderWindow_drawText(mh->window, mh->mh_p.score_, NULL);
    sfText_setString(mh->mh_p.score, my_int_to_str(mh->score, score));
    sfRenderWindow_drawText(mh->window, mh->mh_p.score, NULL);
}

static int leave_play(my_hunter_t *mh, unsigned int err, unsigned int fails)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue || fails == 3) {
        if (mh->highest_score < mh->score)
            mh->highest_score = mh->score;
        if (mh->all_time_best_score < mh->score) {
            mh->all_time_best_score = mh->score;
            all_time_best_score(mh);
        }
        err = (render_title_screen(mh) == 84) ? (84) : (0);
    }
    return (err);
}

static int render_play(my_hunter_t *mh)
{
    unsigned int err = 0;
    unsigned int fails = 0;
    sfVector2i pos = {0};
    sfVector2f dpos = {-250, (rand() % 880)};
    char *score = malloc(sizeof(char) * 21);

    mh->score = 0;
    sfSprite_setPosition(mh->mh_p.dementor, dpos);
    while (sfRenderWindow_isOpen(mh->window)) {
        while (sfRenderWindow_pollEvent(mh->window, &mh->event))
            (mh->event.type == sfEvtClosed) ? (sRW_cl(mh->window)) : (0);
        draw_elements(mh, score);
        pos = sfMouse_getPositionRenderWindow(mh->window);
        handle_dementors(mh, pos, &dpos, &fails);
        err = leave_play(mh, err, fails);
        sfRenderWindow_display(mh->window);
    }
    free(score);
    return (err);
}

int play(my_hunter_t *mh)
{
    sfRenderWindow_setMouseCursorVisible(mh->window, sfFalse);
    sfClock_restart(mh->mh_p.clock);
    if (render_play(mh) == 84)
        return (84);
    return (0);
}
