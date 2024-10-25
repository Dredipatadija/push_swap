#include "push_swap.h"

void	ft_error1(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error2(int *num)
{
	free(num);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error3(t_stack *stack_a, t_stack *stack_b, int *num)
{
	free(num);
	ft_freest(stack_a);
	ft_freest(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}