int main(int argc, char **argv)
{
    int *stack_a;
    int n_num;

    if (argc < 2)
        ERROR;
    if (ft_c_parse(argc, argv) != 0)
        ERROR;
    if (ft_content(argc, argv) != 0)
        ERROR;
    n_num = ft_count_n(argc, argv);
    if (n_num < 1)
        ERROR;
    stack_a = ft_numbers(argc, argv, n_num);
    if (!stack_a)
        ERROR;
    if (ft_check_dup(stack_a, n_num) != 0)
        ERROR;
}