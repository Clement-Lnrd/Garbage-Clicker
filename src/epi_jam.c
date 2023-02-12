/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** epi_jam
*/

#include "../include/epi_jam.h"

int jam(__attribute__((unused)) int ac, __attribute__((unused)) char **av,
    char **env)
{
    if (env[0] == NULL) {
        write(2, "Please launch this program with an environment!\n", 48);
        return (84);
    }
    if (check_files() == 0)
        return (title_screen());
    return (84);
}
