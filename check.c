/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:33:40 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 10:35:59 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit_chacker(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	ft_double_checker(t_stack_checker *lin, int nb, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (lin->stack[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

t_sign_checker	ft_sign_checker(char *str)
{
	int				i;
	char			sign;
	t_sign_checker	ret;

	i = 0;
	sign = str[i];
	ret.nb = ft_atoi_checker(str);
	ret.nb2 = 0;
	if ((ret.nb < 0 && sign != '-') || (ret.nb > 0 && sign == '-'))
		ret.nb2 = 1;
	return (ret);
}
