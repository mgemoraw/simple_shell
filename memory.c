#include "shell.h"
#include "macros.h"


/**
 * free_all - free memory allocated
 * @cmd: array pointer
 * @line: char pointer
 *
 * Return: Void
 */

void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copy bytes of memory from source to destination
 * @dest: destination pointer
 * @src: source pointer
 * @n: size to be copied
 *
 * Return: pointer to destination
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill - fills an array by constant byte
 * @a: void pointer
 * @el: int
 * @len: length for int
 * Return: void pointer
 */

void *fill(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _realloc -  reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old: previous size Of The Pointer
 * @new: new size of the pointer
 * Return: Pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	void *res;

	if (new == old)
		return (ptr);
	if (new == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(new);
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill(res, '\0', new);
		free(ptr);
	}
	else
	{
		_memcpy(res, ptr, old);
		free(ptr);
	}
	return (res);
}

/**
 * _calloc - allocates memory for an array using malloc
 * @size: size
 * Return: void pointer
 */

void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
