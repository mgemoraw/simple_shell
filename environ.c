#include "shell.h"
#include "macros.h"

/**
 * create_env - creates an array of environment vars
 * @env: array to store environment variables
 */

void create_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strdup(environ[i]);
	env[i] = NULL;
}

/**
 * free_env - frees the memory created by the environment vars
 * @env:  array of Environment variables
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
