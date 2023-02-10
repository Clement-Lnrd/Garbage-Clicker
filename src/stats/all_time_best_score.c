/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** all_time_best_score
*/

#include "../../include/my_hunter.h"

long long int get_best_score(void)
{
    int fd = open("data/stats", O_RDWR);
    char buffer[21];
    long long int score;
    int i = 0;

    read(fd, buffer, 21);
    for (; buffer[i] != '\n' && buffer[i]; ++i);
    buffer[i] = 0;
    close(fd);
    score = my_getnbr(buffer);
    return (score);
}

void all_time_best_score(tekleague_t *jam)
{
    FILE *file = fopen("data/stats", "w+");
    int fd = open("data/stats", O_RDWR);
    ssize_t size = my_intlen(jam->highest_score);
    char *score = malloc(sizeof(char) * 21);

    score = my_int_to_str(jam->highest_score, score);
    write(fd, score, size);
    write(fd, "\n", 1);
    free(score);
    fclose(file);
    close(fd);
}
