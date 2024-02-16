/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-settingup-tharek.akaichi
** File description:
** my_algo.c
*/

#include "../include/my.h"
#include "../include/bsq.h"
static bsq_t *global_bsq;

void my_memset(bsq_t *bsq, char *buffer)
{
    bsq->buffer = my_strdup(buffer);
    bsq->ax = 0;
    bsq->ay = 0;
    bsq->max = 0;
    bsq->min = 0;
    bsq->value = 0;
}

int minint(int a, int b, int c)
{
    int min = a;

    if (min > b)
        min = b;
    if (min > c)
        min = c;
    return min;
}

static void buf_print_if(char *buf, int j)
{
    if (buf[j] != '\n' && buf[j] != 'o')
        buf[j] = 'x';
}

void change_buff_print(char *buf, int max, int len, int j)
{
    int y = 0;
    int x;

    while (y < max) {
        x = 0;
        while (x < max) {
            buf_print_if(buf, j);
            x++;
            j--;
        }
        j = j + max - len;
        y++;
    }
    my_putstr(buf);
}

static void my_algo_next(bsq_t *bsq, int y, int i, int x)
{
    if (bsq->buffer[i] == '.' && y >= 1 && x >= 1) {
        bsq->min = minint(bsq->tab[y - 1][x], bsq->tab[y][x - 1],
        bsq->tab[y - 1][x - 1]);
        bsq->tab[y][x] = bsq->min + 1;
        bsq->value = bsq->min + 1;
        if (bsq->max < bsq->value) {
            bsq->max = bsq->value;
            bsq->ax = x;
            bsq->ay = y;
        }
    }
}

bsq_t *initialize_bsq(char *buffer, int h, int len)
{
    global_bsq = malloc(sizeof(bsq_t));
    global_bsq->tab = create(h, len);
    global_bsq->len = len;
    my_memset(global_bsq, buffer);
    return global_bsq;
}

static void process_cell(char cell, int y, int x, int *i)
{
    bsq_t *bsq = global_bsq;

    switch (cell) {
        case '\n':
            (*i)++;
            break;
        case 'o':
            bsq->tab[y][x] = 0;
            break;
        default:
            my_algo_next(bsq, y, *i, x);
    }
}

static void process_buffer(char *buffer, int h, int len)
{
    int i = 0;
    bsq_t *bsq = global_bsq;

    for (int y = 1; bsq->tab && y < h; ++y) {
        for (int x = 1; x < len; ++x) {
            process_cell(buffer[i], y, x, &i);
            i++;
        }
    }
}

static void finalize_bsq(int len, int h)
{
    bsq_t *bsq = global_bsq;

    change_buff_print(bsq->buffer, bsq->max,
    len, ((bsq->ax - 1) + (bsq->ay - 1) * len));
    free_tab_int(bsq->tab, h, bsq);
}

void my_algo(char *buffer, int h, int len)
{
    initialize_bsq(buffer, h, len);
    process_buffer(buffer, h, len);
    finalize_bsq(len, h);
}
