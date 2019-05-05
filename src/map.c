/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** map.c
*/

#include "my.h"

void print_map(char **arr)
{
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");

	for (int i = 0; i < 8; i++) {
		my_put_nbr(i + 1);
		my_putchar('|');
		for (int n = 0; n < 8; n++) {
			my_putchar(arr[i][n]);
			if (n != 7)
				my_putchar(' ');
		}
		my_putchar('\n');
	}
}

char **fill_map(void)
{
	char **arr = malloc(sizeof(char *) * 9);

	for (int i = 0; i < 8; i++) {
		arr[i] = malloc(sizeof(char) * 9);
		for (int n = 0; n < 8; n++)
			arr[i][n] = '.';
		arr[i][8] = '\0';
	}
	arr[8] = NULL;
	return (arr);
}
