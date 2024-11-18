/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:46:07 by arenilla          #+#    #+#             */
/*   Updated: 2024/11/17 23:46:09 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		index;
	int		pos;

	i = stack->head;
	index = i->index;
	pos = 0;
	while (i->next)
	{
		if (index < i->index)
			index = i->index;
		pos++;
		i = i->next;
	}
	return (pos);
}

int	ft_squareroot(int n)
{
	int	i;

	if (n < 4)
		return (1);
	i = 2;
	while (i * i < n)
		i++;
	if (i * i > n)
		if ((i * i - n) < ((i - 1) * (i - 1) + (-n)))
			return (i);
	return (i - 1);
}

void	ft_sort_three(t_stack *stack)
{
	if (ft_getpos(stack) == 0)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 1, 'a');
	}
	else if (ft_getpos(stack) == 1)
	{
		if (stack->head->data > stack->head->next->next->data)
			ft_rotate(stack, 1, 'a');
		else if (stack->head->data < stack->head->next->next->data)
			ft_swap(stack, 'a');
	}
	else if (ft_getpos(stack) == 2)
	{
		if (stack->head->data < stack->head->next->data)
			ft_rrotate(stack, 1, 'a');
		else if (stack->head->data > stack->head->next->data)
		{
			ft_swap(stack, 'a');
			ft_rrotate(stack, 1, 'a');
		}
	}
}

void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = ft_getpos(stack_a);
	if (min <= (stack_a->size / 2))
		ft_rotate(stack_a, min, 'a');
	else
		ft_rrotate(stack_a, stack_a->size - min, 'a');
	ft_push(stack_a, stack_b, 'b');
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, 'a');
}
