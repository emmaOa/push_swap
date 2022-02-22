#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

char *sort_a1(t_stack *arra)
{
	if (arra->stack[0] > arra->stack[1] && arra->stack[0] < arra->stack[2])
		call("sa\n", ft_sa, arra);
	else if (arra->stack[0] > arra->stack[1] && arra->stack[0] > arra->stack[2] && arra->stack[1] > arra->stack[2])
	{
		call("sa\n", ft_sa, arra);
		call("rra\n", ft_rra, arra);
	}
	else if (arra->stack[0] > arra->stack[1] && arra->stack[0] > arra->stack[2] && arra->stack[1] < arra->stack[2])
		call("ra\n", ft_ra, arra);
	else if(arra->stack[0] < arra->stack[1] && arra->stack[0] < arra->stack[2] && arra->stack[1] > arra->stack[2])
	{
		call("sa\n", ft_sa, arra);
		call("ra\n", ft_ra, arra);
	}
	else if(arra->stack[0] < arra->stack[1] && arra->stack[0] > arra->stack[2] && arra->stack[1] > arra->stack[2])
		call("rra\n", ft_rra, arra);	
	return ("error\n");
}

void	sort_a2(t_stack *arra, t_stack *arrb)
{
	int i;

	i = 0;
	while (i < arra->len - 1)
	{
		if(arra->stack[0] < 3)
		{
			ft_pb(arra,arrb);
			i++;
		}
		else
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
	}

	i = 0;
	while (i < arra->len - 1)
	{
		if(arra->stack[0] < 4)
		{
			ft_pb(arra,arrb);
			i++;
		}
		else
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
	}
	if (arra->stack[0] > arra->stack[1])
		call("sa\n", ft_sa, arra);

	i = 0;
	while (i < arrb->len - 1)
	{
		if(arrb->stack[0] > 2)
		{
			ft_pa(arra,arrb);
			i++;
		}
		else
		{
			call("rb\n", ft_rb, arrb);
			i++;
		}
	}

	if (arrb->stack[0] < arrb->stack[1])
		call("sb\n", ft_sb, arrb);
	ft_pa(arra, arrb);
	ft_pa(arra, arrb);
}

int main(int arc, char **arv)
{
	int		i;
	int count;
	t_stack	len;
	t_stack lis;
	t_stack sub;
	t_stack	arra;
	t_stack	arrb;
	t_stack sub_sq;
	actions	mouves;
	
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

	while (i < arc - 1)
	{
		arra.stack[i] = ft_atoi (arv[i + 1]);
		i++;
	}
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
	
	mouves = ft_mouves(&arra, &arrb);
	ft_push_arra(&arra, &arrb);
	printf("------arra----\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	printf("------arrb----\n");

	for(i = 0; i < arrb.len; i++)
		printf("%d\n", arrb.stack[i]);
	printf("----------\n"); 
}