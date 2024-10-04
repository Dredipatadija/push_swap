int main(int argc, char **argv)
{
    int     *num;
    int     n_num;
    t_stack stack_a;
    t_stack stack_b;

    if (argc < 2)
        exit(1);
    if (ft_c_parse(argc, argv) != 0)
        ft_error1(void);
    if (ft_content(argc, argv) != 0)
        ft_error1(void);
    n_num = ft_count_n(argc, argv);
    if (n_num < 1)
        ft_error1(void);
    num = ft_numbers(argc, argv, n_num);
    if (!num)
        ft_error1(void);
    if (ft_check_dup(num, n_num) != 0)
        ft_error2(num);
}