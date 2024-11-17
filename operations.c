/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:45:21 by arenilla          #+#    #+#             */
/*   Updated: 2024/11/17 23:45:25 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char c)
{
	t_node	*temp;

	if (stack->size < 2 || !stack->head)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	ft_printf("s%c\n", c);
}

void	ft_push(t_stack *src, t_stack *dst, char c)
{
	t_node	*temp;

	if (!src->head)
		return ;
	temp = src->head;
	src->head = temp->next;
	temp->next = dst->head;
	dst->head = temp;
	src->size--;
	dst->size++;
	ft_printf("p%c\n", c);
}

void	ft_rotate(t_stack *stack, int n, char c)
{
	t_node	*iter;
	t_node	*temp;
	int		i;

	i = 0;
	if (stack->size < 2 || !stack->head)
		return ;
	while (i < n)
	{
		iter = stack->head;
		temp = stack->head;
		stack->head = iter->next;
		while (iter->next)
			iter = iter->next;
		iter->next = temp;
		temp->next = NULL;
		i++;
		ft_printf("r%c\n", c);
	}
}

void	ft_rrotate(t_stack *stack, int n, char c)
{
	t_node	*temp;
	t_node	*last;
	int		i;

	if (stack->size < 2 || !stack->head)
		return ;
	i = 0;
	while (i < n)
	{
		temp = stack->head;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = stack->head;
		stack->head = last;
		i++;
		ft_printf("rr%c\n", c);
	}
}

void	ft_rotate_both(t_stack *s_a, t_stack *s_b, int n)
{
	t_node	*iter_a;
	t_node	*temp_a;
	t_node	*iter_b;
	t_node	*temp_b;

	if (s_a->size < 2 || !s_a->head || s_b->size < 2 || !s_b->head)
		return ;
	while (n-- > 0)
	{
		iter_a = s_a->head;
		iter_b = s_b->head;
		temp_a = s_a->head;
		temp_b = s_b->head;
		s_a->head = iter_a->next;
		s_b->head = iter_b->next;
		while (iter_a->next)
			iter_a = iter_a->next;
		while (iter_b->next)
			iter_b = iter_b->next;
		iter_a->next = temp_a;
		iter_b->next = temp_b;
		temp_a->next = NULL;
		temp_b->next = NULL;
		ft_printf("rr\n");
	}
}
