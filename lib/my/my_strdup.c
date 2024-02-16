/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-settingup-tharek.akaichi
** File description:
** my_strdup.c
*/

int my_strdup(char *src)
{
    int i = 0;
    int len = 0;
    char *dest;

    while (src[len] != '\0')
        len++;
    dest = malloc(sizeof(char) * (len + 1));
    while (i < len) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
