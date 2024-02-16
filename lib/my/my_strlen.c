/*
** EPITECH PROJECT, 2023
** BSQ
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int j = 0;

    while (str[j] != '\0')
        j++;
    return (j);
}
