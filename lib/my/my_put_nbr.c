/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** display number
*/

#include "my.h"

void my_put_nbr(int nb)
{
	int unit = 0;
	
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 10) {
		unit = nb % 10;
		nb = (nb - unit) / 10;
		my_put_nbr(nb);
		my_putchar(48 + unit);
	}else
		my_putchar(48 + nb);
}
