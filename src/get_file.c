/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-settingup-tharek.akaichi
** File description:
** get_file.c
*/

#include "../include/my.h"
#include "../include/bsq.h"

int get_fd(char const *str)
{
    int fd = open(str, O_RDONLY);

    if (fd == -1) {
        my_putstr("Error : open fail");
        return (-1);
    }
    return (fd);
}

long read_size(char const *path)
{
    struct stat st;
    long size = 0;

    if (stat(path, &st) == 0)
        size = st.st_size;
    return (size);
}

char *read_file(int fd, char const *path)
{
    int c = 0;
    long size = read_size(path);
    char *str = malloc(sizeof(char) * (size + 2));

    str[size] = '\0';
    c = read(fd, str, size);
    if (c == -1)
        return (NULL);
    return (str);
}

char *get_tab(char const *str)
{
    int fd = get_fd(str);
    char *tab = read_file(fd, str);

    close(fd);
    return (tab);
}
