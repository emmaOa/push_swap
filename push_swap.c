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
	t_stack	arra;
	t_stack	arrb;
	int max;
	i = 0;
	len.len = arra.len;
	len.stack = malloc(arra.len * sizeof(int));
	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));

	while (i < arc - 1)
	{
		arra.stack[i] = ft_atoi (arv[i + 1]);
		i++;
	}
	len = ft_found_lis(&arra);
	for(i = 0; i < arra.len; i++)
		printf("len %d\n", len.stack[i]);
	count = ft_count_lis(&len);
	printf("count %d\n", count);
	lis.len = count;
	lis.stack = malloc(count * sizeof(int));
	lis = ft_lis(&len, &arra);
	for (i = 0; i < lis .len; i++)
		printf("valeur-- %d\n", lis.stack[i]);
	
	/*printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	printf("----------\n");
	for(i = 0; i < arrb.len; i++)
		printf("%d\n", arrb.stack[i]);
	printf("----------\n"); */
}