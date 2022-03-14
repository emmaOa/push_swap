/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:56:30 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/14 22:39:29 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_found_lis(t_stack *arra)
{
	int		i;
	int		j;
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
	i = 1;
	while (i < arra->len)
	{
		j = 0;
		while (j < i)
		{
			if (arra->stack[i] > arra->stack[j]
				&& len.stack[i] <= len.stack[j] + 1)
				len.stack[i] = len.stack[j] + 1;
			j++;
		}
		i++;
	}
	return (len);
}

int	ft_count_lis(t_stack *len)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < len->len)
	{
		if (count < len->stack[i])
			count = len->stack[i];
		i++;
	}
	return (count);
}

t_stack	ft_indec(t_stack *len, t_stack *arra)
{
	int		i;
	int		j;
	t_stack	indec;

	i = 1;
	indec.len = arra->len;
	indec.stack = malloc(arra->len * sizeof(int));
	if (!indec.stack)
		exit (0);
	while (i < arra->len)
	{
		j = 0;
		while (j < i)
		{
			if (arra->stack[i] > arra->stack[j]
				&& len->stack[i] <= len->stack[j] + 1)
				indec.stack[i] = j;
			j++;
		}
		i++;
	}
	return (indec);
}

t_stack	ft_indec_sub_sq(t_stack *indec, t_stack *len, int count)
{
	int		i;
	int		j;
	int		indc_count;
	t_stack	sub_sq;

	i = 0;
	sub_sq.len = count;
	sub_sq.stack = malloc(count * sizeof(int));
	if (!sub_sq.stack)
		exit (0);
	while (i < len->len)
	{
		if (len->stack[i] == count)
			indc_count = i;
		i++;
	}
	sub_sq.stack[count - 1] = indc_count;
	j = count - 2;
	i = len->len;
	while (i > 0)
	{
		if (i == indc_count)
		{
			if (j == (-1))
				break ;
			sub_sq.stack[j] = indec->stack[i];
			indc_count = indec->stack[i];
			j--;
		}
		i--;
	}
	return (sub_sq);
}

t_stack	ft_sub_sq(t_stack *arra, t_stack *sub_sq, int count)
{
	int		i;
	int		j;
	t_stack	lis;

	i = 0;
	j = 0;
	lis.len = count;
	lis.stack = malloc (count * sizeof(int));
	if (!lis.stack)
		exit (0);
	while (i < arra->len)
	{
		if (i == sub_sq->stack[j])
		{
			lis.stack[j] = arra->stack[i];
			j++;
			if (j == count)
				break ;
		}
		i++;
	}
	return (lis);
}
