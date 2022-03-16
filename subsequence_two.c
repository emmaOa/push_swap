/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:33:51 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/15 17:34:42 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_found_lis_one(t_stack *arra, t_stack *len)
{
	int	i;
	int	j;

	i = 1;
	while (i < arra->len)
	{
		j = 0;
		while (j < i)
		{
			if (arra->stack[i] > arra->stack[j]
				&& len->stack[i] <= len->stack[j] + 1)
				len->stack[i] = len->stack[j] + 1;
			j++;
		}
		i++;
	}
	return (*len);
}

t_stack	ft_found_lis(t_stack *arra)
{
	int		i;
	t_stack	len;

	len.len = arra->len;
	len.stack = malloc(arra->len * sizeof(int));
	if (!len.stack)
		exit (0);
	i = 0;
	while (i < arra->len)
	{
		len.stack[i] = 1;
		i++;
	}
	len = ft_found_lis_one(arra, &len);
	return (len);
}
