#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	ft_mouves_normal(t_stack *arra, t_stack *arrb, actions *mouves, int j)
{
	int i;

	i = 0;
	while (i < arra->len - 1)
	{

		if ((arrb->stack[j] < arra->stack[i] && arrb->stack[j] > arra->stack[i + 1]) 
		|| (arrb->stack[j] > arra->stack[i] && arrb->stack[j] < arra->stack[i + 1]))
		{
			if (i + 1 <= (arra->len / 2))
			{
				mouves->mouves_a.stack[j] = i + 1;
			}
			else
			{
				mouves->mouves_a.stack[j] = (arra->len - (i + 1)) * (-1);
				printf("\n j=%d mouves negative %d, i = %d, i + 1 = %d, len a = %d, len b = %d \n", j, mouves->mouves_a.stack[j], i, i + 1, arra->len, arrb->len);
			}
		}
		i++;
	}
}

void	ft_mouves_mm(t_stack *arra, t_stack *arrb, actions *mouves, int j)
{
	int i;
	int max;
	int indc_max;
	int min;
	int indc_min;	

	i = 0;
	max = INT32_MIN;
	min = INT32_MAX;

	while (i < arra->len)
	{
		if (arra->stack[i] > max)
		{
			max = arra->stack[i];
			indc_max = i;
		}			
		if (arra->stack[i] < min)
		{
			min = arra->stack[i];
			indc_min = i;
		}
		i++;
	}
	if (arrb->stack[j] > max)
	{
		if (indc_max <= arra->len / 2)
			mouves->mouves_a.stack[j] = indc_max + 1;
		else
			mouves->mouves_a.stack[j] = (arra->len - (indc_max + 1)) * (-1);	
		printf("j=%d", j);
	}
	if (arrb->stack[j] < min)
	{
		if (indc_min <= arra->len / 2)
			mouves->mouves_a.stack[j] = indc_min;
		else
			mouves->mouves_a.stack[j] = (arra->len - indc_min) * (-1);	
		printf("j=%d", j);
	}
}

void    ft_mouves_arrb(t_stack *arrb, actions *mouves)
{
    int i;
    int j;

    i = 0;
    j = 0;
     while (j < (arrb->len / 2) + 1)
    {
        mouves->mouves_b.stack[j] = i;
        j++;
        i++;
    }
	j = mouves->mouves_b.len - 1;
    i = -1;
    while (j > arrb->len / 2)
    {
        mouves->mouves_b.stack[j] = i;
        j--;
        i--;
	}
}

void	ft_sort_arra(t_stack *arra)
{
	int i;
	int j;
	int min;
	int indec;

	i = 0;
	min = 2147483647;
	while (i < arra->len)
	{
		if (arra->stack[i] < min)
		{
			min = arra->stack[i];
			indec = i;
		}	
		i++;	
	}
	j = indec;
	if (indec <= (arra->len / 2))
	{
		while (indec > 0)
		{
			call("ra\n", ft_ra, arra);
			indec--;
		}
	}
	j = arra->len - j;
	if (indec > (arra->len / 2))
	{
		while (j > 0)
		{
			call("rra\n", ft_rra, arra);
			j--;
		}
	}
}
