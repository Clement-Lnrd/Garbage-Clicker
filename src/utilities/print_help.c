/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** print_help
*/

#include "../../include/my_hunter.h"

sc char *help[] = {"______  ___            ______  __             _____\n"
    , "___   |/  /____  __    ___  / / /___  __________  /_____________\n"
    , "__  /|_/ /__  / / /    __  /_/ /_  / / /_  __ \\  __/  _ \\_  ___/\n"
    , "_  /  / / _  /_/ /     _  __  / / /_/ /_  / / / /_ /  __/  /\n"
    , "/_/  /_/  _\\__, /      /_/ /_/  \\__,_/ /_/ /_/\\__/ \\___//_/\n"
    , "          /____/\n\n"
    , "A little history: Duck Hunt is a pistol shooting video game"
    , " developed and edited by Nintendo.\n\n"
    , "The game: dementors appear randomly on the screen and fly from left to"
    , "right.\nYou must click on the ennemies with the magic wand to kill them."
    , "\nIf 3 of the dementors go out of the screen at the right, you lose!\n"
    , "\nPress <ESC> to go back on the title screen when you are in a menu."
    , "\nClick with the top of the magic wand on the dementors to kill them."
    , "\n\n▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n\n"
    , "My Hunter V1.0.1\n"
    , "Copyright (C) 2022 Clément Liénard\n\nWritten by Clément Liénard\n", 0};

void print_help(void)
{
    for (int i = 0; help[i]; ++i)
        my_putstr(help[i]);
}
