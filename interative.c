#include "shell.h"
/**
 * interactive_mode - unix command line interpreter when run in interactive
 * mode
 *
 */
void interactive_mode(void)
{
	char del[] = " \t\r\n\a\":";
	char *input = NULL;
	char **input_tokens = NULL;
	char **env_var_tokens = NULL;
	char *full_path = NULL;
	char *env_var = NULL;
	char *directory = NULL;
	int status = -1;

	do {
	env_var =  _getpath("PATH");
	Print_char("$: ");
	input = myread_line();
	input_tokens = split_string(input, del);
	if (env_var != NULL)
	{
		env_var_tokens = split_string(env_var, ":");
		if (*env_var_tokens != NULL)
		{
			directory = search_directories(env_var_tokens, *input_tokens);
			if (directory != NULL)
			{
				full_path = build_path(directory, *input_tokens);
				if (full_path == NULL)
					free(env_var_tokens);
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
	} while (status == -1);
	free(env_var_tokens);
}
