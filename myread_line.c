#include "shell.h"

/**
 * myread_line - stores user input command in a buffer for manipulation
 *
 * Return: buffer containing user input
 */

char *myread_line(void)
{
	char *input = NULL;
	ssize_t len = 0;
	size_t bufsiz = 0;

	len =  getline(&input, &bufsiz, stdin);
	if (len == -1)
	{
	if (feof(stdin))
	{
	free(input);
	exit(EXIT_SUCCESS);
	}
	{
	free(input);
	perror("reading from input failed");
	exit(EXIT_FAILURE);
	}
	}
	return (input);
}
