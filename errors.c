void    ft_error1(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void    ft_error2(int *stack)
{
    free(stack);
    write(2, "Error\n", 6);
    exit(1);
}