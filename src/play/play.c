/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** play
*/

#include "../../include/epi_jam.h"

static void handle_dementors(jam_t *jam, sfVector2i pos, sfVector2f *dpos
    , unsigned int *fails)
{
    sfTime time = sfClock_getElapsedTime(jam->jam_p.clock);
    sfVector2f fpos = {pos.x - 20, pos.y - 13};

    dpos->x = (((time.microseconds / 2000) - 250) + time.microseconds / 8000);
    sfSprite_setPosition(jam->jam_p.wand, fpos);
    sfSprite_setPosition(jam->jam_p.dementor, (*dpos));
    if (jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
        jam->jam_p.wands.left = 488;
    else
        jam->jam_p.wands.left = 0;
    sfSprite_setTextureRect(jam->jam_p.wand, jam->jam_p.wands);
    dementor_kill(jam, fpos, dpos, fails);
    animate_dementor(jam, time);
}

static void draw_elements(jam_t *jam, char *score)
{
    sfRenderWindow_clear(jam->window, sfBlack);
    sfRenderWindow_drawSprite(jam->window, jam->game_background, NULL);
    sfRenderWindow_drawSprite(jam->window, jam->jam_p.dementor, NULL);
    sfRenderWindow_drawSprite(jam->window, jam->jam_p.wand, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_p.score_, NULL);
    sfText_setString(jam->jam_p.score, my_int_to_str(jam->score, score));
    sfRenderWindow_drawText(jam->window, jam->jam_p.score, NULL);
}

static int leave_play(jam_t *jam, unsigned int err, unsigned int fails)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue || fails == 3) {
        if (jam->highest_score < jam->score)
            jam->highest_score = jam->score;
        if (jam->all_time_best_score < jam->score) {
            jam->all_time_best_score = jam->score;
            all_time_best_score(jam);
        }
        err = (render_title_screen(jam) == 84) ? (84) : (0);
    }
    return (err);
}

static int render_play(jam_t *jam)
{
    unsigned int err = 0;
    unsigned int fails = 0;
    sfVector2i pos = {0};
    sfVector2f dpos = {-250, (rand() % 880)};
    char *score = malloc(sizeof(char) * 21);

    jam->score = 0;
    sfSprite_setPosition(jam->jam_p.dementor, dpos);
    while (sfRenderWindow_isOpen(jam->window)) {
        check_closing_event(jam);
        draw_elements(jam, score);
        pos = sfMouse_getPositionRenderWindow(jam->window);
        handle_dementors(jam, pos, &dpos, &fails);
        err = leave_play(jam, err, fails);
        sfRenderWindow_display(jam->window);
    }
    free(score);
    return (err);
}

int play(jam_t *jam)
{
    sfRenderWindow_setMouseCursorVisible(jam->window, sfFalse);
    sfClock_restart(jam->jam_p.clock);
    if (render_play(jam) == 84)
        return (84);
    return (0);
}
