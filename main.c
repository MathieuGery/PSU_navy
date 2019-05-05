/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
	if (ac != 1 || ac > 3) {
		if (str_cmp(av[1], "-h") == 0) {
			usage();
			return (0);
		}
		if (ac == 2)
			return (server(av[1]));
		if (ac == 3)
			return (client(av));
	} else
		return (84);
	return (0);
}
