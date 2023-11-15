#include "shell.h"

/**
 * execute_cmd - Forks a new child process and excutes command using execve.
 * @args: args vectors made up of tokenized command strings.
 * Return: On success, execve() does not return, on error -1 is return
 */
int execute_cmd(char **args)
{
	int status;
	pid_t pid;

	pid = fork();
	if (_strcmp(args[0], "exit") == 0)
	{
	exit_shell(args[0]);
	}
	if (pid < 0)
	{
	perror("error in forking new process");
	exit(1);
	}
	/* child process because return value zero*/
	else if (pid == 0)
	{
	if (execve(args[0], args, environ) == -1)
	{
	perror("Error from child process");
	}
	exit(EXIT_FAILURE);
	}
	/*parent process because return value non-zero*/
	else
	{
	do {
	waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
