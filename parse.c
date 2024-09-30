int ft_c_parse(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
            && argv[i][j] != '+' && argv[i][j] != ' ')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}