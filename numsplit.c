void    ft_freen(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}


int *ft_numbers(int argc, char  **argv, int n_num)
{
    int     *stack_a;
    int     i;
    int     n;
    int     s;
    char    **nstr;

    stack_a = (int *)malloc(sizeof(int) * n_num);
    if (!stack_a)
        return (NULL);
    i = 1;
    n = 0;
    while (i < argc)
    {
        nstr = ft_split(argv[i], ' ');
        if (!nstr)
        {
            free(stack_a);
            return (NULL);
        }
        s = 0;
        while (nstr[s])
            stack_a[n++] = ft_atoi(nstr[s++]);
        ft_freen(nstr);
        i++;
    }
    return (stack_a);
}