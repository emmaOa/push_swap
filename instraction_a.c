/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:45:19 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 14:27:08 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *arra)
{	
	ft_swap(&arra->stack[1], &arra->stack[0]);
}

void	ft_pa(t_stack *arra, t_stack *arrb)
{
	int	i;
	int	tmp;

	i = 0;
	arra->len++;
	tmp = arra->len - 1;
	while (tmp > 0)
	{
		arra->stack[tmp] = arra->stack[tmp - 1];
		tmp--;
	}
	arra->stack[0] = arrb->stack[0];
	i = 0;
	while (i < arrb->len)
	{
		arrb->stack[i] = arrb->stack[i + 1];
		i++;
	}
	arrb->len--;
	write(1, "pa\n", 3);
}

void	ft_ra(t_stack *arra)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arra->stack[i];
	while (i < arra->len - 1)
	{
		arra->stack[i] = arra->stack[i + 1];
		i++;
	}
	arra->stack[arra->len - 1] = tmp;
}

void	ft_rra(t_stack *arra)
{
	int	i;
	int	tmp;

	i = arra->len - 1;
	tmp = arra->stack[i];
	while (i > 0)
	{
		arra->stack[i] = arra->stack[i - 1];
		i--;
	}
	arra->stack[0] = tmp;
}
