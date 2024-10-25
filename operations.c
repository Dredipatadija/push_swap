#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node  *temp;

	if (stack->size < 2 || !stack->head)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
}  

void	ft_push(t_stack *src, t_stack *dst)
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
}

void	ft_rotate(t_stack *stack, int n)
{
	t_node	*temp;
	int		i;

	i  = 0;
	if (stack->size < 2 || !stack->head)
		return ;
	while (i < n)
	{
		temp = stack->head;
		stack->head = temp->next;
		while (temp->next)
			temp = temp->next;
		temp->next = stack->head;
		stack->head = stack->head->next;
		temp->next->next = NULL;
		i++;
	}
}

void	ft_rrotate(t_stack *stack, int n)
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
	}
}

void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b, int n)
{
	ft_rotate(stack_a, n);
	ft_rotate(stack_b, n);
}