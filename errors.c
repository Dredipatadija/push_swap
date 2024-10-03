void    ft_error1(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void    ft_error2(int *num)
{
    free(num);
    write(2, "Error\n", 6);
    exit(1);
}