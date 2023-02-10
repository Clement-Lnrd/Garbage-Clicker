/*
** EPITECH PROJECT, 2022
** MY_PUTSTR
** File description:
** Function that displays 1-by-1 the chars of a string
*/

#include "../../include/my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
