/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** pars_map.c
*/

#include "my.h"

int *char_to_int(char **arr)
{
	int *num = malloc(sizeof(int) * 8);
	int n = 0;

	for (int i = 0; i < 8; i++) {
		for (n = 0; arr[i][0] != (65 + n); n++);
		num[i] = n;
		n = 0;
	}
	return (num);
}

int *pars_map(char *file, map_t *map)
{
	char **arr;
	int *cols;
	char buffer[400];
	int fd = open(file, O_RDONLY);

	read(fd, buffer, 400);
	arr = str_to_word_array(buffer);
	cols = char_to_int(arr);
	map->lines = map_number(buffer);
	return (cols);
}

int *map_number(char *buffer)
{
	int *num = malloc(sizeof(int) * 8);
	int n = 3;

	for (int i = 0; i < 8; i++) {
		num[i] = my_getnbr(buffer + n);
		if (n == 6 || n == 14 || n == 22)
			n = n + 5;
		else
			n = n + 3;
	}
	for (int i = 0; i < 8; i ++)
		num[i] -= 1;
	return (num);
}

int map_define(map_t *map, char *str)
{
	map->map = fill_map();
	map->cols = pars_map(str, map);
	if (error_gesture(map) != 0)
		return (84);
	place_first_boat(map);
	place_sc_boat(map, 2, 3, 2);
	place_th_boat(map, 4, 5, 3);
	place_last_boat(map, 6, 7, 4);
	return (0);
}
