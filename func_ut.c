
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
	tmp = arra->len - 1;
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
	while (i < arra->len - 1)
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
	while (i < arra->len - 1)
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
	while (i > 0)
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
	while (i > 0)
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

t_stack	ft_found_lis(t_stack *arra)
{
	int i;
	int j;
	t_stack	len;

	len.len = arra->len;
	len.stack = malloc(arra->len * sizeof(int));
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
	//////////////////////////////////////////////////
	//  for (int k = 0; k < sub_sq.len; k++)
	 	// printf("sub         %d\n", sub_sq.stack[k]);
	//////////////////////////////////////////////////
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
	while (i < arra->len)
	{
		// printf("%d * %d * %d * %d\n", count, j, arra->len, i);
		if (i == sub_sq->stack[j])
		{
			lis.stack[j] = arra->stack[i];
			j++;
			if (j == count)
				break;
		}
		i++;	
	}
	//////////////////////////////////////////////////
	// for (int k = 0; k < lis.len; k++)
		// printf("------longes subsq inc -----%d\n", lis.stack[k]);
	// printf("***********\n");
	//////////////////////////////////////////////////
	return (lis);
}

void ft_push_not_lis(t_stack *lis, t_stack *arra, t_stack *arrb)
{
	int i;
	int j;

	i = 0;
	for (int k = 0; k < lis->len; k++)
		//printf("lis : %d\n", lis->stack[k]);
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
	mouves.mouves_b.len = arrb->len;
	mouves.mouves_b.stack = malloc (arrb->len * sizeof(int));

	while (j < arrb->len)
	{
		if (arrb->stack[j] < arra->stack[0] && arrb->stack[j] > arra->stack[arra->len - 1])
		{
			mouves.mouves_a.stack[j] = 0;
			//printf("j                         %d\n", j);
		}
		ft_mouves_normal(arra, arrb, &mouves, j);
		ft_mouves_mm(arra, arrb, &mouves, j);
		j++;
	}
	ft_mouves_arrb(arrb, &mouves);

	//////////////////////////////////////////////////
	// 		printf ("\n mouves arrb\n");
	// for(int i = 0; i < mouves.mouves_b.len; i++)
	// 	printf ("%d | ", mouves.mouves_b.stack[i]);
	// printf("\n");
	// printf ("----mouves arra--\n");
	// for(int i = 0; i < mouves.mouves_a.len; i++)
	// 	printf ("%d | ", mouves.mouves_a.stack[i]);
	// printf("\n");
	//////////////////////////////////////////////////
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

	//////////////////////////////////////////////////
	// printf("------staaaaaaaack A----\n");
	// for(int i = 0; i < arra->len; i++)
	// 	printf("%d * ", arra->stack[i]);
	// printf("\n------staaaaaaaaack B----\n");

	// for(int i = 0; i < arrb->len; i++)
	// 	printf("%d * ", arrb->stack[i]);
	// printf("\n----------\n");
	//////////////////////////////////////////////////

	}
	ft_sort_arra(arra);
}