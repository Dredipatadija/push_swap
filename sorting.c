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

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int cont)
{
	if (cont == 2)
		ft_swap(stack_a);
	else if (cont < 8)
		ft_selection_sort(stack_a, stack_b);
}