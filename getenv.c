#include "shell.h"

#include <string.h>
#include <stdio.h>


/**
 * get_path_index - Finds the index of an environmental variable.
 * @str: Environmental variable that needs to be found.
 * Return: Upon success returns the index of the environmental variable.
 * otherwise returns -1.
 */
int get_path_index(char *str)
{
	int i;
	int len;
	int j;

	len = str_len(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != str[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}



/**
 * char *_getpath(const char *pathname)
 - Finds the index of an environmental variable.
 * @pathname: Environmental variable that needs to be found.
 * Return: Upon success returns the index of the environmental variable.
 * otherwise returns -1.
 */
char *_getpath(char *pathname)
{
	int index;
	int i;
	int len;
	char *env_copy;	
	char *full_path;
	

	index = get_path_index(pathname);
	if(index != -1)
	{	
		env_copy = _strncpy(env_copy, environ[index]);
		full_path = strtok(env_copy, "=");
		full_path = strtok(NULL, "=");	
		return (full_path);
	}

}


