#include "monty.h"
info my_info = {
        NULL,
        {
            {"push", push},
            {"pall", pall}
        }
    };

void handle_op(char *line, unsigned int line_number)
{
    stack_t *temp;
    char *token;
    int i;
    int n;
    int ok = 0;
    
    line[strcspn(line, "\n")] = '\0';
    token = strtok(line, " ");
    for (i = 0; i < 2; i++)
    {
        if (strcmp(token, my_info.instructions[i].opcode) == 0)
        {
            my_info.instructions[i].f(&my_info.top, line_number);
            ok = 1;
            break;
        }   
    }
    if (!ok)
    {
        fprintf(stderr,"L%d: unknown instruction %s\n", line_number, token);
        exit(EXIT_FAILURE);
    }
    if (strcmp(token, "push") == 0)
    {
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            temp = my_info.top;
            my_info.top = my_info.top->next;
            free(temp);
            exit(EXIT_FAILURE);
        }
        n = atoi(token);
        if (n == 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            temp = my_info.top;
            my_info.top = my_info.top->next;
            free(temp);
            exit(EXIT_FAILURE);
        }
        my_info.top->n = n;
    }
}
