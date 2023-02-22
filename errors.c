#include "shell.h"
#include "macros.h"

/**
 * print_error - displays error message
 * @input: input recieved from user
 * @count: counts shell loop
 * @argv: arguments before program starts
 */

void print_error(char *input, int count, char **argv)
{
	char *err;

	PRINT(argv[0]);
	PRINT(": ");
	err = _itoa(count);
	PRINT(err);
	free(err);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 *  _prerror - prints custom Error
 * @argv: arguments before program starts
 * @count: error Count
 * @cmd: array of parsed command strings
 */

void _prerror(char **argv, int count, char **cmd)
{
	char *err = _itoa(count);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(err);
}

/**
 * error_file - prints custom Error
 * @argv: arguments before program starts
 * @count: error Count
 */

void error_file(char **argv, int count)
{
	char *err = _itoa(count);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(err);
}

