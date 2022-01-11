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

char *sort_a2(t_stack *arra, t_stack *arrb)
{
	int i;
	int len_arra;
	int len_arrb;
	t_stack arry;
	int x;

	i = 0;
	len_arra = arra->len;
	arry.len = arra->len;
	arry.stack = malloc(arra->len * sizeof(int));
	arry = ft_sort(arra);
	//printf("len ARRY1%d\n", arry.len);
	while (i < arra->len - 1)
	{
		if(arra->stack[0] < arry.stack[arry.len / 2])
		{
			ft_pb(arra,arrb);
			i++;
		}
		if (!(arra->stack[0] < arry.stack[arry.len / 2]))
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
		if (i = (arra->len / 2))
		{
			arry = ft_sort(arra);
		
		}
	}
	if (arra->stack[0] > arra->stack[1])
		call("sa\n", ft_sa, arra);

	arry.len = arrb->len;
	arry.stack = malloc(arrb->len * sizeof(int));
	arry = ft_sort(arrb);
	i = 0;
	while (i < arrb->len - 1)
	{
		if(arrb->stack[0] > arry.stack[arry.len / 2])
		{
			ft_pa(arra,arrb);
			i++;
		}
		if (!(arrb->stack[0] > arry.stack[arry.len / 2]))
		{
			call("rb\n", ft_rb, arrb);
			i++;
		}
		if (i = (arrb->len / 2))
		{
			arry = ft_sort(arrb);
		/*	printf("array--------\n");
			for(x = 0; x < arry.len; x++)
			printf("%d\n", arry.stack[x]);
			printf("array-------\n");*/
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
	t_stack	arra;
	t_stack	arrb;

	i = 0;
	arra.len = arc - 1;
	arra.stack = (int *)malloc((arc - 1) * sizeof(int));
	arrb.stack = (int *)malloc((arc - 1) * sizeof(int));

	while (i < arc - 1)
	{
		arra.stack[i] = ft_atoi (arv[i + 1]);
		printf("%d\n", arra.stack[i]);
		i++;
	}

	printf("----------\n");
	sort_a2(&arra, &arrb);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	printf("----------\n");
	for(i = 0; i < arrb.len; i++)
		printf("%d\n", arrb.stack[i]);
	/*printf("----------\n"); 
	sort_a1(&arra);
	for(i = 0; i < 3; i++)
		printf("%d\n", arra.stack[i]);
	printf("push_b\n");
	ft_pb(&arra, &arrb);
		printf(" L B %d\n", arrb.len);
		printf(" V B %d\n", arrb.stack[1]);
		printf(" L A %d\n", arra.len);
		printf(" V A %d\n", arra.stack[1]);
	/*printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	printf("push_a\n");
	ft_pa(&arra, &arrb);
		for(i = 0; i < arrb.len; i++)
			printf("%d\n", arrb.stack[i]);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);*/
/*t_stack arry;
arry.len = arra.len;
arry.stack = malloc(arra.len * sizeof(int));
arry = ft_sort(&arra);
for(i = 0; i < arry.len; i++)
	printf("%d\n", arry.stack[i]);*/
}