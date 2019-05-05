/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** str_to_word_array
*/

#include "my.h"

int size_len(char *str)
{
	int i = 0;
	int ret = 0;

	while (str[i] != '\0') {
		if (str[i] == ':' || str[i] == '\t' && str[i + 1] != '\0')
			ret++;
		i++;
	}
	return (ret + 1);
}

int is_alphanum(char c)
{
	if (c <= ':' || c >= 127)
		return (0);
	else
		return (1);
}

char *my_strcpy(char *str, char *str2, int size)
{
	int i = 0;

	while (str2[i] != '\0' && i < size) {
		str[i] = str2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char **str_to_word_array(char *str)
{
	int x = 0;
	int i = 0;
	int size = 0;
	char **arr = malloc(sizeof(char *) * (size_len(str) + 1));

	while (str != NULL && str[i]) {
		if (is_alphanum(str[i]))
			size++;
		if (is_alphanum(str[i]) == 1 && is_alphanum(str[i + 1]) == 0) {
			arr[x] = malloc(sizeof(char) * (size + 1));
			my_strcpy(arr[x], &str[i - size + 1], size);
			size = 0;
			x++;
		}
		i++;
	}
	arr[x] = NULL;
	return (arr);
}
