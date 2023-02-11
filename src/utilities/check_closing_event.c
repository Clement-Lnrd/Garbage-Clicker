/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** check_closing_event
*/

#include "../../include/epi_jam.h"

void check_closing_event(jam_t *jam)
{
    while (sfRenderWindow_pollEvent(jam->window, &jam->event))
        if (jam->event.type == sfEvtClosed)
            sfRenderWindow_close(jam->window);
}
