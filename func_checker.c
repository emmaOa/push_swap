/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:03:01 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/18 16:32:21 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int	check_checker(size_t sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi_checker(const char *str)
{
	size_t				i;
	size_t				k;
	int					sign;
	unsigned long long	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	k = i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		n = n * 10 + str[i++] - 48;
	k = i - k;
	if (k > 19 || n > 9223372036854775807)
		return (check_checker(sign));
	n = n * sign;
	return ((int)n);
}

int	ft_strncmp(const char *d, const char *s, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)d;
	src = (unsigned char *)s;
	if (n == 0)
		return (0);
	while ((i < n) && ((dst[i] != '\0') || (src[i] != '\0')))
	{
		if (dst[i] != src[i])
		{
			return (dst[i] - src[i]);
		}
		i++;
	}
	return (0);
}

void	ft_error_checker(void)
{
	write (2, "Error\n", 6);
	exit (0);
}

void	ft_instraction(char *out_get, t_stack_checker *arra,
	t_stack_checker *arrb)
{
	if (ft_strncmp(out_get, "sa\n", 3) == 0)
		ft_sa_ch(arra);
	else if (ft_strncmp(out_get, "sb\n", 3) == 0)
		ft_sb_ch(arrb);
	else if (ft_strncmp(out_get, "ss\n", 3) == 0)
		ft_ss_ch(arra, arrb);
	else if (ft_strncmp(out_get, "pa\n", 3) == 0)
		ft_pa_ch(arra, arrb);
	else if (ft_strncmp(out_get, "pb\n", 3) == 0)
		ft_pb_ch(arra, arrb);
	else if (ft_strncmp(out_get, "ra\n", 3) == 0)
		ft_ra_ch(arra);
	else if (ft_strncmp(out_get, "rb\n", 3) == 0)
		ft_rb_ch(arrb);
	else if (ft_strncmp(out_get, "rr\n", 3) == 0)
		ft_rr_ch(arra, arrb);
	else if (ft_strncmp(out_get, "rra\n", 4) == 0)
		ft_rra_ch(arra);
	else if (ft_strncmp(out_get, "rrb\n", 4) == 0)
		ft_rrb_ch(arrb);
	else if (ft_strncmp(out_get, "rrr\n", 4) == 0)
		ft_rrr_ch(arra, arrb);
	else
		ft_error_checker();
}
