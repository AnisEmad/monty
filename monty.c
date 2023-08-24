#include "monty.h"
stack_t *top = NULL; 
void push(int n)
{
    stack_t *new_node;
    new_node = malloc(sizeof(stack_t));
    new_node->n = n;
    new_node->next = NULL;

    new_node->next = top;
    top = new_node;
}
void pall()
{
    stack_t *temp;
    temp = top;
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
