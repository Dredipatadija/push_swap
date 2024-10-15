#include "push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int *num, int cont)
{
	int	min;
	int	pos;

	if (cont == 2)
		ft_swap(stack_a);
	min = ft_getmin(stack_a);
	pos = ft_getpos(stack_a, min);
	else if (cont == 3)
	{
		if (pos == 1)
			ft_rotate(stack_a);
		else
			ft_sort3(stack_a, pos)
	}
}