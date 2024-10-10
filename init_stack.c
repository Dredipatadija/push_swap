#include "push_swap.h"

void    ft_sort(int *num, int n)
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

void    ft_init(t_stack *stack_a, t_stack *stack_b, int *num, int n)
{
    t_node  *node;

    stack_a->head = NULL;
    stack_a->size = 0;
    stack_b->head = NULL;
    stack_b->size = 0;
    n = n - 1;
    while (n > -1)
    {
        if (ft_push(stack_a, num[n]) != 0)
            ft_error2(num);
        n--;
    }
    ft_sort(num, n);
    node = stack_a->head;
    while (node)
    {
        node->index = ft_index(num, node->data);
        node = node->next;
    }
}