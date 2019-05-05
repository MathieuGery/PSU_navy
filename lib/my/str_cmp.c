/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** str_cmp.c
*/

#include "my.h"

int str_cmp(char *str, char *str2)
{
	int i = 0;

	while (str[i] != '\0' || str2[i] != '\0') {
		if (str[i] == str2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
