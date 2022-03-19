/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:35:23 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/18 18:16:46 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_double(t_stack *lin, int nb, int ac)
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

t_sign	ft_sign(char *str)
{
	int		i;
	char	sign;
	t_sign	ret;

	i = 0;
	sign = str[i];
	if (str[0] == '\0')
		ft_error();
	ret.nb = ft_atoi(str);
	ret.nb2 = 0;
	if ((ret.nb < 0 && sign != '-') || (ret.nb > 0 && sign == '-'))
		ret.nb2 = 1;
	return (ret);
}

void	ft_check_error_one(int arc, char **arv, t_stack *arra)
{
	int		i;
	int		j;
	t_sign	sign_nb;

	i = 0;
	while (i < arc - 1)
	{
		j = 0;
		if (ft_isdigit(arv[i + 1][j]) == 0
			&& arv[i + 1][j] != '-' && arv[i + 1][j] != '+')
			ft_error();
		while (arv[i + 1][j])
		{
			if (ft_isdigit(arv[i + 1][j]) == 0 && j != 0)
				ft_error();
			j++;
		}
		sign_nb = ft_sign(arv[i + 1]);
		if (sign_nb.nb2 == 1 || ft_double(arra, sign_nb.nb, i) == 1)
		{
			ft_error();
		}
		arra->stack[i] = sign_nb.nb;
		i++;
	}
}

t_stack	ft_check_error(int arc, char **arv, t_stack *arra, t_stack *arrb)
{
	if (arc == 1)
		exit(0);
	ft_check_error_one(arc, arv, arra);
	if (arc == 4)
	{
		ft_sort_a1(arra);
		exit(0);
	}
	if (arc == 6)
	{
		ft_sort_a2(arra, arrb);
		exit(0);
	}
	return (*arra);
}

int	main(int arc, char **arv)
{
	int			count;
	t_stack		len;
	t_variable	variable;
	t_stack		arra;
	t_stack		arrb;

	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.len = 0;
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));
	len.len = arra.len;
	arra = ft_check_error(arc, arv, &arra, &arrb);
	ft_sort_arra(&arra);
	len = ft_found_lis(&arra);
	count = ft_count_lis(&len);
	variable.sub_sq.len = count;
	variable.lis.len = count;
	variable.lis = ft_indec(&len, &arra);
	variable.sub_sq = ft_indec_sub_sq(&variable.lis, &len, count);
	variable.sub.len = count;
	variable.sub = ft_sub_sq(&arra, &variable.sub_sq, count);
	ft_push_not_lis(&variable.sub, &arra, &arrb);
	ft_push_arra(&arra, &arrb);
}
