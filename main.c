#include "monty.h"
/*
 * main -  entry point
 * ac - argument count
 * av - argument array
 * 
 * Return: int
 */

int main(int ac, char **av)
{
    FILE *file;
    char line[256]; 
    int n_line = 1;

    if (ac != 2)
    {
        fprintf(stderr,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(av[1], "r");
    if (file == NULL) 
    {
        fprintf(stderr,"Error: Can't open file: %s\n",av[1]);
        exit(EXIT_FAILURE);
    }
    

    while (fgets(line, sizeof(line), file)) {
        
        handle_op(line, n_line);
        n_line++;        
        
    }

    fclose(file);
    return (0);
}
