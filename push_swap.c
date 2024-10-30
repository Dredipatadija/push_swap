#include "push_swap.h"

int main(int argc, char **argv)
{
	int	 *num;
	int	 n_num;
	t_stack stack_a;
	t_stack stack_b;

	if (argc < 2)
		ft_error1();
	if (ft_c_parse(argc, argv) != 0)
		ft_error1();
	if (ft_content(argc, argv) != 0)
		ft_error1();
	n_num = ft_count_n(argc, argv);
	if (n_num < 1)
		ft_error1();
	num = ft_numbers(argc, argv, n_num);
	if (!num)
		ft_error1();
	if (ft_check_dup(num, n_num) != 0)
		ft_error2(num);
	ft_init(&stack_a, &stack_b, num, n_num);
	if (!ft_issorted(&stack_a))
		ft_sort(&stack_a, &stack_b, n_num, num);
}