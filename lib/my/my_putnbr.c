/*
** EPITECH PROJECT, 2023
** BSQ
** File description:
** my_putnbr.c
*/


int my_putnbr(int nb)
{
    int n = nb;
    int d = 1;

    if (nb < 0) {
        my_putchar('-');
        n = - nb;
    }
    while (d <= n)
        d *= 10;
    d = d / 10;
    while (d) {
        my_putchar((n / d) % 10 + '0');
        d /= 10;
    }
}

void my_putnbr_base_bis(int i, int j, char buffer[32])
{
    i = j - 1;
    while (i >= 0) {
        my_putchar(buffer[i]);
        i--;
    }
}

void my_putnbr_base(int num, int base)
{
    char buffer[32];
    int j = 0;
    int d;
    int i;

    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num == 0) {
        my_putchar('0');
        return;
    }
    while (num > 0) {
        d = num % base;
        buffer[j] = (d < 10) ? (d + '0') : ('A' + d - 10);
        num /= base;
        j++;
    }
    my_putnbr_base_bis(i, j, buffer);
}
