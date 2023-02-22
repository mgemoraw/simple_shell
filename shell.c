#include "shell.h"
#include "macros.h"

/**
 * main - Begin shell
 * @argc: argument number
 * @argv: arguments
 * Return: returns cond
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int count = 0, i, cond = 1, stat = 0;
	char *input, **cmd, **commands;

	if (argv[1] != NULL)
		read_file(argv[1], argv);

	signal(SIGINT, handle_signal);

	while (cond)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		history(input);
		commands = separator(input);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = parse_cmd(commands[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, input, argv, count, stat);
			}
			else if (check_builtin(cmd) == 0)
			{
				stat = handle_builtin(cmd, stat);
				free(cmd);
				continue;
			}
			else
			{
				stat = check_cmd(cmd, input, count, argv);
			}
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&stat);
	}
	return (stat);
}
