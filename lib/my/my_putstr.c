/*
** EPITECH PROJECT, 2023
** BSQ
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int j = 0;

    while (str[j] != '\0') {
        my_putchar(str[j]);
        j++;
    }
    return 0;
}
