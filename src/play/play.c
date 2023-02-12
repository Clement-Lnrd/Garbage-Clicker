/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** play
*/

#include "../../include/epi_jam.h"

static const char *assets_vacuum[] = {"assets/textures/vacuum.png",
    "assets/textures/vacuum_etchebest.png", "assets/textures/vacuum_gabriel.png",
    "assets/textures/vacuum_chloe.png", "assets/textures/vacuum_sebastien.png",
    "assets/textures/vacuum_adam.png", "assets/textures/vacuum_augustin.png", NULL};

static void handle_waste_bags(jam_t *jam, unsigned int *fails)
{
    sfVector2i pos = {0};
    sfTime time;

    for (u_int i = 0; jam->jam_p.waste_bags[i].sprite; ++i) {
        time = sfClock_getElapsedTime(jam->jam_p.waste_bags[i].clock);
        jam->jam_p.waste_bags[i].pos.x = (((time.microseconds / jam->jam_p.waste_bags[i].mov.x) - 250) + time.microseconds / 8000) + jam->jam_p.waste_bags[i].initial_pos.x;
        pos = sfMouse_getPositionRenderWindow(jam->window);
        sfSprite_setPosition(jam->jam_p.vacuum, sfVector2i_to_sfVector2f(pos));
        sfSprite_setPosition(jam->jam_p.waste_bags[i].sprite, jam->jam_p.waste_bags[i].pos);
        if (jam->jam_p.waste_bags[i].pos.x <= -50 && jam->jam_p.waste_bags[i].pos.x >= -55)
            sfSprite_setTextureRect(jam->jam_p.waste_bags[i].sprite, (sfIntRect){(rand() % 5) * 28, 0, 28, 27});
        waste_bags_pick_up(jam, fails, i);
    }
}

static void draw_elements(jam_t *jam, char *score, char *fails, unsigned int *fails_nb)
{
    sfRenderWindow_clear(jam->window, sfBlack);
    sfRenderWindow_drawSprite(jam->window, jam->game_background, NULL);
    for (u_int i = 0; jam->jam_p.waste_bags[i].sprite; ++i)
        sfRenderWindow_drawSprite(jam->window, jam->jam_p.waste_bags[i].sprite, NULL);
    sfRenderWindow_drawSprite(jam->window, jam->jam_p.vacuum, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_p.score_, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_p.fail_, NULL);
    sfText_setString(jam->jam_p.score, my_int_to_str(jam->score, score));
    sfText_setString(jam->jam_p.fail, my_int_to_str((*fails_nb), fails));
    sfRenderWindow_drawText(jam->window, jam->jam_p.score, NULL);
    sfRenderWindow_drawText(jam->window, jam->jam_p.fail, NULL);
}

static int leave_play(jam_t *jam, unsigned int err, unsigned int fails)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue || fails >= 5) {
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
    char *score = malloc(sizeof(char) * 21);
    char *fails_char = malloc(sizeof(char) * 21);

    jam->score = 0;
    for (u_int i = 0; jam->jam_p.waste_bags[i].sprite; ++i) {
        jam->jam_p.waste_bags[i].initial_pos = (sfVector2f){(rand() % 1500 * -1), (rand() % 880 + 40)};
        jam->jam_p.waste_bags[i].mov = (sfVector2f){(rand() % 1200 + (rand() % 1500 + 1500)), 0};
        if (i != 0 and jam->jam_p.waste_bags[i].initial_pos.y - jam->jam_p.waste_bags[i - 1].initial_pos.y < 40)
            jam->jam_p.waste_bags[i].initial_pos.x += 60;
        jam->jam_p.waste_bags[i].pos = jam->jam_p.waste_bags[i].initial_pos;
        sfSprite_setPosition(jam->jam_p.waste_bags[i].sprite, jam->jam_p.waste_bags[i].pos);
    }
    while (sfRenderWindow_isOpen(jam->window)) {
        check_closing_event(jam);
        draw_elements(jam, score, fails_char, &fails);
        handle_waste_bags(jam, &fails);
        err = leave_play(jam, err, fails);
        sfRenderWindow_display(jam->window);
    }
    free(score);
    return (err);
}

int play(jam_t *jam)
{
    jam->jam_p.vacuum_texture = sfTexture_createFromFile(assets_vacuum[rand() % 7], NULL);
    if (!jam->jam_p.vacuum_texture)
        return (84);
    make_sprite(&jam->jam_p.vacuum, jam->jam_p.vacuum_texture);
    sfSprite_setOrigin(jam->jam_p.vacuum, (sfVector2f){145, 140});
    sfSprite_setPosition(jam->jam_p.vacuum, jam->jam_p.pos_vacuum);
    sfRenderWindow_setMouseCursorVisible(jam->window, sfFalse);
    for (u_int i = 0; jam->jam_p.waste_bags[i].sprite; ++i)
        sfClock_restart(jam->jam_p.waste_bags[i].clock);
    if (render_play(jam) == 84) {
        sfTexture_destroy(jam->jam_p.vacuum_texture);
        return (84);
    }
    sfSprite_destroy(jam->jam_p.vacuum);
    sfTexture_destroy(jam->jam_p.vacuum_texture);
    jam->jam_p.vacuum = NULL;
    jam->jam_p.vacuum_texture = NULL;
    return (0);
}
