/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** check_files
*/

#include "../../include/epi_jam.h"

static const char *assets[] = {"assets/textures/background.png",
    "assets/textures/dementors.png", "assets/textures/vacuum.png",
    "assets/sounds/musics/hp_theme.ogg", "assets/fonts/marvel.ttf",
    "assets/textures/game_background.png", "assets/textures/htp.png", 0};

static void check_stats(unsigned int *err)
{
    int fd;
    FILE *file;

    fd = open("data/stats", O_RDWR);
    if (fd == -1) {
        my_putstr("[+] Creating statistics file");
        my_putstr(": doesn't exist or can't open it\n");
        file = fopen("data/stats", "w+");
        if (file == NULL) {
            write(2, "[ERROR] Unable to create data/stats!\n", 38);
            (*err) = 84;
        } else
            fclose(file);
    } else
        close(fd);
}

static void check_settings(unsigned int *err)
{
    int fd;
    FILE *file;

    fd = open("data/settings", O_RDWR);
    if (fd == -1) {
        my_putstr("[+] Creating settings file");
        my_putstr(": doesn't exist or can't open it\n");
        file = fopen("data/settings", "w+");
        if (file == NULL) {
            write(2, "[ERROR] Unable to create data/settings!\n", 41);
            (*err) = 84;
        } else
            fclose(file);
    } else
        close(fd);
}

int check_files(void)
{
    unsigned int err = 0;
    int fd;

    check_stats(&err);
    check_settings(&err);
    for (int i = 0; assets[i]; ++i) {
        fd = open(assets[i], O_RDONLY);
        if (fd == -1) {
            write(2, "[ERROR] Unable to open/find ", 28);
            write(2, assets[i], my_strlen(assets[i]));
            write(2, "!\n", 2);
            err = 84;
        } else
            close(fd);
    }
    return (err);
}
