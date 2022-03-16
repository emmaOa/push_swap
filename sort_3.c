/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:50:04 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 19:54:05 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

char	*ft_sort_a1(t_stack *arra)
{
	if (arra->stack[0] > arra->stack[1]
		&& arra->stack[0] < arra->stack[2])
		call("sa\n", ft_sa, arra);
	else if (arra->stack[0] > arra->stack[1]
		&& arra->stack[0] > arra->stack[2] && arra->stack[1] > arra->stack[2])
	{
		call("sa\n", ft_sa, arra);
		call("rra\n", ft_rra, arra);
	}
	else if (arra->stack[0] > arra->stack[1]
		&& arra->stack[0] > arra->stack[2] && arra->stack[1] < arra->stack[2])
		call("ra\n", ft_ra, arra);
	else if (arra->stack[0] < arra->stack[1]
		&& arra->stack[0] < arra->stack[2] && arra->stack[1] > arra->stack[2])
	{
		call("sa\n", ft_sa, arra);
		call("ra\n", ft_ra, arra);
	}
	else if (arra->stack[0] < arra->stack[1]
		&& arra->stack[0] > arra->stack[2] && arra->stack[1] > arra->stack[2])
		call("rra\n", ft_rra, arra);
	return ("error\n");
}
