/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** client.c
*/

#include "my.h"

void count_sig1(int UNUSED sig, siginfo_t UNUSED *siginfo, void UNUSED *context)
{
	signal_r = 1;
}

void count_sig2(int UNUSED sig, siginfo_t UNUSED *siginfo, void UNUSED *context)
{
	signal_r = 2;
}

int attack_pos(signal_t *s_signal)
{
	struct sigaction act;
	struct sigaction act2;
	int n = 0;

	act2.sa_sigaction = count_sig2;
	act.sa_sigaction = count_sig1;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	while (signal_r == 1) {
		pause();
		n++;
	}
	s_signal->pos_x = n - 1;
	n = 0;
	while (signal_r == 2) {
		pause();
		n++;
	}
	s_signal->pos_y = n;
	return (0);
}

int game_c(signal_t *s_signal, map_t *map)
{
	int *pos = malloc(sizeof(int) * 2);

	while (check_win(map) == 0) {
		my_putstr("waiting for enemy's attack...\n");
		attack_pos(s_signal);
		print_coord(s_signal, map);
		my_putchar('\n');
		pos = prompt_game(pos);
		if (pos == NULL)
			return (84);
		send_pos(s_signal, pos);
		is_touch(pos, map);
		print_game(map);
	}
	if (check_win(map) == 1)
		return (1);
	return (0);
}

int client(char **str)
{
	struct sigaction sig;
	signal_t s_signal;
	map_t map;

	s_signal.pid = my_getnbr(str[1]);
	game_init(&map, str[2]);
	print_pid_client(getpid());
	sig.sa_sigaction = mss_co_client;
	sigaction(SIGUSR1, &sig, NULL);
	kill(s_signal.pid, SIGUSR1);
	pause();
	signal_r = 1;
	print_game(&map);
	if (game_c(&s_signal, &map) == 0) {
		my_putstr("I won\n\n");
		return (0);
	} else {
		my_putstr("Enemy won\n\n");
		return (1);
	}
}
