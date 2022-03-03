#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void    ft_arra_maximal_positive(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int rest;
    int repet;

    rest = mouves->mouves_a.stack[mouves->indec_nb] - mouves->mouves_b.stack[mouves->indec_nb];
			repet = mouves->mouves_b.stack[mouves->indec_nb];
				while (repet > 0)
			{
				ft_rr(arrb,arra);
				repet--;
			}
			while (rest > 0)
			{
				call("ra\n", ft_ra, arra);
				rest--;
			}
			ft_pa(arra,arrb);
}

void    ft_arrb_maximal_positive(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int rest;
    int repet;

    rest = mouves->mouves_b.stack[mouves->indec_nb] - mouves->mouves_a.stack[mouves->indec_nb];
			repet = mouves->mouves_a.stack[mouves->indec_nb];
			while (repet > 0)
			{
				ft_rr(arrb,arra);
				repet--;
			}
			while (rest > 0)
			{
				call("rb\n", ft_rb, arrb);
				rest--;
			}
			ft_pa(arra,arrb);
}

void    ft_arra_arrb_equal_positive(t_stack *arra, t_stack *arrb, actions *mouves)
{
    int repet;

    repet = (mouves->mouves_b.stack[mouves->indec_nb] * (-1));
			while (repet > 0)
			{
				ft_rr(arrb, arra);
				repet--;
			}
			ft_pa(arra,arrb);
}

void    ft_arra_arrb_positive(t_stack *arra, t_stack *arrb, actions *mouves)
{
    	if (mouves->mouves_b.stack[mouves->indec_nb] > mouves->mouves_a.stack[mouves->indec_nb])
            ft_arrb_maximal_positive(arra, arrb, mouves);	
		if (ft_abs(mouves->mouves_a.stack[mouves->indec_nb]) > ft_abs(mouves->mouves_b.stack[mouves->indec_nb]))
            ft_arra_maximal_positive(arra, arrb, mouves); 
		if ((mouves->mouves_a.stack[mouves->indec_nb] == mouves->mouves_b.stack[mouves->indec_nb]) && (mouves->mouves_a.stack[mouves->indec_nb] != 0))
            ft_arra_arrb_equal_positive(arra, arrb, mouves);
}