#include "monty.h"
stack_t *top = NULL; 
instruction_t instructions[] = {
    {"push", push},
    {"pall", pall}
};

void push(stack_t **stack, unsigned int line_number)
{  
    stack_t *new_node;

    (void)line_number;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = 0;
    new_node->next = NULL;

    new_node->next = *stack;
    *stack = new_node;
}
void pall(stack_t **stack, unsigned int line_number)
{
    
    stack_t *temp;

    (void)line_number;
    temp = *stack;
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

void handle_op(char *line, unsigned int line_number)
{
    char *token;
    int i;
    int n;
    int ok = 0;
    
    line[strcspn(line, "\n")] = '\0';
    token = strtok(line, " ");
    for (i = 0; i < 2; i++)
    {
        if (strcmp(token, instructions[i].opcode) == 0)
        {
            instructions[i].f(&top, line_number);
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
            exit(EXIT_FAILURE);
        }
        n = atoi(token);
        if (n == 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        top->n = n;
    }
}
