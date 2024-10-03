void    ft_freen(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}

void    *ft_freestack(int *stack)
{
    free(stack);
    return (NULL);
}
