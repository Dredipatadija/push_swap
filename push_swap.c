int main(int argc, char **argv)
{
    int *stack_a;

    if (argc < 2)
        ERROR;
    if (ft_c_parse(argc, argv) != 0)
        ERROR;
    if (ft_content != 0)
        ERROR;
    if (ft_count_n != 0)
        ERROR;
    stack_a = ft_numbers;
    if (!stack_a)
        ERROR;
    if (ft_check_dup(stack_a) != 0)
        ERROR;
}