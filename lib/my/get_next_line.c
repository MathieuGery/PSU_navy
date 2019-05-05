/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** get_next_line.c
*/

#include "get_next_line.h"

char *my_realloc(char *str, int size)
{
	char *tmp = str;

	str = malloc(sizeof(char) * size + 1);
	str = copy_str(str, tmp);

	free(tmp);
	return (str);
}

char *copy_str(char *str, char *tmp)
{
	int i = 0;

	while (tmp[i] != '\0') {
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';

	return (str);
}

char get_char(int fd)
{
	static int size_of_read;
	static char buffer[READ_SIZE];
	static char *ptr_char;
	char c;

	if (size_of_read == 0)
	{
		size_of_read = read(fd, buffer, READ_SIZE);
		ptr_char = (char*)&buffer;
		if (size_of_read == 0)
			return ('\0');
	}
	c = *ptr_char;
	ptr_char++;
	size_of_read--;

	return (c);
}

char *get_next_line(int fd)
{
	int size = 0;
	char c = get_char(fd);
	char *str = malloc(sizeof(char) * (READ_SIZE + 1));

	while (c != '\n' && c != '\0') {
		str[size] = c;
		c = get_char(fd);
		if (size % (READ_SIZE) == 0)
			str = my_realloc(str, size + READ_SIZE + 1);
		size++;
	}
	str[size] = '\0';
	if (c == '\0' && str[0] == '\0')
		return (NULL);

	return (str);
}
