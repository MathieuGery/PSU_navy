/*
** EPITECH PROJECT, 2018
** navy
** File description:
** DUPUIS_Benjamin && GERY_Mathieu
*/

#include "my.h"

int error_gesture(map_t *map)
{
	for (int i = 0; i < 8; i++)
		if (0 > map->cols[i] || map->cols[i] > 7)
			return (84);
	for (int i = 0; i < 8; i++)
		if (0 > map->lines[i] || map->lines[i] > 7)
			return (84);
	return (0);
}
