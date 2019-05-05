/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** usage.c
*/

#include "my.h"

void usage(void)
{
	my_putstr("USAGE\n");
	my_putstr("     ./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("     first_player_id: only for the 2nd player. pid of the ");
	my_putstr("first player.\n     navy_positions: file representing the ");
	my_putstr("positions of the ships.\n");
}
