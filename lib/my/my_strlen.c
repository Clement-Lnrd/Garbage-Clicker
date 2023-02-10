/*
** EPITECH PROJECT, 2022
** MY_LEN
** File description:
** Function that count the number of characters in a string
*/

int my_strlen(char const *str)
{
    unsigned int i = 0;

    while (str[i])
        ++i;
    return (i);
}
