#include "push_swap.h"

void	ft_selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	int		cont;

	cont = stack_a->size;
	while (cont > 2)
	{
		index = ft_getpos(stack_a);
		if (index <= (stack_a->size / 2))
			ft_rotate(stack_a, index, 'a');
		else
			ft_rrotate(stack_a, cont - index, 'a');
		ft_push(stack_a, stack_b, 'b');
		cont--;
	}
	if (stack_a->head->data > stack_a->head->next->data)
		ft_swap(stack_a, 'a');
	while (stack_b->size > 0)
		ft_push(stack_b, stack_a, 'a');
}

void	ft_ksort_atob(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int range;

	i = 0;
	range = ft_squareroot(stack_a->size);
	while (stack_a->head)
	{
		if (stack_a->head->index <= i)
		{
			ft_push(stack_a, stack_b, 'b');
			i++;
		}
		else if (stack_a->head->index <= i + range)
		{
			ft_push(stack_a, stack_b, 'b');
			i++;
			if (stack_a->head->index > i + range)
				ft_rotate_both(stack_a, stack_b, 1);
			else
				ft_rotate(stack_b, 1, 'b');
		}
		else
			ft_rotate(stack_a, 1, 'a');
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int cont, int *num)
{
	if (cont == 2)
		ft_swap(stack_a, 'a');
	else if (cont < 11)
		ft_selection_sort(stack_a, stack_b);
	else if (cont > 10)
	{
		ft_ksort_atob(stack_a, stack_b);
		ft_selection_sort(stack_b, stack_a);
	}
	else
		ft_error3(stack_a, stack_b, num);
}