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
	int		min;
	int		pos;
	int		min_pos;

	i = stack->head;
	min = i->data;
	pos = 0;
	min_pos = 0;
	while (i)
	{
		if (i->data < min)
		{
			min = i->data;
			min_pos = pos;
		}
		i = i->next;
		pos++;
	}
	return (min_pos);
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
