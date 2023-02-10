/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** my_int_to_str
*/

#include "../../include/my.h"

char *my_int_to_str(long long int nb, char *str)
{
    int i = (my_intlen(nb) - 1);
    int len = (i + 1);

    for (; i >= 0; --i) {
        str[i] = ((nb % 10) + '0');
        nb /= 10;
    }
    str[len] = 0;
    return (str);
}
