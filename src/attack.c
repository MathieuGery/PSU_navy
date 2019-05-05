/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** attack.c
*/

#include "my.h"

int hit(int y, int x, map_t *map)
{
	if (map->map[x - 1][y - 1] != '.' && map->map[x - 1][y - 1] != 'o')
		return (0);
	return (1);
}
