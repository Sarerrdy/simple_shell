#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char **argv, char **env_args)
{ 

    if(isatty(STDIN_FILENO) == 1)
    {       
      interactive_mode();
    }
    else
    {
        non_interactive_mode();
    } 
    
    return (0);  

}
