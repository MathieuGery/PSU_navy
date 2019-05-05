/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** DUPUIS_Benjamin
*/

#include <stdlib.h>
int is_alpha(char c, char the_char)
{
	if (c != the_char)
		return 1;
	return 0;
}

int count_words(char *str, char the_char)
{
	int word = 0;
	int i = 0;
	int nb_words = 0;

	while (str[i])
	{
		if (word == 0 && is_alpha(str[i], the_char) == 1) {
			word = 1;
			nb_words = nb_words + 1;
		}
		if (word == 1 && is_alpha(str[i], the_char) == 0)
			word = 0;
		i++;
	}
	return nb_words;
}

void do_the_thing(char *str, char *str2, int begin, int end)
{
	int i = 0;

	while (begin <= end) {
		str2[i] = str[begin];
		begin++;
		i++;
	}
	str2[i] = '\0';
}

static void save_words(char **tab, char *str, int nb_words, char the_char)
{
	int i = 0;
	int begin = 0;
	int word_cur = 0;

	while (word_cur < nb_words)
	{
		while (str[i] && is_alpha(str[i], the_char) == 0)
			i++;
		begin = i;
		while (str[i] && is_alpha(str[i], the_char) == 1)
			i++;
		tab[word_cur] = malloc(sizeof(char) * ((i - 1) - begin + 2));
		do_the_thing(str, tab[word_cur], begin, i - 1);
		i++;
		word_cur++;
	}
}

char **my_str_to_word_array(char *str, char the_char)
{
	int nb_words = count_words(str, the_char);
	char **array = malloc(sizeof(char *) * nb_words + 1);

	save_words(array, str, nb_words, the_char);
	array[nb_words] = NULL;
	return array;
}
