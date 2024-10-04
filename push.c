int    ft_push_(t_stack *stack, int data, int index)
{
    t_node  *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return (1);
    new->data = data;
    new->index = index;
    new->next = stack->head;
    stack->head = new;
    stack->size++;
    return (0);
}