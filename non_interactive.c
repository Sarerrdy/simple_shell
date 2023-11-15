#include "shell.h"

/**
 * non_interactive_mode - unix command line interpreter
 *
 * Return: void
 */

void non_interactive_mode(void)
{
	char del[] = " \t\r\n\a\":";
	char *input = NULL;
	char **input_tokens = NULL;
	char **env_var_tokens = NULL;
	char *str = "PATH";
	const char *path_delim = ":";
	char *full_path = NULL;
	char *env_var = NULL;
	char *directory = NULL;
	int status = -1;

	do {
	env_var =  _getpath(str);
	input = read_stream();
	input_tokens = split_string(input, del);
	if (env_var != NULL)
	{
	env_var_tokens = split_string(env_var, path_delim);
	if (*env_var_tokens != NULL)
	{
	directory = search_directories(env_var_tokens, *input_tokens);
	if (directory != NULL)
	{
	full_path = build_path(directory, *input_tokens);
	if (full_path == NULL)
	{
	free(env_var_tokens);
	}
	*input_tokens = full_path;
	status = execute_cmd(input_tokens);
	free(env_var_tokens);
	}
	else
	{
	status = execute_cmd(input_tokens);
	}
	}
	}
	free(input);
	free(input_tokens);
	if (status >= 0)
	{
	exit(status);
	}
	} while (status == -1);
}
