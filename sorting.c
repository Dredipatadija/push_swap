#include "push_swap.h"

void	ft_selection_sort(t_stack *stack_a, t_stack *stack_b, len)
{
	int		index;
	int		cont;

	cont = len;
	while (cont > 2)
	{
		index = ft_getpos(stack_a);
		if (index <= (len / 2))
			ft_rotate(stack_a, index);
		else
			ft_rrotate(stack_a, cont - index);
		ft_push(stack_a, stack_b);
		cont--;
	}
	if (stack_a->head->data > stack_a->head->next->data)
		ft_swap(stack_a);
	while (stack_b->size > 0)
		ft_push(stack_b, stack_a);
}

ft_quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int range;

	i = 0;
	range = ft_squareroot(stack_a->size);
	while (stack_a->head)
	{
		if (stack_a->head->index <= i)
		{
			ft_push(stack_a, stack_b);
			i++;
		}
		else if (stack_a->head->index <= i + range)
		{
			push(stack_a, stack_b);
			i++;
			if (stack_a->head->index > i + range)
			{
				ft_rotate(stack_a, 1);
				ft_rotate(stack_b, 1);
			}
			else
				ft_rotate(stack_b, 1);
		}
		else
			ft_rotate(stack_a, 1);
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int cont)
{
	if (cont == 2)
		ft_swap(stack_a);
	else if (cont < 11)
		ft_selection_sort(stack_a, stack_b);
	else if (cont > 10)
		ft_quick_sort(stack_a, stack_b);
	else
		ERROR;
}