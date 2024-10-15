#include "push_swap.h"

void	ft_freen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	*ft_freeint(int *num)
{
	free(num);
	return (NULL);
}
