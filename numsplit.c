ft_numlen(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i] == '+' || str[i] == '-' || str[i] == '0')
        i++;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    return (len);
}

ft_intlimit(char **str, int *stack)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_numlen(str[i]) > 10 || ft_atoll_chek(str[i]) > 2147483647
            || ft_atoll_check(str[i]) < -2147483648)
        {
            ft_freen(str);
            free(stack);
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
    return (0);
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
        nstr = ft_split(argv[i++], ' ');
        if (!nstr)
            return (ft_freestack(stack_a));
        ft_intlimit(nstr, stack_a);
        s = 0;
        while (nstr[s])
            stack_a[n++] = ft_atoi(nstr[s++]);
        ft_freen(nstr);
    }
    return (stack_a);
}