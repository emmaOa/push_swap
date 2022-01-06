
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

void ft_sa(int *arra)
{	
	ft_swap(&arra[1], &arra[0]);
	write(1, "sa\n", 3);
}

void ft_rra(int *arra)
{
		ft_swap(&arra[2], &arra[1]);
		ft_swap(&arra[1], &arra[0]);
		write(1, "rra\n", 4);
}

void ft_ra(int *arra)
{
		ft_swap(&arra[0], &arra[1]);
		ft_swap(&arra[1], &arra[2]);
		write(1, "ra\n", 3);
}

void ft_pb(int *arra, int *arrb)
{
	int *tmp

	tmp = malloc((ft_strlen(arra) - 1) * sizeof(int));
	arrb[0] = arra[0];
	ft_memmove(tmp, arra, )
}