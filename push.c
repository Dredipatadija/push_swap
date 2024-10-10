#include "push_swap.h"

int    ft_push(t_stack *stack, int data)
{
    t_node  *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return (1);
    new->data = data;
    new->next = stack->head;
    stack->head = new;
    stack->size++;
    return (0);
}