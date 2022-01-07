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
		call("ra\n", ft_sa, arra);
	}
	else if(arra->stack[0] < arra->stack[1] && arra->stack[0] > arra->stack[2] && arra->stack[1] > arra->stack[2])
		call("rra\n", ft_rra, arra);	
	return ("error\n");
}

// char *sort_a2(t_stack *arra, t_stack *arrb)
// {

// }

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
	sort_a1(&arra);
	for(i = 0; i < 3; i++)
		printf("%d\n", arra.stack[i]);
	printf("push_b\n");
	ft_pb(&arra, &arrb);
		printf("%d\n", arrb.stack[0]);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
	printf("push_a\n");
	ft_pa(&arra, &arrb);
		for(i = 0; i < arrb.len; i++)
			printf("%d\n", arrb.stack[i]);
	printf("----------\n");
	for(i = 0; i < arra.len; i++)
		printf("%d\n", arra.stack[i]);
}