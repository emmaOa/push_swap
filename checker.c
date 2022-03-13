#include "get_next_line.h"
#include "push_swap.h"
#include "checker.h"

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

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int ft_double(t_stack *lin, int nb)
{
	int i;

	i = 0;
	while (i < lin->len)
	{
		if (lin->stack[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

sign ft_sign(char *str)
{
	sign ret;
	int i;
	char sign;

	i = 0;
	sign = str[i];
	ret.nb = ft_atoi(str);
	if ((ret.nb < 0 && sign != '-') || (ret.nb > 0 && sign == '-'))
		return (ret.not_nb = "error");
	return (ret.nb);
}

char *ft_checker(char *lin)
{

}

int main(int arc, char **arv)
{
	t_stack stack_a;
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	while (i < arc - 1)
	{
		nb = ft_sign(arv[i + 1])
		if (ft_double(&stack_a, nb) == 1 || )
	}
	
}