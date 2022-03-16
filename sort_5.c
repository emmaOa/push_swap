/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:46:27 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 20:14:54 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a2_two(t_stack *arra, t_stack *arrb)
{
	int	i;

	i = 0;
	while (i < arra->len - 1)
	{
		if (arra->stack[0] < 3)
		{
			ft_pb(arra, arrb);
			i++;
		}
		else
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
	}
}

void	ft_sort_a2_one(t_stack *arra, t_stack *arrb)
{
	int	i;

	i = 0;
	ft_sort_a2_two(arra, arrb);
	while (i < arra->len - 1)
	{
		if (arra->stack[0] < 4)
		{
			ft_pb(arra, arrb);
			i++;
		}
		else
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
	}
}

void	ft_sort_a2(t_stack *arra, t_stack *arrb)
{
	int	i;

	ft_sort_a2_one(arra, arrb);
	if (arra->stack[0] > arra->stack[1])
		call("sa\n", ft_sa, arra);
	i = 0;
	while (i < arrb->len - 1)
	{
		if (arrb->stack[0] > 2)
		{
			ft_pa(arra, arrb);
			i++;
		}
		else
		{
			call("rb\n", ft_rb, arrb);
			i++;
		}
	}
	if (arrb->stack[0] < arrb->stack[1])
		call("sb\n", ft_sb, arrb);
	ft_pa(arra, arrb);
	ft_pa(arra, arrb);
}
