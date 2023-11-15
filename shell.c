#include "shell.h"

/**
 * main - driver function
 * @argc: represents number of argument vectors
 * @argv: argument vactors
 * @env_args: environmental variables of the program
 *
 * Return: returns 0 on successful execution
 */

int main(int argc, char **argv, char **env_args)
{
	(void) argc;
	(void) argv;
	(void) env_args;
	if (isatty(STDIN_FILENO) == 1)
	{
	interactive_mode();
	}
	else
	{
	non_interactive_mode();
	}
	return (0);
}
