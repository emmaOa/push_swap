
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
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

t_stack	ft_found_lis(t_stack *arra)
{
	int i;
	int j;
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
			if (arra->stack[i] > arra->stack[j] && len.stack[i] <= len.stack[j] + 1)
				len.stack[i] = len.stack[j] + 1;
			j++;
		}
		i++;
	}
	return (len);
}

int	ft_count_lis(t_stack *len)
{
	int count;
	int i;
	
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

t_stack ft_indec(t_stack *len, t_stack *arra)
{
	int i;
	int j;
	t_stack indec;

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
			if (arra->stack[i] > arra->stack[j] && len->stack[i] <= len->stack[j] + 1)
				indec.stack[i] = j;
			j++;
		}
		i++;
	}
	return (indec);
}

t_stack ft_indec_sub_sq(t_stack *indec, t_stack *len, int count)
{
	int i;
	int j;
	int indc_count;
	t_stack sub_sq;

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
				break;	
			sub_sq.stack[j] = indec->stack[i];
			indc_count = indec->stack[i];
			j--;
		}
		i--;
	}
	return (sub_sq);
}

t_stack ft_sub_sq(t_stack *arra, t_stack *sub_sq, int count)
{
	int i;
	int j;
	t_stack lis;

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
				break;
		}
		i++;	
	}
	return (lis);
}

void ft_push_not_lis(t_stack *lis, t_stack *arra, t_stack *arrb)
{
	int i;
	int j;

	i = 0;
	for (int k = 0; k < lis->len; k++)
	while (arra->len > lis->len)
	{
		j = 0;
		while (j < lis->len)
		{
			if (arra->stack[i] == lis->stack[j])
				call("ra\n", ft_ra, arra);	
			j++;	
		}
		ft_pb(arra,arrb);
	}
	ft_sort_arra(arra);
}

actions	ft_mouves(t_stack *arra, t_stack *arrb)
{
	int j;
	actions mouves;

	j = 0;
	mouves.mouves_a.len = arrb->len;
	mouves.mouves_a.stack = malloc (arrb->len * sizeof(int));
	if (!mouves.mouves_a.stack)
		exit (0);
	mouves.mouves_b.len = arrb->len;
	mouves.mouves_b.stack = malloc (arrb->len * sizeof(int));
	if (!mouves.mouves_b.stack)
		exit (0);
	while (j < arrb->len)
	{
		if (arrb->stack[j] < arra->stack[0] && arrb->stack[j] > arra->stack[arra->len - 1])
			mouves.mouves_a.stack[j] = 0;
		ft_mouves_normal(arra, arrb, &mouves, j);
		ft_mouves_mm(arra, arrb, &mouves, j);
		j++;
	}
	ft_mouves_arrb(arrb, &mouves);
	return (mouves);
}

void	ft_push_arra(t_stack *arra, t_stack *arrb)
{
	actions	mouves;

	while (arrb->len > 0)
	{	
		mouves = ft_mouves(arra, arrb);
		ft_min_mouves_a(&mouves);
		if (mouves.mouves_b.stack[mouves.indec_nb] == 0 && mouves.mouves_a.stack[mouves.indec_nb] == 0)
			ft_pa(arra,arrb);				
		if ((mouves.mouves_b.stack[mouves.indec_nb] > 0 && mouves.mouves_a.stack[mouves.indec_nb] >= 0)
			 || (mouves.mouves_b.stack[mouves.indec_nb] >= 0 && mouves.mouves_a.stack[mouves.indec_nb] > 0))
				 ft_arra_arrb_positive(arra, arrb, &mouves);				
		if ((mouves.mouves_b.stack[mouves.indec_nb] <= 0 && mouves.mouves_a.stack[mouves.indec_nb] < 0)
			 || (mouves.mouves_b.stack[mouves.indec_nb] < 0 && mouves.mouves_a.stack[mouves.indec_nb] <= 0))
				 ft_arra_arrb_negative(arra, arrb, &mouves);					
		if ((mouves.mouves_b.stack[mouves.indec_nb] < 0 && mouves.mouves_a.stack[mouves.indec_nb] > 0)
			 || (mouves.mouves_b.stack[mouves.indec_nb] > 0 && mouves.mouves_a.stack[mouves.indec_nb] < 0))
				 ft_push_a_df(arra, arrb, &mouves);
		free(mouves.mouves_a.stack);
		free(mouves.mouves_b.stack);
	}
	ft_sort_arra(arra);

}