/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** int_to_char.c
*/

#include "my.h"

char int_to_char(int i)
{
	char c;

	for (int n = 0; i != n; n++)
		c = 'A' + n;
	return (c);
}
