/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** win.c
*/

#include "my.h"

int check_win(map_t *map)
{
	int res = 0;

	for (int i = 0; i < 8; i++) {
		for (int n = 0; n < 8; n++)
			if (map->map[i][n] == 'x')
				res++;
	}
	if (res == 14)
		return (1);
	res = 0;
	for (int i = 0; i < 8; i++) {
		for (int n = 0; n < 8; n++)
			if (map->map2[i][n] == 'x')
				res++;
	}
	if (res == 14)
		return (2);
	return (0);
}
