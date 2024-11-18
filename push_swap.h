/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:45:40 by arenilla          #+#    #+#             */
/*   Updated: 2024/11/17 23:45:41 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

int			main(int argc, char **argv);
int			ft_c_parse(int argc, char **argv);
int			ft_count_n(int argc, char **argv);
int			ft_content(int argc, char **argv);
int			ft_check_dup(int *num, int cont);
int			*ft_numbers(int argc, char **argv, int n_num);
int			ft_numlen(char *str);
void		ft_intlimit(char **str, int *stack);
long long	ft_atoll_check(char *str);
void		ft_freen(char **str);
void		*ft_freeint(int *num);
void		ft_freest(t_stack *stack);
void		ft_error1(void);
void		ft_error2(int *num);
void		ft_error3(t_stack *stack_a, t_stack *stack_b, int *num);
void		ft_init(t_stack *stack_a, t_stack *stack_b, int *num, int n);
void		ft_push_init(t_stack *stack, int data);
int			ft_index(int *num, int data);
void		ft_sort_init(int *num, int n);
void		ft_swap(t_stack *stack, char c);
void		ft_push(t_stack *src, t_stack *dst, char c);
void		ft_rotate(t_stack *stack, int n, char c);
void		ft_rrotate(t_stack *stack, int n, char c);
void		ft_rotate_both(t_stack *stack_a, t_stack *stack_b, int n);
void		ft_sort(t_stack *stack_a, t_stack *stack_b, int cont, int *num);
void		ft_selection_sort(t_stack *stack_a, t_stack *stack_b);
void		ft_ksort_atob(t_stack *stack_a, t_stack *stack_b);
void		ft_ksort_btoa(t_stack *stack_a, t_stack *stack_b);
int			ft_squareroot(int n);
int			ft_getpos(t_stack *stack);
int			ft_issorted(t_stack *stack);
void		ft_sort_three(t_stack *stack);
void		ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void		ft_freestack(t_stack *stack);

#endif
