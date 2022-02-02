
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

t_stack	ft_sort(t_stack *arr, int len)
{
	t_stack rtrn;
	int i;
	int j;
	int k;

	rtrn.len = len;
	rtrn.stack = malloc(len * sizeof(int));
	i = 0;
	k = 0;
	while (i < len)
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
	int x;

	i = 0;
	va_lenstart = start->stack[start->len];
	printf("len start %d\n", start->stack[start->len]);
	part.len =  va_lenstart - start->stack[start->len - 1];
	printf(" len part avant %d\n", part.len);
	part.stack = malloc((va_lenstart - start->stack[start->len - 1]) * sizeof(int));
	while (i < va_lenstart - start->stack[start->len - 1])
	{
		part.stack[i] = arr->stack[i];
		i++;
	}
	part = ft_sort(&part, part.len);
	start->len--;
	for(x = 0; x < part.len; x++)
		printf("V %d\n", part.stack[x]);
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

/*t_stack	ft_empty_1(t_stack *arra, t_stack *arrb)
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
	t_stack v_part;
	t_stack arra_sorti;


	i = 0;
	y = 0;
	
	len_arra = arra->len;
	x = 0;
	indB = 0;
	while (len_arra / 2 > 0)
	{
		len_arra = len_arra / 2;
		x++;
	}*/
	/*arra_sorti.len = arra->len;
	arra_sorti.stack = malloc(arra->len * sizeof(int));
	arra_sorti = ft_sort(arra);*/
/*	arry.len = arra->len;
	arry.stack = malloc(arra->len * sizeof(int));
	arry = ft_sort(arra, arra->len);
	start.len = arra->len - 2;
	v_part.len = arra->len - 2;
	start.stack = (int *)malloc(x * sizeof(int));
	v_part.stack = (int *)malloc(x * sizeof(int));
	while (i < arra->len - 1)
	{
		
		if(arra->stack[0] < arry.stack[arry.len / 2])
		{
			ft_pb(arra,arrb);
			i++;
			indB++;
		}
		printf(" valeur indb %d\n", indB);
		v_part.stack[x] = (indB - v_part.stack[x - 1]);
		x++;
		printf(" valeur x %d\n", x);
		if (arra->stack[0] == arry.stack[arry.len / 2])
		{
			printf("valeur arry %d\n", arry.stack[arry.len / 2]);
			indB = arrb->len;
			if (start.stack[y] != indB)
			{
				y++;
				start.stack[y] = indB;
			}
			printf("indb %d\n", indB);
		}
		if (!(arra->stack[0] < arry.stack[arry.len / 2]))
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
		if (i = (arra->len / 2))
			arry = ft_sort(arra, arra->len);
		
	}
	//printf("len start avant %d\n", start.len);
	while (start.stack[start.len] != len_arra - 2)
	{
		start.len--;
	}
	for(x= 0; x < start.len; x++)
		printf("%d\n", start.stack[x]);*/
/*	for(x= 0; x < start.len; x++)
		printf("%d\n", start.stack[x]);*/

	//if (arra->stack[0] > arra->stack[1])
	//	call("sa\n", ft_sa, arra);
/*	for(y= 0; y < start.len; y++)
		printf("v_ part %d\n", start.stack[y]);*/
	//return (start);
//}*/

void	ft_empty_1(t_stack *arra, t_stack *arrb)
{
	//int i;
	int j;
	//int len;
	t_stack arry;
	//t_stack start;

	/*i = 0;
	len = arra->len;
	while (len / 2 > 0)
	{
		len = len / 2;
		i++;
		if (len == 1)
			i++;
	}
	len = 0;
	printf("i %d\n" ,i);
	start.len = i;
	start.stack = malloc(i * sizeof(int));*/
	arry.len = arra->len;
	arry.stack = malloc(arra->len * sizeof(int));
	arry = ft_sort(arra, arra->len);

	while (arra->len > 2)
	{
		j = 0;
		
		while (j <= arry.len / 2)
		{
			if(arra->stack[0] < arry.stack[arry.len / 2])
			{
				ft_pb(arra,arrb);
				j++;
			}
			if (!(arra->stack[0] < arry.stack[arry.len / 2]))
			{
				call("ra\n", ft_ra, arra);
				j++;
			}
				
		}
		/*start.stack[len] = arrb->len;
		len++;*/	
		arry = ft_sort(arra, arra->len);
		//printf("len arrb %d\n", arrb->len);
	}
/*	for(int x = 0; x < start.len; x++)
			printf(" lll%d\n", start.stack[x]);*/
	if (arra->stack[0] > arra->stack[1])
		call("sa\n", ft_sa, arra);
}

int ft_comparison(t_stack *arry, int nb)
{
	int i;

	i = 0;
	while (i < arry->len)
	{
		if (nb < arry->stack[i])
			return 1;
		i++;	
	}
	return 0;
}

void	ft_empty_2(t_stack *arrb, t_stack *arra)
{

	/*t_stack arry;

	arry.len = arrb->len;
	arry.stack = malloc(arrb->len * sizeof(int));
	arry = ft_sort(arrb, arrb->len);
	ft_empty_1(arra, arrb);
	while (arrb->len > 2)
	{
		if (ft_comparison(arrb) == 1)
			call("rb\n", ft_rb, arrb);
		else if (ft_comparison(arrb) == 0)
			ft_pa(arra,arrb);
	}
	if (arrb->stack[0] < arrb->stack[1])
		call("sb\n", ft_sb, arrb);*/

	
	int j;
	t_stack arry;

	ft_empty_1(arra, arrb);
	arry.len = arrb->len;
	arry.stack = malloc(arrb->len * sizeof(int));
	arry = ft_sort(arrb, arrb->len);
	while (arrb->len > 2)
	{
		j = 0;
		while (j < arry.len / 2)
		{
			if(arrb->stack[0] > arry.stack[arry.len / 2] && ft_comparison(arrb, arrb->stack[0]) == 0)
				ft_pa(arra,arrb);	
			else
				call("rb\n", ft_rb, arrb);
			j++;
		}
		arry = ft_sort(arrb, arrb->len);
		
	}
	/*printf("----------\n");
	for(i = 0; i < arry.len; i++)
		printf("%d\n", arry.stack[i]);*/
	if (arrb->stack[0] < arrb->stack[1])
		call("sb\n", ft_sb, arrb);
}

/*void	ft_empty_2(t_stack *arrb, t_stack *arra)
{
	int len;
	int i;
	int j;
	t_stack start;
	t_stack arry;

	len = arrb->len;
	i = 0;
	while (len / 2 > 0)
	{
		len = len / 2;
		i++;
		if (len == 1)
			i++;
	}
	len = 0;
	start.len = i;
	start.stack = malloc(start.len * sizeof(int));
	start = ft_empty_1(arra, arrb);
	i = 0;


	while (arrb->len > 0)
	{
		j = 0;
		while (j <= arry.len / 2)
		{
			if(arrb->stack[0] < arry.stack[arry.len / 2])
			{
				ft_pa(arra,arrb);
				j++;
			}
			if (!(arrb->stack[0] < arry.stack[arry.len / 2]))
			{
				call("rb\n", ft_rb, arrb);
				j++;
			}
				
		}
		start.stack[len] = arrb->len;
		len++;
		
		arry = ft_sort(arrb, arra->len);
		printf("len arrb %d\n", arrb->len);
	}

	

}*/
