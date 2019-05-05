/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** send.c
*/

#include "my.h"

void send_pos(signal_t *s_signal, int *pos)
{
	for (int i = 0; i < pos[0]; i++) {
		kill(s_signal->pid, SIGUSR1);
		usleep(100);
	}
	for (int i = 0; i < pos[1]; i++) {
		kill(s_signal->pid, SIGUSR2);
		usleep(100);
	}
	kill(s_signal->pid, SIGUSR1);
}
