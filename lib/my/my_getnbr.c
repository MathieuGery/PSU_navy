/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** mathieu gery
*/

#include "my.h"

int my_getnbr(char *str)
{
	int i = 0;
	int ret = 0;

	if (str[0] == '-')
		i++;

	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
		ret = ret * 10;
		ret = ret + str[i] - '0';
		i++;
	}
	if (str[0] == '-')
		ret = ret * -1;

	return (ret);
}
