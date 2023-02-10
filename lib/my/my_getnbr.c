/*
** EPITECH PROJECT, 2022
** MY_GETNBR
** File description:
** Function that returns a number sent as a string
*/

#include "../../include/my.h"

static int get_number(char const *str, int i)
{
    int nbr = 0;

    for (; str[i] >= '0' && str[i] <= '9'; ++i) {
        nbr *= 10;
        nbr += str[i] - '0';
    }
    return (nbr);
}

static int less(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; ++i)
        if (str[i] == '-')
            ++count;
    if (count % 2 == 0)
        return (1);
    return (0);
}

static int is_overflow(char const *str, int i)
{
    int numbers = 0;
    int j = i;
    char tmp[11];

    for (; str[i] >= '0' && str[i] <= '9'; ++i) {
        tmp[numbers] = str[i];
        ++numbers;
        if (numbers > 10 || (numbers == 10 && str[j] > '2'))
            return (1);
    }
    tmp[numbers] = 0;
    if (my_strcmp(tmp, "2147483648") > 0 && less(str) == 0 && numbers >= 10)
        return (1);
    if (my_strcmp(tmp, "2147483647") > 0 && less(str) == 1 && numbers >= 10)
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    for (; str[i]; ++i) {
        if (str[i] >= '0' && str[i] <= '9')
            break;
        if (str[i] != '+' && str[i] != '-')
            return (0);
    }
    if (is_overflow(str, i) != 0)
        return (0);
    nbr = get_number(str, i);
    if (less(str) == 0)
        nbr = -nbr;
    return (nbr);
}
