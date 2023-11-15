#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>

void interactive_mode();
void non_interactive_mode();
extern char **environ;

int str_len(char *str);
char *read_stream(void);
char *myread_line();
char **split_string(char *usr_input, const char *delimiter);
int execute_cmd(char **args);

int get_path_index(char *str);
char *_getpath(char *pathname);
void Print_char(char *str);
int _putchar(char c);


char *_strncpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);

void get_all_env();
void exit_shell();

char *search_directories(char **path_tokens, char *command);
char *build_path(char *directory, char *command);
#endif
