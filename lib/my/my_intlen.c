/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** my_intlen
*/

int my_intlen(int nb)
{
    int len = 0;

    if (nb == 0)
        ++len;
    for (; nb != 0; ++len)
        nb /= 10;
    return (len);
}
