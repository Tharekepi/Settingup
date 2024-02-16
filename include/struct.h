/*
** EPITECH PROJECT, 2023
** BSQ
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct {
    int max;
    int l;
    int c;
}coord_t;

typedef struct {
    char **map;
    int **map2;
    int rows;
    int cols;
}map_t;

#endif
