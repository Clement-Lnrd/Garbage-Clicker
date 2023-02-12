/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** waste_bags
*/

#include "../../include/epi_jam.h"

void waste_bags_pick_up(jam_t *jam, sfVector2f fpos, unsigned int *fails, u_int i)
{
    sfFloatRect bag_rect = sfSprite_getGlobalBounds(jam->jam_p.waste_bags[i].sprite);

    sfSprite_setPosition(jam->jam_p.waste_bags[i].sprite, (sfVector2f){bag_rect.left, bag_rect.top});
    if ((sfFloatRect_contains(&bag_rect, fpos.x, fpos.y)
        && jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
        || jam->jam_p.waste_bags[i].pos.x >= 1920) {
        sfClock_restart(jam->jam_p.waste_bags[i].clock);
        jam->jam_p.waste_bags[i].initial_pos.y = (rand() % 880);
        jam->jam_p.waste_bags[i].initial_pos.x = (rand() % 1500 * -1);
        jam->jam_p.waste_bags[i].pos.y = jam->jam_p.waste_bags[i].initial_pos.y;
        if (i != 0 and jam->jam_p.waste_bags[i].initial_pos.y - jam->jam_p.waste_bags[i - 1].initial_pos.y < 40)
            jam->jam_p.waste_bags[i].initial_pos.x += 60;
        (jam->jam_p.waste_bags[i].pos.x >= 1920) ? (++(*fails)) : (++jam->score);
    }
}
