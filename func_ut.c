
#include "libft.h"
#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*k;
	size_t	i;

	k = (char *)dst;
	i = 0;
	if (!k && !src)
		return (NULL);
	while (i < n)
	{
		k[i] = *(char *)src;
		i++;
		src++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}

static	int	check(size_t sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
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
		return (check(sign));
	n = n * sign;
	return ((int)n);
}

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_sa(t_stack *arra)
{	
	ft_swap(&arra->stack[1], &arra->stack[0]);
}

void ft_sb(t_stack *arrb)
{	
	ft_swap(&arrb->stack[1], &arrb->stack[0]);
}

void ft_ss(t_stack *arrb, t_stack *arra)
{	
	ft_sa(arra);
	ft_sb(arrb);
	write(1, "ss\n", 3);
}

void ft_pa(t_stack *arra, t_stack *arrb)
{
	int i;
	int tmp;

	i = 0;
	arra->len++;
	tmp = arra->len;
	while (tmp > 0)
	{
		arra->stack[tmp] = arra->stack[tmp - 1];
		tmp--;
	}
	arra->stack[0] = arrb->stack[0];
	arrb->len--;
	write(1, "pa\n", 3);
}

void ft_pb(t_stack *arra, t_stack *arrb)
{
	int i;

	i = 0;
	arrb->stack[0] = arra->stack[0];
	while (i < arra->len)
	{
		arra->stack[i] = arra->stack[i + 1];
		i++;
	}
	arra->len--;
	arrb->len++;
	write(1, "pb\n", 3);
}

void ft_ra(t_stack *arra)
{
	ft_swap(&arra->stack[0], &arra->stack[1]);
	ft_swap(&arra->stack[1], &arra->stack[2]);
}

void ft_rb(t_stack *arrb)
{
	ft_swap(&arrb->stack[0], &arrb->stack[1]);
	ft_swap(&arrb->stack[1], &arrb->stack[2]);
}

void ft_rr(t_stack *arrb, t_stack *arra)
{
	ft_rb(arrb);
	ft_ra(arra);
	write(1, "rr\n", 3);
}

void ft_rra(t_stack *arra)
{
		ft_swap(&arra->stack[2], &arra->stack[1]);
		ft_swap(&arra->stack[1], &arra->stack[0]);
}

void ft_rrb(t_stack *arrb)
{
		ft_swap(&arrb->stack[2], &arrb->stack[1]);
		ft_swap(&arrb->stack[1], &arrb->stack[0]);
}

void ft_rrr(t_stack *arrb, t_stack *arra)
{
	ft_rrb(arrb);
	ft_rra(arra);
	write(1, "rrr\n", 4);
}

void call(char *s, void (*f)(t_stack *arr), t_stack *t)
{
	f(t);
	write(1, s, ft_strlen(s));
}
