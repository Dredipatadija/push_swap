/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:44:39 by arenilla          #+#    #+#             */
/*   Updated: 2024/11/17 23:44:41 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_init(int *num, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_index(int *num, int data)
{
	int	i;

	i = 0;
	while (num[i] != data)
		i++;
	return (i);
}

void	ft_push_init(t_stack *stack, int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = data;
	new->next = stack->head;
	stack->head = new;
	stack->size++;
}

void	ft_init(t_stack *stack_a, t_stack *stack_b, int *num, int n)
{
	t_node	*node;
	int		i;

	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
	i = n - 1;
	while (i > -1)
	{
		ft_push_init(stack_a, num[i]);
		i--;
	}
	ft_sort_init(num, n);
	node = stack_a->head;
	while (node)
	{
		node->index = ft_index(num, node->data);
		node = node->next;
	}
}
