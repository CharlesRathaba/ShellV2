#include "main.h"

/**
 * main - Entry point for the shell
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Return: 0 on success
*/

int main(int argc, char *argv[])
{
    char *promt = "(MyShell)$ ";
    char *lineptr = NULL; /* to store the address of the buffer holding what was typed */
    char *lineptr_copy = NULL; /* to hold the copy of the string to be passed to strtok */
    const char *delim = " \n";
    size_t n = 0;
    ssize_t nchars_read;
    int num_tokens = 0;
    char *token = NULL;
    int i;


    /* infite loop */
    while(1) 
    {
        printf("%s", promt);
        nchars_read = getline(&lineptr, &n, stdin);
        /* check if the getline function failed or reached EOF or user use CTRL + D */ 
        if (nchars_read == -1)  
        {
            printf("Exiting shell....\n");
            break;
        }

        /* allcocate memory for a copy of the lineptr */
        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if(lineptr_copy == NULL)
        {
            perror("Memory allocation error");
            free(lineptr);
            free(lineptr_copy);
            break;
        }

        /* make a copy of lineptr */
        strcpy(lineptr_copy, lineptr);

        /* split the string into an array of words */
        token = strtok(lineptr, delim);

        /* calculate the number of tokens */
        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        /* Allocate space to hold the array of strings (tokens) */
        argv = malloc(sizeof(char *) * num_tokens);

        /**
         * Store each token in the argv array
         * First allocate enought space for each token
         * then copy token in the allocted space
        */
        token = strtok(lineptr_copy, delim);
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
            if (argv[i] == NULL)
            {
                perror("Memory allocation error");
                break;
            }
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* execute the command */
        execmd(argv);

        /* free argv after each iteration */
        for (i = 0; i < num_tokens -1; i++)
        {
            free(argv[i]);
        }
        free(argv);
        num_tokens = 0;

    }
    /* getline() dynamically allocates memory, free memory whether it succeeds or fails*/
    free(lineptr); 
    free(lineptr_copy);

    return (0);
}