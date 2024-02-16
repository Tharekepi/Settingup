/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-settingup-tharek.akaichi
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/bsq.h"

unsigned short **create(int h, int len)
{
    unsigned short **tab = malloc(sizeof(unsigned short *) * (h + 1));

    if (tab == NULL)
        exit(84);
    for (int i = 0; i <= h; i++) {
        tab[i] = malloc(sizeof(unsigned short) * (len + 1));
        if (tab[i] == NULL)
            exit(84);
    }
    return (tab);
}

int len_second_line(char const *str)
{
    int i = 0;

    while (str[i] != '\n' && str[i] != '\0')
        i++;
    i++;
    return i;
}

int check_board(char *str, int i)
{
    int j = 0;

    while (str[j] && str[j] != '\n') {
        if (str[j] < '0' || str[j] > '9')
            return 84;
        j++;
    }
    if (my_getnbr(str) < 0)
        return 84;
    j = i;
    while (str[j]) {
        if (str[j] != '.' && str[j] != '\n' && str[j] != 'o')
            return 84;
        j++;
    }
    return 0;
}

int main(int ac, char **av)
{
    char *board = NULL;
    int i = 0;

    if (ac != 2)
        return 84;
    board = get_tab(av[1]);
    if (board == NULL)
        return 84;
    while (board[i] != '\n')
        i++;
    i++;
    if (check_board(board, i) == 84)
        return 84;
    my_algo(board + i, my_getnbr(board) + 1, len_second_line(board + i));
    free(board);
    return 0;
}
