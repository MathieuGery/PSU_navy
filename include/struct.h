/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** struct.h
*/

typedef struct
{
	char **map;
	char **map2;
	int *cols;
	int *lines;
}map_t;

typedef struct
{
	int pos_x;
	int pos_y;
	int pid;
}signal_t;
