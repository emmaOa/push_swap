/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_else.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:45:01 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 14:26:46 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rrr(t_stack *arrb, t_stack *arra)
{
	ft_rrb(arrb);
	ft_rra(arra);
	write(1, "rrr\n", 4);
}

void	call(char *s, void (*f)(t_stack *arr), t_stack *t)
{
	f(t);
	write(1, s, ft_strlen(s));
}

void	ft_rr(t_stack *arrb, t_stack *arra)
{
	ft_rb(arrb);
	ft_ra(arra);
	write(1, "rr\n", 3);
}

void	ft_ss(t_stack *arrb, t_stack *arra)
{	
	ft_sa(arra);
	ft_sb(arrb);
	write(1, "ss\n", 3);
}
