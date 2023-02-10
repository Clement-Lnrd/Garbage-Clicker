/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** dementors
*/

#include "../../include/my_hunter.h"

void animate_dementor(my_hunter_t *mh, sfTime time)
{
    if (time.microseconds % 100 > 0 && time.microseconds % 100 < 201) {
        mh->mh_p.dementors.left = (mh->mh_p.dementors.left + 118) % 708;
        sfSprite_setTextureRect(mh->mh_p.dementor, mh->mh_p.dementors);
    }
}

void dementor_kill(my_hunter_t *mh, sfVector2f fpos, sfVector2f *dpos
    , unsigned int *fails)
{
    sfFloatRect kpos = sfSprite_getGlobalBounds(mh->mh_p.dementor);
    sfVector2f pos = {fpos.x + 5, fpos.y + 5};
    sfVector2f tmp = {kpos.left, kpos.top};

    sfSprite_setPosition(mh->mh_p.dementor, tmp);
    if ((sfFloatRect_contains(&kpos, pos.x, pos.y)
        && mh->event.type == sEMBP && mh->event.mouseButton.button == sML)
        || dpos->x >= 1920) {
        sfClock_restart(mh->mh_p.clock);
        dpos->y = (rand() % 880);
        (dpos->x >= 1920) ? (++(*fails)) : (++mh->score);
    }
}
