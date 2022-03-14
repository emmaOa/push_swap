/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:06:40 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/14 22:39:08 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_not_lis(t_stack *lis, t_stack *arra, t_stack *arrb)
{
	int	i;
	int	j;

	i = 0;
	while (arra->len > lis->len)
	{
		j = 0;
		while (j < lis->len)
		{
			if (arra->stack[i] == lis->stack[j])
				call("ra\n", ft_ra, arra);
			j++;
		}
		ft_pb(arra, arrb);
	}
	ft_sort_arra(arra);
}

t_actions	ft_mouves(t_stack *arra, t_stack *arrb)
{
	int			j;
	t_actions	mouves;

	j = 0;
	mouves.mouves_a.len = arrb->len;
	mouves.mouves_a.stack = malloc (arrb->len * sizeof(int));
	if (!mouves.mouves_a.stack)
		exit (0);
	mouves.mouves_b.len = arrb->len;
	mouves.mouves_b.stack = malloc (arrb->len * sizeof(int));
	if (!mouves.mouves_b.stack)
		exit (0);
	while (j < arrb->len)
	{
		if (arrb->stack[j] < arra->stack[0]
			&& arrb->stack[j] > arra->stack[arra->len - 1])
			mouves.mouves_a.stack[j] = 0;
		ft_mouves_normal(arra, arrb, &mouves, j);
		ft_mouves_mm(arra, arrb, &mouves, j);
		j++;
	}
	ft_mouves_arrb(arrb, &mouves);
	return (mouves);
}

void	ft_push_arra(t_stack *arra, t_stack *arrb)
{
	t_actions	mouves;

	while (arrb->len > 0)
	{	
		mouves = ft_mouves(arra, arrb);
		ft_min_mouves_a(&mouves);
		if (mouves.mouves_b.stack[mouves.indec_nb] == 0
			&& mouves.mouves_a.stack[mouves.indec_nb] == 0)
			ft_pa(arra, arrb);
		if ((mouves.mouves_b.stack[mouves.indec_nb] > 0
				&& mouves.mouves_a.stack[mouves.indec_nb] >= 0)
			|| (mouves.mouves_b.stack[mouves.indec_nb] >= 0
				&& mouves.mouves_a.stack[mouves.indec_nb] > 0))
			ft_arra_arrb_positive(arra, arrb, &mouves);
		if ((mouves.mouves_b.stack[mouves.indec_nb] <= 0
				&& mouves.mouves_a.stack[mouves.indec_nb] < 0)
			|| (mouves.mouves_b.stack[mouves.indec_nb] < 0
				&& mouves.mouves_a.stack[mouves.indec_nb] <= 0))
			ft_arra_arrb_negative(arra, arrb, &mouves);
		if ((mouves.mouves_b.stack[mouves.indec_nb] < 0
				&& mouves.mouves_a.stack[mouves.indec_nb] > 0)
			|| (mouves.mouves_b.stack[mouves.indec_nb] > 0
				&& mouves.mouves_a.stack[mouves.indec_nb] < 0))
			ft_push_a_df(arra, arrb, &mouves);
		free(mouves.mouves_a.stack);
		free(mouves.mouves_b.stack);
	}
	ft_sort_arra(arra);
}
