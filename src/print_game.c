/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** game.c
*/

#include "my.h"

int game_init(map_t *map, char *av)
{
	if (map_define(map, av) != 0)
		return (84);
	map->map2 = fill_map();
	return (0);
}

void print_game(map_t *map)
{
	my_putstr("\nmy positions:\n");
	print_map(map->map);
	my_putstr("\nenemy's positions:\n");
	print_map(map->map2);
	my_putchar('\n');
}

int *prompt_game(int *pos)
{
	char *s;
	int i;

	my_putstr("attack: ");
	s = get_next_line(0);
	if (s == NULL)
		return (NULL);
	while (check(s) != 0) {
		my_putstr("attack: ");
		s = get_next_line(0);
	}
	for (i = 0; s[0] != (65 + i); i++);
	pos[0] = i + 1;
	pos[1] = s[1] - '0';;
	return (pos);
}

void print_coord(signal_t *signal, map_t *map)
{
	char s = int_to_char(signal->pos_x);

	my_putchar(s);
	my_put_nbr(signal->pos_y);
	my_putstr(": ");
	if (hit(signal->pos_x, signal->pos_y, map) == 0) {
		my_putstr("hit\n");
        map->map[signal->pos_y - 1][signal->pos_x - 1] = 'x';
		kill(signal->pid, SIGUSR1);
	} else {
		my_putstr("missed\n");
        map->map[signal->pos_y - 1][signal->pos_x - 1] = 'o';
		kill(signal->pid, SIGUSR2);
	}
}
