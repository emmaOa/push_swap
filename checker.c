#include "get_next_line.h"
#include "checker.h"
#include <stdio.h>

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

int	ft_isdigit_chacker(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int ft_double_checker(t_stack_checker *lin, int nb, int ac)
{
	int i;

	i = 0;
	while (i < ac + 1)
	{
		if (lin->stack[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

sign_checker ft_sign_checker(char *str)
{
	sign_checker ret;
	int i;
	char sign;

	i = 0;
	sign = str[i];
	ret.nb = ft_atoi_checker(str);
	ret.nb2 = 0;
	if ((ret.nb < 0 && sign != '-') || (ret.nb > 0 && sign == '-'))
		ret.nb2 = 1;
	return (ret);
}

void	ft_instraction(char *out_get, t_stack_checker *arra, t_stack_checker *arrb)
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
	{
		write (2, "error1\n", 6);
		exit (0);
	}
}

int	ft_checker(t_stack_checker *arra)
{
	int i;

	i = 0;
	while (i < arra->len - 1)
	{
		if (arra->stack[i] > arra->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int main(int arc, char **arv)
{
	int		i;
	int		j;
	char	*instraction;
	t_stack_checker	arra;
	t_stack_checker	arrb;
	sign_checker sign_nb;

	i = 0;
	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.len = 0;
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));
	if (arc == 1)
	{
		write (2, "error2\n", 6);
		exit (0);		
	}
	while (i < arc - 1)
	{
		j = 0;
		while (arv[i + 1][j])
		{
			if (ft_isdigit_chacker(arv[i + 1][j]) == 0 && arv[i + 1][j] != '-')
			{
				write (2, "error3\n", 6);
				exit (0);
			}
			j++;
		}	
		sign_nb = ft_sign_checker(arv[i + 1]);
		if (sign_nb.nb2 == 1)
		{
			write (2, "error4\n", 6);
			exit (0);
		}
		if (ft_double_checker(&arra, sign_nb.nb, i) ==  1)
		{
			write (2, "error5\n", 6);
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