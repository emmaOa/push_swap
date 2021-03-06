/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:42:38 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/18 18:16:36 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_ft_check_error_one_checker(int arc, char **arv,
		t_stack_checker *arra)
{
	int				i;
	int				j;
	t_sign_checker	sign_nb;

	i = 0;
	while (i < arc - 1)
	{
		j = 0;
		if (ft_isdigit_chacker(arv[i + 1][j]) == 0
			&& arv[i + 1][j] != '-' && arv[i + 1][j] != '+')
			ft_error_checker();
		while (arv[i + 1][j])
		{
			if (ft_isdigit_chacker(arv[i + 1][j]) == 0 && j != 0)
				ft_error_checker();
			j++;
		}
		sign_nb = ft_sign_checker(arv[i + 1]);
		if (sign_nb.nb2 == 1 || ft_double_checker(arra, sign_nb.nb, i) == 1)
		{
			ft_error_checker();
		}
		arra->stack[i] = sign_nb.nb;
		i++;
	}
}

int	main(int arc, char **arv)
{
	char			*instraction;
	t_stack_checker	arra;
	t_stack_checker	arrb;

	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.len = 0;
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));
	if (arc == 1)
		exit(0);
	ft_ft_check_error_one_checker(arc, arv, &arra);
	instraction = get_next_line(0);
	while (instraction != '\0')
	{
		ft_instraction(instraction, &arra, &arrb);
		free(instraction);
		instraction = get_next_line(0);
	}
	if (ft_checker(&arra) == 0 && arrb.len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
