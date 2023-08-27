#include "monty.h"

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
