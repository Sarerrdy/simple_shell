#include "shell.h"

/**
 * str_len - Calculates the lenght of a string.
 * @str: String that needs length to be found.
 * Return: Upon success returns the length of a string. otherwise 0.
 */
int str_len(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strncpy - copy a strings
 * @dest: string to store copied string
 * @src: string to be copied
 *
 * Return: a pointer to the copied string.
 */

char *_strncpy(char *dest, char *src)
{
	size_t i;
	size_t n;

	n = str_len(src) + 1;
	dest = malloc(n);

	for (i = 0; i < n && src[i] != '\0'; i++)
	dest[i] = src[i];
	for ( ; i < n; i++)
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp(char *str1, char *str2)
{

	int i;

	if (str_len(str1) != str_len(str2))
		return (-1);
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}

/**
 * _putchar - Writes a character to stdout
 * @c: Character that will be written to stdout
 *
 * Return: Upon success how many characters were written.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * Print_char - prints string
 * followed by a new line
 * @str: string to be printed
 */
void Print_char(char *str)
{
	int len, i;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}
}
