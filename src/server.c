/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** messages.c
*/

#include "my.h"

int signal_r;

void touch(int __attribute__((unused)) pid,
	   siginfo_t __attribute__((unused)) *siginfo,
	   void __attribute__((unused))  *context)
{
	my_putstr("hit\n");
	signal_r = 3;
}

void missed(int __attribute__((unused)) pid,
	    siginfo_t __attribute__((unused)) *siginfo,
	    void __attribute__((unused)) *context)
{
	my_putstr("missed\n");
	signal_r = 4;
}

int is_touch(int *pos, map_t *map)
{
	struct sigaction act;
	struct sigaction act2;
	char s = int_to_char(pos[0]);

	act.sa_sigaction = touch;
	act2.sa_sigaction = missed;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	my_putchar(s);
	my_put_nbr(pos[1]);
	my_putstr(": ");
	pause();
	if (signal_r == 3)
		map->map2[pos[1] - 1][pos[0] - 1] = 'x';
	if (signal_r == 4)
		map->map2[pos[1] - 1][pos[0] - 1] = 'o';
	signal_r = 1;
	return (0);
}

int game_loop(map_t *map, signal_t *s_signal)
{
	int *pos = malloc(sizeof(int) *2);

	print_game(map);
	while (check_win(map) == 0) {
		pos = prompt_game(pos);
		if (pos == NULL)
			return (84);
		send_pos(s_signal, pos);
		is_touch(pos, map);
		my_putstr("\nwaiting for enemy's attack...\n");
		attack_pos(s_signal);
		print_coord(s_signal, map);
		print_game(map);
	}
	if (check_win(map) == 1)
		return (1);
	return (0);
}

int server(char *av)
{
	struct sigaction act;
	map_t map;
	signal_t s_signal;

	if (game_init(&map, av) != 0)
		return (84);
	print_pid(getpid());
	act.sa_sigaction = message_connection;
	sigaction(SIGUSR1, &act, NULL);
	pause();
	s_signal.pid = signal_r;
	signal_r = 1;
	if (game_loop(&map, &s_signal) == 0) {
		my_putstr("I won\n\n");
		return (0);
	} else {
		my_putstr("Enemy won\n\n");
		return (1);
	}
}
