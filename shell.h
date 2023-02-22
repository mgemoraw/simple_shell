#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/* MACROS */

#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void rev_array(char *arr, int len);
int int_len(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

char *_strtok(char *line, char *delim);
char *_getline();
char *enter(char *string);
char *space(char *str);
void comment_handler(char *buff);

char **parse_cmd(char *input);

int ch_dir(char **cmd, __attribute__((unused))int st);
int display_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st);
int echo_bul(char **cmd, int st);
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int st);

extern char **environ;

int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);

void free_env(char **env);
void create_env(char **env);

void print_error(char *input, int count, char **argv);
void _prerror(char **argv, int count, char **cmd);
void error_file(char **argv, int count);

void read_file(char *file, char **argv);
void exit_for_file(char **cmd, char *line, FILE *fd);
void parse_file(char *line, int count, FILE *fp, char **argv);

char *_memcpy(char *dest, char *src, unsigned int n);
void free_all(char **cmd, char *line);
void *fill(void *a, int el, unsigned int len);
void *_calloc(unsigned int size);

char *_getenv(char *name);
char *build(char *token, char *value);
int path_cmd(char **cmd);

int print_echo(char **cmd);
void print_number(unsigned int n);
void print_number_int(int n);

void prompt(void);

int history(char *input);
char **separator(char *input);

int check_cmd(char **cmd, char *input, int c, char **argv);
void handle_signal(int sig);

/**
 * struct _builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*SHELL_H*/
