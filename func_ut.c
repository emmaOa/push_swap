
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
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
	i = 0;
	while (i < arrb->len)
	{
		arrb->stack[i] = arrb->stack[i + 1];
		i++;
	}
	arrb->len--;
	write(1, "pa\n", 3);
}

void ft_pb(t_stack *arra, t_stack *arrb)
{
	int i;
	int tmp;

	i = 0;
	arrb->len++;
	tmp = arrb->len;
	while (tmp > 0)
	{
		arrb->stack[tmp] = arrb->stack[tmp - 1];
		tmp--;
	}
	arrb->stack[0] = arra->stack[0];
	i = 0;
	while (i < arra->len)
	{
		arra->stack[i] = arra->stack[i + 1];
		i++;
	}
	arra->len--;
	write(1, "pb\n", 3);
}

void ft_ra(t_stack *arra)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arra->stack[i];
	while (i < arra->len)
	{
		arra->stack[i] = arra->stack[i + 1];
		i++;
	}
	arra->stack[arra->len - 1] = tmp;
}

void ft_rb(t_stack *arrb)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arrb->stack[i];
	while (i < arrb->len)
	{
		arrb->stack[i] = arrb->stack[i + 1];
		i++;
	}
	arrb->stack[arrb->len - 1] = tmp;
}

void ft_rr(t_stack *arrb, t_stack *arra)
{
	ft_rb(arrb);
	ft_ra(arra);
	write(1, "rr\n", 3);
}

void ft_rra(t_stack *arra)
{
	int	i;
	int	tmp;

	i = arra->len - 1;
	tmp = arra->stack[i];
	while (i >= 0)
	{
		arra->stack[i] = arra->stack[i - 1];
		i--;
	}
	arra->stack[0] = tmp;
}

void ft_rrb(t_stack *arrb)
{
			int	i;
	int	tmp;

	i = arrb->len - 1;
	tmp = arrb->stack[i];
	while (i >= 0)
	{
		arrb->stack[i] = arrb->stack[i - 1];
		i--;
	}
	arrb->stack[0] = tmp;
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

t_stack	ft_sort(t_stack *arr)
{
	t_stack rtrn;
	int i;
	int j;
	int k;

	rtrn.len = arr->len;
	rtrn.stack = malloc(arr->len * sizeof(int));
	i = 0;
	k = 0;
	while (i < arr->len)
	{
		rtrn.stack[i] = arr->stack[i];
		i++;
	}
	i = 0;
	while (i < rtrn.len)
	{
		j = i + 1;
		while(j < rtrn.len)
		{
			if(rtrn.stack[i] > rtrn.stack[j])
				ft_swap(&rtrn.stack[i], &rtrn.stack[j]);
			j++;
		}
		i++;
	}
	return (rtrn);
}

t_stack ft_sortpart(t_stack *arr, t_stack *start)
{
	int i;
	int va_lenstart;
	t_stack part;

	i = 0;
	va_lenstart = start->stack[start->len];
	part.len =  va_lenstart - start->stack[start->len - 1];
	part.stack = malloc((va_lenstart - start->stack[start->len - 1]) * sizeof(int));
	while (i < va_lenstart - start->stack[start->len - 1])
	{
		part.stack[i] = arr->stack[va_lenstart];
		i++;
		va_lenstart--;
	}
	start->len--;
	return (part);
}
/*t_stack cat(t_stack *arry, int len)
{
	int i;

	i = 0;
	while (arry->stack[arry->len] != )
	{
		 code 
	}
	
}*/

t_stack	ft_empty_1(t_stack *arra, t_stack *arrb)
{
	int i;
	int x;
	int indB;
	int y;
	int l;
	int count;
	int len_arra;
	t_stack arry;
	t_stack start;
	t_stack part;


	i = 0;
	y = 0;
	
	len_arra = arra->len;
	x = 0;
/*	while (len_arra / 2 > 0)
	{
		len_arra = len_arra / 2;
		x++;
	}*/
	arry.len = arra->len;
	arry.stack = malloc(arra->len * sizeof(int));
	arry = ft_sort(arra);
	start.len = arra->len;
	printf("x %d\n", x);
	start.stack = (int *)malloc(x * sizeof(int));
	while (i < arra->len - 1)
	{
		printf("I1 %d\n", i);
		if(arra->stack[0] < arry.stack[arry.len / 2])
		{
			ft_pb(arra,arrb);
			i++;
		}

		if (arra->stack[0] == arry.stack[(arry.len / 2)])
		{
			indB = arrb->len;
			if (start.stack[y] != indB)
			{
				y++;
				start.stack[y] = indB;
			}
			/*for(l= 0; l < start.len; l++)
				printf("foix %d\n", start.stack[l]);*/

			printf(" ..%d\n", indB);
		}
		if (!(arra->stack[0] < arry.stack[arry.len / 2]))
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
		if (i = (arra->len / 2))
			arry = ft_sort(arra);
	}

	while (start.stack[start.len] != len_arra - 2)
	{
		start.len--;
	}
	start.len += 1;
	for(x= 0; x < start.len; x++)
		printf("%d\n", start.stack[x]);
/*	for(x= 0; x < start.len; x++)
		printf("%d\n", start.stack[x]);*/

	if (arra->stack[0] > arra->stack[1])
		call("sa\n", ft_sa, arra);
	return (start);
}

void	ft_empty_2(t_stack *arrb, t_stack *arra)
{
	int i;
	int x;
	t_stack arry;
	t_stack start;
	t_stack part;
	int Half;

	i = arrb->len;
	arry.len = arrb->len;
	arry.stack = malloc(arrb->len * sizeof(int));
	arry = ft_sort(arrb);
	
	start = ft_empty_1(arra, arrb);
	
	part = ft_sortpart(arrb, &start);
	Half = (start.stack[start.len] - start.stack[start.len - 1]) / 2;
	while (i < start.stack[start.len])
	{
		if (Half == 0)
		{
			if (arrb->stack[0] < arrb->stack[1])
				call("sb\n", ft_sb, arrb);
			ft_pa(arra,arrb);
			i++;
			ft_pa(arra,arrb);
			i++;	
			if (i == start.stack[start.len])
				start.len--;
		}
		if(arrb->stack[0] > arrb->stack[Half])
		{
			ft_pa(arra,arrb);
			i++;
			if (i == start.stack[start.len])
				start.len--;
		}
		if (!(arrb->stack[0] > arrb->stack[Half]))
		{
			call("rb\n", ft_rb, arrb);
			i++;
			if (i == start.stack[start.len])
				start.len--;
		}
		/*if (i = (arrb->len / 2))
			arry = ft_sort(arrb);*/
	}
	if (arrb->stack[0] < arrb->stack[1])
		call("sb\n", ft_sb, arrb);
}
