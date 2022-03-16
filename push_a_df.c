/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_df.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:46:22 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/15 17:21:13 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_mouves_a(t_actions *mouves)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (i < mouves->mouves_a.len)
	{
		if (ft_abs(mouves->mouves_a.stack[i])
			+ ft_abs(mouves->mouves_b.stack[i]) < min)
		{	
			min = ft_abs(mouves->mouves_a.stack[i])
				+ ft_abs(mouves->mouves_b.stack[i]);
			mouves->indec_nb = i;
		}
		i++;
	}
}

void	ft_push_a_df_one(t_stack *arrb, t_actions *mouves)
{
	int	repet;

	if (mouves->mouves_b.stack[mouves->indec_nb] > 0)
	{
		repet = mouves->mouves_b.stack[mouves->indec_nb];
		while (repet > 0)
		{
			call("rb\n", ft_rb, arrb);
			repet--;
		}
	}
	if (mouves->mouves_b.stack[mouves->indec_nb] < 0)
	{
		repet = ft_abs(mouves->mouves_b.stack[mouves->indec_nb]);
		while (repet > 0)
		{
			call("rrb\n", ft_rrb, arrb);
			repet--;
		}
	}
}

void	ft_push_a_df(t_stack *arra, t_stack *arrb, t_actions *mouves)
{
	int	repet;

	ft_push_a_df_one(arrb, mouves);
	if (mouves->mouves_a.stack[mouves->indec_nb] > 0)
	{
		repet = mouves->mouves_a.stack[mouves->indec_nb];
		while (repet > 0)
		{
			call("ra\n", ft_ra, arra);
			repet--;
		}
	}
	if (mouves->mouves_a.stack[mouves->indec_nb] < 0)
	{
		repet = ft_abs(mouves->mouves_a.stack[mouves->indec_nb]);
		while (repet > 0)
		{
			call("rra\n", ft_rra, arra);
			repet--;
		}
	}
	ft_pa(arra, arrb);
}
