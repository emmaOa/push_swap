#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int *stack;
	int len;
}	t_stack;
typedef struct actions
{
	t_stack	mouves_a;
	t_stack	mouves_b;
	int	indec_nb;
}	actions;
int		ft_atoi(const char *str);
void	ft_sa(t_stack *arra);
void	ft_swap(int *a, int *b);
void	ft_rra(t_stack *arra);
void	ft_ra(t_stack *arra);
void	ft_pb(t_stack *arra, t_stack *arrb);
void	ft_pa(t_stack *arra, t_stack *arrb);
void	ft_sb(t_stack *arrb);
void	ft_rb(t_stack *arrb);
void	ft_rrb(t_stack *arrb);
void	call(char *s, void (*f)(t_stack *arr), t_stack *t);
void	sort_a2(t_stack *arra, t_stack *arrb);
char	*sort_a1(t_stack *arra);
t_stack	ft_found_lis(t_stack *arra);
int		ft_count_lis(t_stack *len);
t_stack	ft_indec(t_stack *len, t_stack *arra);
t_stack	ft_indec_sub_sq(t_stack *indec, t_stack *len, int count);
t_stack	ft_sub_sq(t_stack *arra, t_stack *sub_sq, int count);
void	ft_push_not_lis(t_stack *lis, t_stack *arra, t_stack *arrb);
actions	ft_mouves(t_stack *arra, t_stack *arrb);
void	ft_push_arra(t_stack *arra, t_stack *arrb);
void    ft_mouves_normal(t_stack *arra, t_stack *arrb, actions *mouves, int j);
void    ft_mouves_max(t_stack *arra, t_stack *arrb, actions *mouves, int max, int j);
void    ft_mouves_min(t_stack *arra, t_stack *arrb, actions *mouves, int max, int j);
void    ft_mouves_top(t_stack *arra, t_stack *arrb, actions *mouves, int j);
void    ft_mouves_arrb(t_stack *arrb, actions *mouves);
void    ft_arra_arrb_negative(t_stack *arra, t_stack *arrb, actions *mouves);
void    ft_arra_maximal(t_stack *arra, t_stack *arrb, actions *mouves);
void    ft_arrb_maximal(t_stack *arra, t_stack *arrb, actions *mouves);
void    ft_arra_arrb_equal(t_stack *arra, t_stack *arrb, actions *mouves);

#endif