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