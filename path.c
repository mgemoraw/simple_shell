#include "shell.h"

/**
 * build - build command
 * @token: executable command
 * @val: directory containing command
 *
 * Return: Parsed full path of command or NULL if failed
 */

char *build(char *token, char *val)
{
	char *cmd;
	size_t len;

	len = _strlen(val) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, val);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * _getenv - gets the val of environment variable by name
 * @name: environment variable name
 *
 * Return: the val of the environment variable or NULL if failed
 */

char *_getenv(char *name)
{
	size_t name_len, val_len;
	char *val;
	int i, j, k;

	name_len = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			val_len = _strlen(environ[i]) - name_len;
			val = malloc(sizeof(char) * val_len);
			if (!val)
			{
				free(val);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				val[j] = environ[i][k];
			}
			val[j] = '\0';

			return (val);
		}
	}
	return (NULL);
}

/**
 * path_cmd -  search In $PATH for executable command
 * @cmd: parsed input
 * Return: 0 on success
 */

int path_cmd(char **cmd)
{
	char *path, *val, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	val = _strtok(path, ":");
	while (val != NULL)
	{
		cmd_path = build(*cmd, val);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		val = _strtok(NULL, ":");
	}
	free(path);
	free(val);
	return (1);
}
