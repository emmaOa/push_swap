/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:48:31 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 10:52:32 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct t_stack
{
	int		*stack;
	int		len;
}	t_stack;
typedef struct t_actions
{
	t_stack		mouves_a;
	t_stack		mouves_b;
	int			indec_nb;
}				t_actions;

typedef struct t_sign
{
	int		nb;
	int		nb2;
}			t_sign;

typedef struct t_ring
{
	int		max;
	int		indc_max;
	int		min;
	int		indc_min;
}			t_ring;

typedef struct t_variable
{
	t_stack		lis;
	t_stack		sub;
	t_stack		sub_sq;
}				t_variable;

int			ft_atoi(const char *str);
void		ft_sa(t_stack *arra);
void		ft_swap(int *a, int *b);
void		ft_rra(t_stack *arra);
void		ft_ra(t_stack *arra);
void		ft_pb(t_stack *arra, t_stack *arrb);
void		ft_pa(t_stack *arra, t_stack *arrb);
void		ft_sb(t_stack *arrb);
void		ft_rb(t_stack *arrb);
void		ft_rrb(t_stack *arrb);
void		ft_rrr(t_stack *arrb, t_stack *arra);
void		ft_rr(t_stack *arrb, t_stack *arra);
void		call(char *s, void (*f)(t_stack *arr), t_stack *t);
void		sort_a2(t_stack *arra, t_stack *arrb);
char		*sort_a1(t_stack *arra);
t_stack		ft_found_lis(t_stack *arra);
int			ft_count_lis(t_stack *len);
t_stack		ft_indec(t_stack *len, t_stack *arra);
t_stack		ft_indec_sub_sq(t_stack *indec, t_stack *len, int count);
t_stack		ft_sub_sq(t_stack *arra, t_stack *sub_sq, int count);
void		ft_push_not_lis(t_stack *lis, t_stack *arra, t_stack *arrb);
t_actions	ft_mouves(t_stack *arra, t_stack *arrb);
void		ft_push_arra(t_stack *arra, t_stack *arrb);
void		ft_mouves_normal(t_stack *arra, t_stack *arrb,
				t_actions *mouves, int j);
void		ft_mouves_mm(t_stack *arra, t_stack *arrb,
				t_actions *mouves, int j);
void		ft_mouves_arrb(t_stack *arrb, t_actions *mouves);
void		ft_arra_maximal_negative(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_arrb_maximal_negative(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_arra_arrb_equal_negative(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_arra_arrb_negative(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_arra_maximal_positive(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_arrb_maximal_positive(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_arra_arrb_equal_positive(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_arra_arrb_positive(t_stack *arra, t_stack *arrb,
				t_actions *mouves);
void		ft_push_a_df(t_stack *arra, t_stack *arrb, t_actions *mouves);
void		ft_min_mouves_a(t_actions *mouves);
void		ft_sort_arra(t_stack *arra);
int			ft_abs(int n);
int			ft_isdigit(int a);
int			ft_double(t_stack *lin, int nb, int ac);
t_ring		ft_max_min(t_stack *arra);
int			ft_min_indec(t_stack *arra);
void		ft_puch_arra_one(t_stack *arra, t_stack *arrb, t_actions mouves);
void		ft_push_a_df_one(t_stack *arrb, t_actions *mouves);
t_stack		ft_indec_sub_sq_one(int indc_count, t_stack *sub_sq,
				t_stack *indec, t_stack *len);
void		ft_error(void);
#endif