#include "push_swap.h"

void	ft_selection_sort(t_stack *stack_a, t_stack *stack_b, len)
{
	t_node	*node;
	int		index;
	int		cont;

	cont = len;
	index = ft_getindex(stack_a);
	while (cont < (len - 2))
	{
		if (index <= (len / 2))
			ft_rotate(stack_a, index - 1);

	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int cont)
{
	if (cont == 2)
		ft_swap(stack_a);
	else if (cont < 8)
		ft_selection_sort(stack_a, stack_b);
}