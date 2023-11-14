#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern char **environ;
int str_len(char *str);
char *myread_line();
char **split_string(char *usr_input, const char *delimiter);
int execute_cmd(char **args);
char *_getenv(const char *name);
char *print_env(void);
char *_strncpy(char *dest, char *src);
char *search_directories(char **path_tokens, char *command);
char *build_path(char *directory, char *command);
#endif /* SHELL_H */
