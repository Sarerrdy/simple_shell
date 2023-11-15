#include "shell.h"

/**
 * split_string - parses through string and splits it according to delimeter
 * @usr_input: command input by user
 * @delimiter: character indicating position where the string
 * will be split
 *
 * Return: an array containing the split commands
 */

char **split_string(char *usr_input, const char *delimiter)
{
	int buf = 1024;
	int i = 0;
	char *single_token;
	char **token_arr = malloc(buf * sizeof(char *));

	single_token = strtok(usr_input, delimiter);

	while (single_token != NULL)
	{
	if (single_token[0] == '#')
	{
	break;
	}
	token_arr[i] = single_token;
	i++;
	if (buf <= i)
	{
	buf += buf;
	token_arr = realloc(token_arr, buf * sizeof(char *));
	if (!token_arr)
	{
	printf("realocating memory failed");
	free(token_arr);
	EXIT_FAILURE;
	}
	}
	single_token = strtok(NULL, delimiter);
	}
	token_arr[i] = NULL;
	return (token_arr);
}
