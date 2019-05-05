/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** place_boats.c
*/

#include "my.h"

int place_first_boat(map_t *map)
{
	if (map->map[map->lines[0]][map->cols[0]] == '.' &&
	    map->map[map->lines[1]][map->cols[1]] == '.') {
		map->map[map->lines[0]][map->cols[0]] = '2';
		map->map[map->lines[1]][map->cols[1]] = '2';
		return (0);
	}
	else
		return (84);
}

int place_sc_boat(map_t *map, int pos_x, int UNUSED pos_y, int boat)
{
	if (lines_cols(map, boat) == 0) {
		for (int i = 0; i < boat + 1; i++)
			map->map[map->lines[pos_x]][map->cols[pos_x] + i] = '3';

	} else {
		for (int i = 0; i < boat + 1; i++)
			map->map[map->lines[pos_x] + i][map->cols[pos_x]] = '3';

	}
	return (84);
}

int place_th_boat(map_t *map, int pos_x, int UNUSED pos_y, int boat)
{
	if (lines_cols(map, boat) == 0) {
		for (int i = 0; i < boat + 1; i++)
			map->map[map->lines[pos_x]][map->cols[pos_x] + i] = '4';

	} else {
		for (int i = 0; i < boat + 1; i++)
			map->map[map->lines[pos_x] + i][map->cols[pos_x]] = '4';

	}
	return (84);
}

int place_last_boat(map_t *map, int pos_x, int UNUSED pos_y, int boat)
{
	if (lines_cols(map, boat) == 0) {
		for (int i = 0; i < boat + 1; i++)
			map->map[map->lines[pos_x]][map->cols[pos_x] + i] = '5';

	} else {
		for (int i = 0; i < boat + 1; i++)
			map->map[map->lines[pos_x] + i][map->cols[pos_x]] = '5';

	}
	return (84);
}
