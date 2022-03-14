/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:42:38 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/14 23:25:04 by iouazzan         ###   ########.fr       */
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
	while (i < ac + 1)
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

int	ft_checker(t_stack_checker *arra)
{
	int	i;

	i = 0;
	while (i < arra->len - 1)
	{
		if (arra->stack[i] > arra->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	main(int arc, char **arv)
{
	int				i;
	int				j;
	char			*instraction;
	t_stack_checker	arra;
	t_stack_checker	arrb;
	t_sign_checker	sign_nb;

	i = 0;
	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.len = 0;
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));
	if (arc == 1)
	{
		write (2, "error\n", 6);
		exit (0);
	}
	while (i < arc - 1)
	{
		j = 0;
		while (arv[i + 1][j])
		{
			if (ft_isdigit_chacker(arv[i + 1][j]) == 0 && arv[i + 1][j] != '-')
			{
				write (2, "error\n", 6);
				exit (0);
			}
			j++;
		}
		sign_nb = ft_sign_checker(arv[i + 1]);
		if (sign_nb.nb2 == 1)
		{
			write (2, "error\n", 6);
			exit (0);
		}
		if (ft_double_checker(&arra, sign_nb.nb, i) == 1)
		{
			write (2, "error\n", 6);
			exit (0);
		}
		arra.stack[i] = sign_nb.nb;
		i++;
	}
	instraction = get_next_line(0);
	while (instraction != '\0')
	{
		ft_instraction(instraction, &arra, &arrb);
		free(instraction);
		instraction = get_next_line(0);
	}
	if (ft_checker(&arra) == 0 && arrb.len == 0)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}
