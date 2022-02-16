#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void    ft_mouves_normal(t_stack *arra, t_stack *arrb, actions *mouves, int j)
{
    int i;
    
    i = 0;
   while (i < arra->len)
		{
			if (arra->stack[i] < arrb->stack[j] && arra->stack[i + 1] > arrb->stack[j])
			{
				if ((i + 1) <= (arra->len  - 1) / 2)
					mouves->mouves_a.stack[j] = i;
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
			i = 0;
			while (i < arra->len)
			{
				if (i == max)
				{
					if (i <= (arra->len - 1) / 2)
						mouves->mouves_a.stack[j] = i;
					if (i > (arra->len - 1) / 2)
						mouves->mouves_a.stack[j] = (((arra->len - j) - 1)* (-1));
				}
				i++;
			}
		}
}

void    ft_mouves_min(t_stack *arra, t_stack *arrb, actions *mouves, int min, int j)
{
    int i;

    i = 0;
    if (arrb->stack[j] < min)
		{
			i = 0;
			while (i < arra->len)
			{
				if (i == min)
				{
					if (i <= (arra->len - 1) / 2)
						mouves->mouves_a.stack[j] = i;
					if (i > (arra->len - 1) / 2)
						mouves->mouves_a.stack[j] = (((arra->len - j) - 1)* (-1));
				}
				i++;
			}
		}
}

void    ft_mouves_top(t_stack *arra, t_stack *arrb, actions *mouves, int j)
{
    int i;

    if (j < arra->stack[0] && j > arra->stack[arra->len - 1] || j > arra->stack[0] && j < arra->stack[arra->len - 1])
    {
        i = 0;
        while (i < arra->len)
			{
				mouves->mouves_a.stack[j] = 0;
				i++;
			}

    }

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