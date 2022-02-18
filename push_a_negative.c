#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void    ft_arra_maximal_negative(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int rest;
    int repet;

    rest = ft_abs(mouves->mouves_a.stack[mouves->indec_nb]) - ft_abs(mouves->mouves_b.stack[mouves->indec_nb]);
			repet = ft_abs(mouves->mouves_b.stack[mouves->indec_nb]);
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

void    ft_arrb_maximal_negative(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int rest;
    int repet;

    rest = ft_abs(mouves->mouves_b.stack[mouves->indec_nb]) - ft_abs(mouves->mouves_a.stack[mouves->indec_nb]);
			repet = ft_abs(mouves->mouves_a.stack[mouves->indec_nb]);
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

void    ft_arra_arrb_equal_negative(t_stack *arra, t_stack *arrb, actions *mouves)
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

    	if (ft_abs(mouves->mouves_b.stack[mouves->indec_nb]) > ft_abs(mouves->mouves_a.stack[mouves->indec_nb]))
            ft_arrb_maximal_negative(arra, arrb, mouves);	
		if (ft_abs(mouves->mouves_a.stack[mouves->indec_nb]) > ft_abs(mouves->mouves_b.stack[mouves->indec_nb]))
            ft_arra_maximal_negative(arra, arrb, mouves); 
		if (mouves->mouves_a.stack[mouves->indec_nb] == mouves->mouves_b.stack[mouves->indec_nb] && mouves->mouves_a.stack[mouves->indec_nb] != 0)
            ft_arra_arrb_equal_negative(arra, arrb, mouves);
		
}