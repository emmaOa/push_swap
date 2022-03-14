/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_b_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:54:08 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/14 21:59:16 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sb_ch(t_stack_checker *arrb)
{	
	ft_swap_ch(&arrb->stack[1], &arrb->stack[0]);
}

void	ft_pb_ch(t_stack_checker *arra, t_stack_checker *arrb)
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
}

void	ft_rb_ch(t_stack_checker *arrb)
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

void	ft_rrb_ch(t_stack_checker *arrb)
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
