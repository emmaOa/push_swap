#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

char *sort_a1(int *arra)
{
	if (arra[0] > arra[1] && arra[0] < arra[2])
		ft_sa(arra);
	else if (arra[0] > arra[1] && arra[0] > arra[2] && arra[1] > arra[2])
	{
		ft_sa(arra);
		ft_rra(arra);
	}
	else if (arra[0] > arra[1] && arra[0] > arra[2] && arra[1] < arra[2])
	{
		ft_ra(arra);
	}
	else if(arra[0] < arra[1] && arra[0] < arra[2] && arra[1] > arra[2])
	{
		ft_sa(arra);
		ft_ra(arra);
	}
	else if(arra[0] < arra[1] && arra[0] > arra[2] && arra[1] > arra[2])
		ft_rra(arra);
	return ("error");
}

// char *sort_a2(int *arra, int *arrb)
// {

// }

int main(int arc, char **arv)
{
	int i;
	int *arra;
	int *arrb;

	i = 0;
	arra = (int *)malloc((arc - 1) * sizeof(int));
	arrb = (int *)malloc((arc - 1) * sizeof(int));

	while (i < arc - 1)
	{
		arra[i] = ft_atoi(arv[i+1]);
		printf("%d\n", arra[i]);
		i++;
	}
	printf("----------\n");
	sort_a1(arra);
	for(i = 0; i < 3; i++)
		printf("%d\n", arra[i]);
	printf("----------\n");
	ft_pb(arra, arrb);
	for(i = 0; i < 3; i++)
		printf("%d\n", arra[i]);
	printf("----------\n");
	printf("%d\n", arrb[0]);
}