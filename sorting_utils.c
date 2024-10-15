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

int	ft_getmin(t_stack *stack)
{
	t_node	*i;
	int		min;
	i = stack->head;
	min = i->data;
}

int	ft_getpos(t_stack *stack, int min)
{
	t_node	*i;
	int		pos;

	i = stack->head;
	pos = 1;
	while (i->data != min)
	{
		i = i->next;
		pos++;
	}
	return (pos);
}

void	ft_sort3(t_stack *stack, int min, int pos)
{
	t_node	*first;
	t_node	*last;
	t_node	*mid;

	first = stack->head;
	while (last->next)
		last = last->next;
	mid = first->next;
	if (pos == 2)
	{
		if (first->data > last->data)
			ft_rotate(stack, 1);
		else if (first->data < last->data)
			ft_swap(stack);
	}
	else if (pos == 3)
	{
		if (first->data > mid->data)
		{
			ft_swap(stack);
			ft_rrotate(stack, 1);
		}
		else if (first->data < mid->data)
			ft_rotate(stack, 2);
	}
}