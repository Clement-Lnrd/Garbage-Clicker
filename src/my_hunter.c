/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** my_hunter
*/

#include "../include/my_hunter.h"

int my_hunter(int ac, char **av, char **env)
{
    if (env[0] == NULL) {
        write(2, "Please launch this program with an environment!\n", 48);
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    } else if (check_files() == 0)
        return (title_screen());
    return (84);
}
