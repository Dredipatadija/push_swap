#include "push_swap.h"

int	ft_c_parse(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
			&& argv[i][j] != '+' && argv[i][j] != ' ')
				return (-1);
			if ((argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]) == 0) ||
				(argv[i][j] == '+' && ft_isdigit(argv[i][j + 1]) == 0))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_count_n(int argc, char **argv)
{
	int	j;
	int	cont;

	cont = 0;
	while (argc > 1)
	{
		j = 0;
		argc--;
		while (argv[argc][j])
		{
			if (ft_isdigit(argv[argc][j]) == 1 && (argv[argc][j + 1] == ' '
				|| argv[argc][j + 1] == '\0'))
				cont++;
			j++;
		}
	}
	return (cont);
}

int	ft_content(int argc, char **argv)
{
	int	j;
	int	digit;

	while (argc > 1)
	{
		j = 0;
		digit = 0;
		argc--;
		while (argv[argc][j] != '\0')
		{
			if (ft_isdigit(argv[argc][j]) == 1)
			{
				digit = 1;
				argc--;
				break ;
			}
			j++;
		}
		if (digit == 0)
			return (-1);
	}
	return (0);
}

int	ft_check_dup(int *num, int cont)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cont)
	{
		j = i + 1;
		while (j < cont)
		{
			if (num[i] == num[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
