/*
** EPITECH PROJECT, 2023
** BSQ
** File description:
** my_getnbr.c
*/

int my_getnbr(const char *str)
{
    long var = 0;
    int neg = 1;
    int i = 0;

    while ((*str < '0' || *str > '9') && *str != 0) {
        str = str + 1;
        i++;
    }
    if (i > 0 && *(str - 1) == '-')
        neg = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        var = var * 10;
        var = var + *str - 48;
        str = str + 1;
    }
    var = var * neg;
    if (var > 2147483647 || var < -2147483647)
        return (0);
    else
        return (var);
}
