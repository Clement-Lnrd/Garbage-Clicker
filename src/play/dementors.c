/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** dementors
*/

#include "../../include/epi_jam.h"

void animate_dementor(jam_t *jam, sfTime time)
{
    if (time.microseconds % 100 > 0 && time.microseconds % 100 < 201) {
        jam->jam_p.dementors.left = (jam->jam_p.dementors.left + 118) % 708;
        sfSprite_setTextureRect(jam->jam_p.dementor, jam->jam_p.dementors);
    }
}

void dementor_kill(jam_t *jam, sfVector2f fpos, sfVector2f *dpos
    , unsigned int *fails)
{
    sfFloatRect kpos = sfSprite_getGlobalBounds(jam->jam_p.dementor);
    sfVector2f pos = {fpos.x + 5, fpos.y + 5};
    sfVector2f tmp = {kpos.left, kpos.top};

    sfSprite_setPosition(jam->jam_p.dementor, tmp);
    if ((sfFloatRect_contains(&kpos, pos.x, pos.y)
        && jam->event.type == sfEvtMouseButtonPressed && jam->event.mouseButton.button == sfMouseLeft)
        || dpos->x >= 1920) {
        sfClock_restart(jam->jam_p.clock);
        dpos->y = (rand() % 880);
        (dpos->x >= 1920) ? (++(*fails)) : (++jam->score);
    }
}
