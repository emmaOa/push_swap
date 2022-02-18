#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void    ft_mouves_normal(t_stack *arra, t_stack *arrb, actions *mouves, int j)
{
    int i;
    
    i = 0;
	printf("mouve normal\n");
   while (i < arra->len)
		{
			if ((arra->stack[i] < arrb->stack[j] && arra->stack[i + 1] > arrb->stack[j])  || (arra->stack[i] > arrb->stack[j] && arra->stack[i + 1] < arrb->stack[j]))
			{
				if ((i + 1) <= (arra->len  - 1) / 2)
					mouves->mouves_a.stack[j] = i + 1;
				if ((i + 1) > (arra->len - 1) / 2)
					mouves->mouves_a.stack[j] = (((arra->len - i) - 1) * (-1));
			}
			i++;
		}
    
}

void    ft_mouves_max(t_stack *arra, t_stack *arrb, actions *mouves, int max, int j)
{
    int i;

    i = 0;
    if (arrb->stack[j] > max)
		{
			while (i < arra->len)
			{
				if (arra->stack[i] == max)
				{
					if (i <= (arra->len - 1) / 2)
						mouves->mouves_a.stack[j] = i;
					if (i > (arra->len - 1) / 2)
						mouves->mouves_a.stack[j] = (((arra->len - j) - 1) * (-1));
				}
				i++;
			}
		}
}

void    ft_mouves_top(t_stack *arra, t_stack *arrb, actions *mouves, int j)
{
    if ((j < arra->stack[0] && j > arra->stack[arra->len - 1]) || (j > arra->stack[0] && j < arra->stack[arra->len - 1]))
		mouves->mouves_a.stack[j] = 0;
}

void    ft_mouves_arrb(t_stack *arrb, actions *mouves)
{
    int i;
    int j;

	j = mouves->mouves_b.len - 1;
    i = -1;
    while (j >= arrb->len / 2)
    {
        mouves->mouves_b.stack[j] = i;
        j--;
        i--;
    }
    i = 0;
    j = 0;
     while (j < arrb->len / 2)
    {
        mouves->mouves_b.stack[j] = i;
        j++;
        i++;
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
			printf("cas 1\n");
			call("ra\n", ft_ra, arra);
			indec--;
		}
	}
	j = arra->len - j;
	if (indec > (arra->len / 2))
	{
		while (j > 0)
		{
			printf("cas 2\n");
			call("rra\n", ft_rra, arra);
			j--;
		}
	}
}
