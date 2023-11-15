#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * get_all_env - Prints all the environmental variables in the current shell.
 */
void get_all_env()
{
    int i;
    int j;

    for (i = 0; environ[i] != NULL; i++)
    {
        for (j = 0; environ[i][j] != '\0'; j++)
            write(STDOUT_FILENO, &environ[i][j], 1);
        write(STDOUT_FILENO, "\n", 1);
    }
	
}


/**
 * exit_shell - Exits the shell. After freeing allocated resources.
 * @input: A string representing the input from the user.
 */
void exit_shell(char *input)
{
    free(input);	
	exit(1);
}
