#include "libft.h"
#include "push_swap.h"
#include <stdio.h>



void    ft_arra_maximal(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int rest;
    int repet;

    rest = abs(mouves->mouves_a.stack[mouves->indec_nb]) - abs(mouves->mouves_b.stack[mouves->indec_nb]);
			repet = abs(mouves->mouves_b.stack[mouves->indec_nb]);
				while (repet > 0)
			{
				ft_rrr(arrb,arra);
				repet--;
			}
			while (rest > 0)
			{
				call("rra\n", ft_rra, arra);
				rest--;
			}
			ft_pa(arra,arrb);
}

void    ft_arrb_maximal(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int rest;
    int repet;

    rest = abs(mouves->mouves_b.stack[mouves->indec_nb]) - abs(mouves->mouves_a.stack[mouves->indec_nb]);
			repet = abs(mouves->mouves_a.stack[mouves->indec_nb]);
			while (repet > 0)
			{
				ft_rrr(arrb,arra);
				repet--;
			}
			while (rest > 0)
			{
				call("rrb\n", ft_rrb, arrb);
				rest--;
			}
			ft_pa(arra,arrb);
}

void    ft_arra_arrb_equal(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int repet;

    repet = (mouves->mouves_b.stack[mouves->indec_nb] * (-1));
			while (repet > 0)
			{
				ft_rrr(arrb,arra);
				repet--;
			}
			ft_pa(arra,arrb);
}

void    ft_arra_arrb_negative(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int rest;
    int repet;

    	if (abs(mouves->mouves_b.stack[mouves->indec_nb]) > abs(mouves->mouves_a.stack[mouves->indec_nb]))
            ft_arrb_maximal(arra, arrb, mouves);	
		if (abs(mouves->mouves_a.stack[mouves->indec_nb]) > abs(mouves->mouves_b.stack[mouves->indec_nb]))
            ft_arra_maximal(arra, arrb, mouves); 
		if (mouves->mouves_a.stack[mouves->indec_nb] == mouves->mouves_b.stack[mouves->indec_nb] && mouves->mouves_a.stack[mouves->indec_nb] != 0)
            ft_arra_arrb_equal(arra, arrb, mouves);
		ft_pa(arra,arrb);
}
