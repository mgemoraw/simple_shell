#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * struct Info - structue info
 * @argc: argument counter
 * @argv: arguemnt vector
 * @env: environment variable pointer
 */
typedef struct Info
{
	int *argc;
	char *argv;
	char *env;
} info_t;

int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);


#endif

