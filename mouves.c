/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:56:16 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/15 16:49:52 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_mouves_normal(t_stack *arra, t_stack *arrb, t_actions *mouves, int j)
{
	int	i;

	i = 0;
	while (i < arra->len - 1)
	{
		if (arrb->stack[j] > arra->stack[i]
			&& arrb->stack[j] < arra->stack[i + 1])
		{
			if (i + 1 <= arra->len / 2)
				mouves->mouves_a.stack[j] = i + 1;
			else
				mouves->mouves_a.stack[j] = (arra->len - (i + 1)) * (-1);
		}
		i++;
	}
}

t_ring	ft_max_min(t_stack *arra)
{
	int		i;
	t_ring	ring;

	i = 0;
	ring.max = INT32_MIN;
	ring.min = INT32_MAX;
	while (i < arra->len)
	{
		if (arra->stack[i] > ring.max)
		{
			ring.max = arra->stack[i];
			ring.indc_max = i;
		}
		if (arra->stack[i] < ring.min)
		{
			ring.min = arra->stack[i];
			ring.indc_min = i;
		}
		i++;
	}
	return (ring);
}

void	ft_mouves_mm(t_stack *arra, t_stack *arrb, t_actions *mouves, int j)
{
	t_ring	ring;

	ring = ft_max_min(arra);
	if (arrb->stack[j] > ring.max)
	{
		if (ring.indc_max <= arra->len / 2)
			mouves->mouves_a.stack[j] = ring.indc_max + 1;
		else
			mouves->mouves_a.stack[j] = (arra->len
					- (ring.indc_max + 1)) * (-1);
	}
	if (arrb->stack[j] < ring.min)
	{
		if (ring.indc_min <= arra->len / 2)
			mouves->mouves_a.stack[j] = ring.indc_min;
		else
			mouves->mouves_a.stack[j] = (arra->len - ring.indc_min) * (-1);
	}
}

int	ft_min_indec(t_stack *arra)
{
	int	i;
	int	min;
	int	indec;

	i = 0;
	min = 2147483647;
	while (i < arra->len)
	{
		if (arra->stack[i] < min)
		{
			min = arra->stack[i];
			indec = i;
		}	
		i++;
	}
	return (indec);
}

void	ft_sort_arra(t_stack *arra)
{
	int	j;
	int	indec;

	indec = ft_min_indec(arra);
	j = indec;
	if (indec <= (arra->len / 2))
	{
		while (indec > 0)
		{
			call("ra\n", ft_ra, arra);
			indec--;
		}
	}
	j = arra->len - j;
	if (indec > (arra->len / 2))
	{
		while (j > 0)
		{
			call("rra\n", ft_rra, arra);
			j--;
		}
	}
}
