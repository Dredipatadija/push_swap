#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_node
{
    int             data;
    int             index;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *head;
    int     size;
}   t_stack;

int         main(int argc, char **argv);
int         ft_c_parse(int argc, char **argv);
int         ft_count_n(int argc, char **argv);
int         ft_content(int argc, char **argv);
int         ft_check_dup(t_stack *stack, int cont);
int         *ft_numbers(int argc, char **argv, int n_num);
int         ft_numlen(char *str);
int         ft_intlimit(char **str, int *stack);
long long   ft_atoll_check(char *str);
void        ft_freen(char **str);
void        *ft_freeint(int *num);
void        ft_error1(void);
void        ft_error2(int *num);
void        ft_init(t_stack *stack_a, t_stack *stack_b, int *num, int n);
int         ft_push(t_stack *stack, int data, int index);

#endif