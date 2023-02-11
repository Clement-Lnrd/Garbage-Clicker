/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** waste_bags
*/

#include "../../include/epi_jam.h"

void waste_bags_pick_up(jam_t *jam, sfVector2f fpos, sfVector2f *dpos
    , unsigned int *fails)
{
    sfFloatRect kpos = sfSprite_getGlobalBounds(jam->jam_p.waste_bags[0]);
    sfVector2f pos = {fpos.x + 5, fpos.y + 5};
    sfVector2f tmp = {kpos.left, kpos.top};

    sfSprite_setPosition(jam->jam_p.waste_bags[0], tmp);
    if ((sfFloatRect_contains(&kpos, pos.x, pos.y)
        && jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
        || dpos->x >= 1920) {
        sfClock_restart(jam->jam_p.clock);
        dpos->y = (rand() % 880);
        (dpos->x >= 1920) ? (++(*fails)) : (++jam->score);
    }
}

// sfSprite_setPosition(jam->jam_p.waste_bags[0], tmp);
//     if ((sfFloatRect_contains(&kpos, pos.x, pos.y)
//         && jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
//         || dpos->y >= 1080) {
//         sfClock_restart(jam->jam_p.clock);
//         dpos->x = (rand() % 1920);
//         (dpos->y >= 1080) ? (++(*fails)) : (++jam->score);
//     }
