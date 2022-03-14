/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_a_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:47:04 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/14 21:52:19 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa_ch(t_stack_checker *arra)
{
	ft_swap_ch(&arra->stack[1], &arra->stack[0]);
}

void	ft_pa_ch(t_stack_checker *arra, t_stack_checker *arrb)
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
}

void	ft_ra_ch(t_stack_checker *arra)
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

void	ft_rra_ch(t_stack_checker *arra)
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
