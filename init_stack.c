#include "push_swap.h"

void    ft_sort_init(int *num, int n)
{
    int     i;
    int     j;
    int     temp;

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

int ft_index(int *num, int data)
{
    int i;

    i = 0;
    while (num[i] != data)
        i++;
    return (i);
}

int	ft_push_init(t_stack *stack, int data)
{
	t_node  *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (1);
	new->data = data;
	new->next = stack->head;
	stack->head = new;
	stack->size++;
	return (0);
}

void    ft_init(t_stack *stack_a, t_stack *stack_b, int *num, int n)
{
    t_node  *node;
    int     i;

    stack_a->head = NULL;
    stack_a->size = 0;
    stack_b->head = NULL;
    stack_b->size = 0;
    i = n - 1;
    while (i > -1)
    {
        if (ft_push_init(stack_a, num[i]) != 0)
            ft_error2(num);
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