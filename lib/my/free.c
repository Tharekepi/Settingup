/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-settingup-tharek.akaichi
** File description:
** free.c
*/

#include "../../include/my.h"
#include "../../include/bsq.h"

void free_tab(char **tab)
{
    int i = 0;

    while (tab) {
        while (tab[i]){
            free(tab[i]);
            i++;
        }
    }
    free(tab);
}

void free_express(int *t, char **numbers)
{
    free(t);
    free_tab(numbers);
}

void free_tab_int(unsigned short **tab, int h, bsq_t *bsq)
{
    int i = 0;

    if (tab == NULL)
        exit(84);
    while (i <= h) {
        free(tab[i]);
        i++;
    }
    free(tab);
    free(bsq->buffer);
    free(bsq);
}
