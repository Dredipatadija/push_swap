/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:46:01 by arenilla          #+#    #+#             */
/*   Updated: 2024/11/17 23:46:02 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	range;

	i = 0;
	range = ft_squareroot(stack_a->size) * 7 / 5;
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

int	ft_count_r(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	ft_ksort_btoa(t_stack *stack_b, t_stack *stack_a)
{
	int	rb_count;
	int	rrb_count;
	int	size;

	size = stack_b->size;
	while (size - 1 >= 0)
	{
		rb_count = ft_count_r(stack_b->head, size - 1);
		rrb_count = (size + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->index != size - 1)
				ft_rotate(stack_b, 1, 'b');
			ft_push(stack_b, stack_a, 'a');
			size--;
		}
		else
		{
			while (stack_b->head->index != size - 1)
				ft_rrotate(stack_b, 1, 'b');
			ft_push(stack_b, stack_a, 'a');
			size--;
		}
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int cont, int *num)
{
	if (cont == 2)
		ft_swap(stack_a, 'a');
	else if (cont == 3)
		ft_sort_three(stack_a);
	else if (cont < 11)
		ft_selection_sort(stack_a, stack_b);
	else if (cont > 10)
	{
		ft_ksort_atob(stack_a, stack_b);
		ft_ksort_btoa(stack_b, stack_a);
	}
	else
		ft_error3(stack_a, stack_b, num);
}
