#include "shell.h"
/**
 * _strcpy - function that copies a string
 * @dest: destination
 * @src: source
 *
 * Return: destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: second string
 *
 * Return: concatenation of the two strings
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - function that locates character in a string
 * @s: string to be searched
 * @c: character to be located
 *
 * Return: pointer to character
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}
/**
 * _strncmp - function that compares n amount of characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: amount of characters to compare
 *
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	if (s1 == NULL)
		return (-1);

	for (index = 0; index < n && s2[index]; index++)
	{
		if (s1[index] != s2[index])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - duplicate a string
 * @str: string
 *
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *dup_str;

	len = _strlen(str);
	dup_str = malloc(sizeof(char) * (len + 1));
	if (!dup_str)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		dup_str[i] = str[i];
	}
	return (dup_str);
}
