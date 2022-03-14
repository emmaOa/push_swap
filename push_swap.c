/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:35:23 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/14 22:37:57 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

char	*sort_a1(t_stack *arra)
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

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	ft_double(t_stack *lin, int nb, int ac)
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

t_sign	ft_sign(char *str)
{
	int		i;
	char	sign;
	t_sign	ret;

	i = 0;
	sign = str[i];
	ret.nb = ft_atoi(str);
	ret.nb2 = 0;
	if ((ret.nb < 0 && sign != '-') || (ret.nb > 0 && sign == '-'))
		ret.nb2 = 1;
	return (ret);
}

int	main(int arc, char **arv)
{
	int		i;
	int		j;
	int		count;
	t_stack	len;
	t_stack	lis;
	t_stack	sub;
	t_stack	arra;
	t_stack	arrb;
	t_stack	sub_sq;
	t_sign	sign_nb;

	i = 0;
	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.len = 0;
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));
	len.len = arra.len;
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
			if (ft_isdigit(arv[i + 1][j]) == 0 && arv[i + 1][j] != '-')
			{
				write (2, "error\n", 6);
				exit (0);
			}
			j++;
		}
		sign_nb = ft_sign(arv[i + 1]);
		if (sign_nb.nb2 == 1)
		{
			write (2, "error\n", 6);
			exit (0);
		}
		if (ft_double(&arra, sign_nb.nb, i) == 1)
		{
			write (2, "error\n", 6);
			exit (0);
		}
		arra.stack[i] = sign_nb.nb;
		i++;
	}
	if (arc == 4)
	{
		sort_a1(&arra);
		exit(0);
	}
	ft_sort_arra(&arra);
	len = ft_found_lis(&arra);
	count = ft_count_lis(&len);
	sub_sq.len = count;
	lis.len = count;
	lis = ft_indec(&len, &arra);
	sub_sq = ft_indec_sub_sq(&lis, &len, count);
	sub.len = count;
	sub = ft_sub_sq(&arra, &sub_sq, count);
	ft_push_not_lis(&sub, &arra, &arrb);
	ft_push_arra(&arra, &arrb);
}
