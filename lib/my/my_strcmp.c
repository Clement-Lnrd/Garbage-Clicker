/*
** EPITECH PROJECT, 2022
** MY_STRCMP
** File description:
** Reproduce of the strcmp function
*/

int my_strcmp(char const *s1, char const *s2)
{
    int diff = 0;
    int i;

    for (i = 0; s1[i] && s2[i]; ++i) {
        diff += s1[i] - s2[i];
        if (diff != 0)
            break;
    }
    diff += s1[i] - s2[i];
    return (diff);
}
