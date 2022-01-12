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
	int x;

	i = 0;
	while (i < arra->len - 1)
	{
		if(arra->stack[0] < 3)
		{
			ft_pb(arra,arrb);
			i++;
		}
		if (!(arra->stack[0] < 3))
		{
			call("ra\n", ft_ra, arra);
			i++;
		}
	}

	while (i < arra->len - 1)
	{
		if(arra->stack[0] < 4)
		{
			ft_pb(arra,arrb);
			i++;
		}
		if (!(arra->stack[0] < 4))
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
		if (!(arrb->stack[0] > 2))
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

char *sort_a3(t_stack *arra, t_stack *arrb)
{
	int i;
	t_stack s_start;
	t_stack s_end;
	int len_arrb;
	t_stack arry;
	int x;

	i = 0;
	
	arry.len = arra->len;
	arry.stack = malloc(arra->len * sizeof(int));
	arry = ft_sort(arra);
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
			arry = ft_sort(arra);
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
			arry = ft_sort(arrb);
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
	t_stack start;
	t_stack part;
	t_stack end;

	start.len = 3;
	start.stack = malloc(3 * sizeof(int));
	start.stack[0] = 0;
	start.stack[1] = 3;
	start.stack[2] = 6;

	end.len = 3;
	end.stack = malloc(3 * sizeof(int));
	end.stack[0] = 2;
	end.stack[1] = 5;
	end.stack[2] = 8;

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

	for(int x; x= 0; x++)
		printf("%d" , start.stack[x]);

/*	while (start.len != 0)
	{
		part = ft_sortpart(&arra, &start, &end);
		for(int x; x = 0; x++)
		{
			printf("----------");
			printf("%d", part.stack[x]);
			printf("----------");
		}
			
	}*/
	
	
	//printf("----------\n");
/*	sort_a3(&arra, &arrb);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	printf("----------\n");
	for(i = 0; i < arrb.len; i++)
		printf("%d\n", arrb.stack[i]);*/
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
	*/
	/*ft_pb(&arra, &arrb);
		for(i = 0; i < arrb.len; i++)
			printf("%d\n", arrb.stack[i]);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	ft_pb(&arra, &arrb);
		for(i = 0; i < arrb.len; i++)
			printf("%d\n", arrb.stack[i]);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	ft_pa(&arra, &arrb);
		for(i = 0; i < arrb.len; i++)
			printf("%d\n", arrb.stack[i]);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
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