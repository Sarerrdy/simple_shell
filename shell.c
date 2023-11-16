#include "shell.h"

/**
 * main - driver function
 * @argc: represents number of argument vectors
 * @argv: argument vactors
 * @env_args: environmental variables of the program
 *
 * Return: returns 0 on successful execution
 */

int main()
{
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
