int	ft_issorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_getpos(t_stack *stack)
{
	t_node	*i;
	int		min;
	int		pos;

	i = stack->head;
	min = i->data;
	pos = 0;
	while (i)
	{
		if (i->data < min)
			min = i->data;
		i = i->next;
		pos++;
	}
	return (pos);
}