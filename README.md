 C - SIMPLE SHELL PROJECT

AUTHORS:

-  Michelle Yatoi <>
- Edmond Ina <sarerrdy4live@gmail.com>

DESCRIPTION 

This project is an implementation of the shell created as a Milestone Project for the C code at ALX Africa Software Engineering.
The gates of shell is a project in the first trimester, that helps student to understand the advanced concepts behind the shell program include process, system call, bit manipulation, file managment, error handling ...
Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh).
This program was written entirely in C Language.

FEATURES

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
Hndling the “end of file” condition (Ctrl+D)
Hanling the command line with arguments
Handle the PATH
Support the exit features and the exit status
Handle the Ctrl-C to not terminate the shell
Handling the command seperator
Support the file input


 BUILTINS

- exit [n] - Exit the shell, with an optional exit status, n.
- env - Print the environment.

USAGE

- First, Fork this Repository
- Then Clone
- Create an executable by running the following command:

	 gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

- From there, type in the following command and press your enter button.
	./hsh



