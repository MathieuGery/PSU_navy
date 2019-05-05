/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** reception.c
*/

#include "my.h"

void print_pid(int pid)
{
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putstr("\nwaiting for enemy connection...\n");
}

void print_pid_client(int pid)
{
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putchar('\n');
}

void message_connection(int UNUSED sig, siginfo_t *siginfo, void UNUSED *context)
{
	my_putstr("\nenemy connected\n");
	signal_r = siginfo->si_pid;
	kill(siginfo->si_pid, SIGUSR1);
}

void mss_co_client(int UNUSED sig, siginfo_t *siginfo, void UNUSED *context)
{
	my_putstr("successfully connected\n");
	signal_r = siginfo->si_pid;
}
