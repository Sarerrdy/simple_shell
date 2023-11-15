
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

char *myread_line()
{
    char* input = NULL;
    size_t len = 0;
    size_t bufsiz = 0;
    

   len =  getline(&input, &bufsiz, stdin);

   if(len == -1)
   {
        if (feof(stdin))
        {
            free(input);
            exit(EXIT_SUCCESS);
        }
        {
            free(input);
            perror("reading from input failed");
            exit(EXIT_FAILURE);
        }       
   }

   return (input);
}

