#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

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
		ret.not_nb = "error\n";
	return (ret);
}

int main(int arc, char **arv)
{
	int		i;
	int		j;
	int count;
	t_stack	len;
	t_stack lis;
	t_stack sub;
	t_stack	arra;
	t_stack	arrb;
	t_stack sub_sq;
	actions	mouves;
	sign sign_nb;
	
	i = 0;
	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.len = 0;
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));
	len.len = arra.len;
	len.stack = malloc(arra.len * sizeof(int));
	mouves.mouves_a.len = arrb.len;
	mouves.mouves_a.stack = malloc (arrb.len * sizeof(int));
	mouves.mouves_b.len = arrb.len;
	mouves.mouves_b.stack = malloc (arrb.len * sizeof(int));

	if (arc == 1)
	{
		write (2, "error\n", 6);
		exit (0);		
	}
	while (i < arc - 1)
	{
		j = 0;
		while (arv[i + 1][j])
		{
			if (ft_isdigit(arv[i + 1][j]) == 0)
			{
				write (2, "error\n", 6);
				exit (0);
			}
			j++;
		}
		
		sign_nb = ft_sign(arv[i + 1]);
		if (sign_nb.not_nb != '\0')
		{
			write (2, "error\n", 6);
			exit (0);
		}
		if (ft_double(&arra, sign_nb.nb) ==  1)
		{
			write (2, "error\n", 6);
			exit (0);	
		}
		arra.stack[i] = sign_nb.nb;
		i++;
	}
	ft_sort_arra(&arra);
	len = ft_found_lis(&arra);
	count = ft_count_lis(&len);
	sub_sq.len = count;
	sub_sq.stack = malloc (count * sizeof(int));
	lis.len = count;
	lis.stack = malloc(count * sizeof(int));
	lis = ft_indec(&len, &arra);
	sub_sq = ft_indec_sub_sq(&lis, &len, count);
	sub.len = count;
	sub.stack = malloc(count * sizeof(int));
	sub = ft_sub_sq(&arra, &sub_sq, count);
	ft_push_not_lis(&sub, &arra, &arrb);
	ft_push_arra(&arra, &arrb);
	// printf("\n------arra----\n");
	// for(i = 0; i < arra.len; i++)
	// 	printf("%d \n", arra.stack[i]);
	// printf("\n------arrb----\n");

	// for(i = 0; i < arrb.len; i++)
	// 	printf("%d *", arrb.stack[i]);
	// printf("\n----------\n"); 
}