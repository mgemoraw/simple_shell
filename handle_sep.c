#include "shell.h"

/**
 * separator - separates cmd recieved from stdin by ;
 * @input: stringfrom stdin
 * Return: parsed strings to be used as cmds
 */

char **separator(char *input)
{
	char **cmds;
	char *cmd;
	int i;
	int buff_size = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * buff_size);
	if (!cmds)
	{
		free(cmds);
		perror("hsh");
		return (NULL);
	}
	cmd = _strtok(input, ";&");
	for (i = 0; cmd; i++)
	{
		cmds[i] = cmd;
		cmd = _strtok(NULL, ";&");
	}
	cmds[i] = NULL;

	return (cmds);
}
