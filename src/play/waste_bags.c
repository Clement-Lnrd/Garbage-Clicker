/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** waste_bags
*/

#include <stdbool.h>
#include "../../include/epi_jam.h"

static bool contain(sfFloatRect rect, sfVector2f pos)
{
    if (pos.x >= rect.left - 40 && pos.x <= rect.left + rect.width + 40
        && pos.y >= rect.top - 20 && pos.y <= rect.top + rect.height + 20)
        return (true);
    return (false);
}

static void debug_hitbox(jam_t *jam, sfFloatRect bag_rect)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){bag_rect.left, bag_rect.top});
    sfRectangleShape_setSize(rect, (sfVector2f){bag_rect.width, bag_rect.height});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 10);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRenderWindow_drawRectangleShape(jam->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void waste_bags_pick_up(jam_t *jam, unsigned int *fails, u_int i)
{
    sfVector2f fpos = sfVector2i_to_sfVector2f(sfMouse_getPositionRenderWindow(jam->window));
    sfFloatRect bag_rect = sfSprite_getGlobalBounds(jam->jam_p.waste_bags[i].sprite);

    sfSprite_setPosition(jam->jam_p.waste_bags[i].sprite, (sfVector2f){bag_rect.left, bag_rect.top});
    if ((contain(bag_rect, fpos)
        && jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
        || jam->jam_p.waste_bags[i].pos.x >= 1920) {
        sfClock_restart(jam->jam_p.waste_bags[i].clock);
        jam->jam_p.waste_bags[i].initial_pos.y = (rand() % 880);
        jam->jam_p.waste_bags[i].initial_pos.x = (rand() % 1500 * -1);
        jam->jam_p.waste_bags[i].mov = (sfVector2f){(rand() % 1200 + (rand() % 1500 + 1500)), 0};
        jam->jam_p.waste_bags[i].pos.y = jam->jam_p.waste_bags[i].initial_pos.y;
        if (i != 0 and jam->jam_p.waste_bags[i].initial_pos.y - jam->jam_p.waste_bags[i - 1].initial_pos.y < 40)
            jam->jam_p.waste_bags[i].initial_pos.x += 60;
        (jam->jam_p.waste_bags[i].pos.x >= 1920) ? (++(*fails)) : (++jam->score);
    }
}
