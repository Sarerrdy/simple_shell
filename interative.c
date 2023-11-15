#include "shell.h"

/**
 * interactive_mode - unix command line interpreter when run in interactive mode
 *
 * Return: void
 */

void interactive_mode()
{
        char del[] = " \t\r\n\a\":";

        char* input;
        char** input_tokens;

        char** env_var_tokens;
        char *str = "PATH";
        const char *path_delim = ":";
        char *full_path = NULL;
        char *env_var = NULL;            
        

        char *directory;

        int status = -1;

    do
    {
        env_var =  _getpath(str);

        Print_char("$: ");   
        
        input = myread_line();
        input_tokens = split_string (input, del); //tokenize command
    
        if(env_var != NULL)
        {
            
            env_var_tokens = split_string(env_var, path_delim);
        
            if(*env_var_tokens != NULL)
            {
                directory = search_directories(env_var_tokens, *input_tokens); 
                
                if(directory != NULL)
                {
                        full_path = build_path(directory, *input_tokens);
                        if (full_path == NULL)
                        {
                            free(env_var_tokens);                           
                        }

                        *input_tokens = full_path;
                        
                    status = execute_cmd(input_tokens);
                        
                    
                    free(env_var_tokens);                    
                }
                else
                {
                       status = execute_cmd(input_tokens);
                }              
            }
        }

    
        /* avoid memory leaks */
        
        free(input);
        free(input_tokens);              
    

    }while (status == -1);
    free(env_var_tokens); 
}