/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:46:29 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 14:27:00 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack *arrb)
{	
	ft_swap(&arrb->stack[1], &arrb->stack[0]);
}

void	ft_rb(t_stack *arrb)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arrb->stack[i];
	while (i < arrb->len)
	{
		arrb->stack[i] = arrb->stack[i + 1];
		i++;
	}
	arrb->stack[arrb->len - 1] = tmp;
}

void	ft_pb(t_stack *arra, t_stack *arrb)
{
	int	i;
	int	tmp;

	i = 0;
	arrb->len++;
	tmp = arrb->len;
	while (tmp > 0)
	{
		arrb->stack[tmp] = arrb->stack[tmp - 1];
		tmp--;
	}
	arrb->stack[0] = arra->stack[0];
	i = 0;
	while (i < arra->len - 1)
	{
		arra->stack[i] = arra->stack[i + 1];
		i++;
	}
	arra->len--;
	write(1, "pb\n", 3);
}

void	ft_rrb(t_stack *arrb)
{
	int	i;
	int	tmp;

	i = arrb->len - 1;
	tmp = arrb->stack[i];
	while (i > 0)
	{
		arrb->stack[i] = arrb->stack[i - 1];
		i--;
	}
	arrb->stack[0] = tmp;
}
