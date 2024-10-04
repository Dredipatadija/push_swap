void    ft_init(t_stack *stack_a, t_stack *stack_b, int *num, int n)
{
    stack_a->head = NULL;
    stack_a->size = 0;
    stack_b->head = NULL;
    stack_b->size = 0;
    n = n - 1;
    while (n > -1)
    {
        if (ft_push_(stack_a, num[n], n) != 0)
            ft_error2(num);
        n--;
    }
}