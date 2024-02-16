/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-settingup-tharek.akaichi
** File description:
** bsq.h
*/

#ifndef BQS_H_
    #define BQS_H_

typedef struct bsq_s {
    char *buffer;
    unsigned short **tab;
    int max;
    int min;
    int ay;
    int ax;
    int len;
    int value;
} bsq_t;

typedef struct {
    bsq_t *bsq;
    char *buffer;
    int *i;
    int y;
    int len;
} process_args;

void my_algo(char *tab, int h, int len);
unsigned short **create(int h, int len);
char *get_tab(char const *str);
char *my_read(int fd, char const *path);
int get_fd(char const *str);
long size_to_read(char const *path);
void free_tab_int(unsigned short **tab, int h, bsq_t *bsq);

#endif
