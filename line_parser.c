#include "shell.h"
#include "macros.h"

/**
 * parse_cmd - parses the command recieved from stdin
 * @input: string entered stdin
 *
 * Return: parsed strings aka tokens
 */

char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i;
	int buff_size = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buff_size);
	if (!tokens)
	{
		free(tokens);
		perror("hsh");
		return (NULL);
	}
	token = _strtok(input, "\n\t\r\a ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n\t\r\a ");
	}
	tokens[i] = NULL;

	return (tokens);
}
