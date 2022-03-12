#ifndef CHECKER
# define CHECKER
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int *stack;
	int len;
}	t_stack;

typedef struct sign
{
	int nb;
	char *not_nb;
}	sign;

void ft_swap_ch(int *a, int *b);
void ft_sa_ch(t_stack *arra);
void ft_sb_ch(t_stack *arrb);
void ft_ss_ch(t_stack *arrb, t_stack *arra);
void ft_pa_ch(t_stack *arra, t_stack *arrb);
void ft_pb_ch(t_stack *arra, t_stack *arrb);
void ft_ra_ch(t_stack *arra);
void ft_rb_ch(t_stack *arrb);
void ft_rr_ch(t_stack *arrb, t_stack *arra);
void ft_rra_ch(t_stack *arra);
void ft_rrb_ch(t_stack *arrb);
void ft_rrr_ch(t_stack *arrb, t_stack *arra);
#endif