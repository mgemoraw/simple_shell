#include "shell.h"

/**
 * check_builtin - checks if parsed command in built-in
 * @cmd: parsed command to check
 *
 * Return: 0 (Success) -1 (Fail)
 */

int check_builtin(char **cmd)
{
	builtin buls[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((buls + i)->command)
	{
		if (_strcmp(cmd[0], (buls + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin - handles built in commands
 * @cmd: command strings
 * @st: status of last execution
 *
 * Return: -1 Failure 0 Success
 */

int handle_builtin(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", ch_dir},
		{"env", display_env},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exit_bul - exit status for built-in commands
 * @cmd: array of parsed command strings
 * @input: input recieved from user
 * @argv: arguments before program starts
 * @c: Shell execution count
 * @stat: exit status
 */

void exit_bul(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				_prerror(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);
		}
	}
}
