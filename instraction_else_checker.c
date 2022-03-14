/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_else_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:02:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/14 22:02:35 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_ch(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_ss_ch(t_stack_checker *arrb, t_stack_checker *arra)
{	
	ft_sa_ch(arra);
	ft_sb_ch(arrb);
}

void	ft_rr_ch(t_stack_checker *arrb, t_stack_checker *arra)
{
	ft_rb_ch(arrb);
	ft_ra_ch(arra);
}

void	ft_rrr_ch(t_stack_checker *arrb, t_stack_checker *arra)
{
	ft_rrb_ch(arrb);
	ft_rra_ch(arra);
}
