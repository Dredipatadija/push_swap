/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:45:10 by arenilla          #+#    #+#             */
/*   Updated: 2024/11/17 23:45:11 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numlen(char *str)
{
	int	i;
	int	len;

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

void	ft_intlimit(char **str, int *stack)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_numlen(str[i]) > 10 || ft_atoll_check(str[i]) > 2147483647
			|| ft_atoll_check(str[i]) < -2147483648)
		{
			ft_freen(str);
			free(stack);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	*ft_numbers(int argc, char **argv, int n_num)
{
	int		*num;
	int		i;
	int		n;
	int		s;
	char	**nstr;

	num = (int *)malloc(sizeof(int) * n_num);
	if (!num)
		return (NULL);
	i = 1;
	n = 0;
	while (i < argc)
	{
		nstr = ft_split(argv[i++], ' ');
		if (!nstr)
			return (ft_freeint(num));
		ft_intlimit(nstr, num);
		s = 0;
		while (nstr[s])
			num[n++] = ft_atoi(nstr[s++]);
		ft_freen(nstr);
	}
	return (num);
}
