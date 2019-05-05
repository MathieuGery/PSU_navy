/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** check.c
*/

#include "my.h"

int check(char *str)
{
	if (my_strlen(str) != 2) {
		my_putstr("wrong position\n");
		return (1);
	}
	if (str[0] > 'H' || str[0] < 'A') {
		my_putstr("wrong position\n");
		return (1);
	}
	if (str[1] < '1' || str[1] > '8') {
		my_putstr("wrong position\n");
		return (1);
	}
	return (0);
}
