/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** pars_map_2.c
*/

#include "my.h"

int lines_cols(map_t *map, int boat)
{
	int x = 6;
	int y = 7;

	if (boat == 2) {
		x = 2;
		y = 3;
	} else if (boat == 3) {
		x = 4;
		y = 5;
	} else {
		x = 6;
		y = 7;
	}
	if (map->lines[x] == map->lines[y])
		return (0);
	else
		return (1);
}
