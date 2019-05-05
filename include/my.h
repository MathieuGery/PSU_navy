/*
** EPITECH PROJECT, 2018
** mathieu gery & benjamin dupuis
** File description:
** navy.h
*/

#include "get_next_line.h"
#include "lib.h"
#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#define UNUSED __attribute__((unused))
int signal_r;
void usage(void);
void message_connection(int, siginfo_t *, void *);
int client(char **);
int server(char *);
int *map_number(char *);
void print_map(char **);
char **fill_map(void);
int place_first_boat(map_t *);
int place_sc_boat(map_t *, int, int, int);
int place_th_boat(map_t *, int, int, int);
int place_last_boat(map_t *, int, int, int);
int place_cols(map_t *, int);
int lines_cols(map_t *, int);
void print_game(map_t *);
int game_init(map_t *, char *);
int map_define(map_t *, char *);
int game_loop(map_t *, signal_t *);
void print_pid(int);
int check(char *);
int game_c(signal_t *, map_t *);
int attack_pos(signal_t *);
char int_to_char(int);
void print_coord(signal_t *, map_t *);
int is_touch(int *, map_t *);
void send_pos(signal_t *, int *);
void print_pid_client(int);
int *prompt_game(int *);
int error_gesture(map_t *);
void mss_co_client(int , siginfo_t *,void *);
int hit(int, int, map_t *);
int check_win(map_t *);
