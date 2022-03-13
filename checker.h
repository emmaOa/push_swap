#ifndef CHECKER
# define CHECKER
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack_checker
{
	int *stack;
	int len;
}	t_stack_checker;

typedef struct sign_checker
{
	int nb;
	int nb2;
}	sign_checker;

void ft_swap_ch(int *a, int *b);
void ft_sa_ch(t_stack_checker *arra);
void ft_sb_ch(t_stack_checker *arrb);
void ft_ss_ch(t_stack_checker *arrb, t_stack_checker *arra);
void ft_pa_ch(t_stack_checker *arra, t_stack_checker *arrb);
void ft_pb_ch(t_stack_checker *arra, t_stack_checker *arrb);
void ft_ra_ch(t_stack_checker *arra);
void ft_rb_ch(t_stack_checker *arrb);
void ft_rr_ch(t_stack_checker *arrb, t_stack_checker *arra);
void ft_rra_ch(t_stack_checker *arra);
void ft_rrb_ch(t_stack_checker *arrb);
void ft_rrr_ch(t_stack_checker *arrb, t_stack_checker *arra);
int	ft_atoi_checker(const char *str);
int	ft_checker(t_stack_checker *arra);
//static	int	check_checker(size_t sign);
#endif