/*
** EPITECH PROJECT, 2018
** mathieu gery
** File description:
** get_next_line.h
*/

#ifndef READ_SIZE
#define READ_SIZE (5)
#endif

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *copy_str(char *str, char *tmp);
char *get_next_line(int);
