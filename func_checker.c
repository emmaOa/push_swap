#include "get_next_line.h"
#include "checker.h"
#include <stdio.h>

void ft_swap_ch(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_sa_ch(t_stack_checker *arra)
{
	ft_swap_ch(&arra->stack[1], &arra->stack[0]);
}

void ft_sb_ch(t_stack_checker *arrb)
{	
	ft_swap_ch(&arrb->stack[1], &arrb->stack[0]);
}

void ft_ss_ch(t_stack_checker *arrb, t_stack_checker *arra)
{	
	ft_sa_ch(arra);
	ft_sb_ch(arrb);
}

void ft_pa_ch(t_stack_checker *arra, t_stack_checker *arrb)
{
	int i;
	int tmp;

	i = 0;
	arra->len++;
	tmp = arra->len - 1;
	while (tmp > 0)
	{
		arra->stack[tmp] = arra->stack[tmp - 1];
		tmp--;
	}
	arra->stack[0] = arrb->stack[0];
	i = 0;
	while (i < arrb->len)
	{
		arrb->stack[i] = arrb->stack[i + 1];
		i++;
	}
	arrb->len--;
}

void ft_pb_ch(t_stack_checker *arra, t_stack_checker *arrb)
{
	int i;
	int tmp;

	i = 0;
	arrb->len++;
	tmp = arrb->len;
	while (tmp > 0)
	{
		arrb->stack[tmp] = arrb->stack[tmp - 1];
		tmp--;
	}
	arrb->stack[0] = arra->stack[0];
	i = 0;
	while (i < arra->len - 1)
	{
		arra->stack[i] = arra->stack[i + 1];
		i++;
	}
	arra->len--;
}

void ft_ra_ch(t_stack_checker *arra)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arra->stack[i];
	while (i < arra->len - 1)
	{
		arra->stack[i] = arra->stack[i + 1];
		i++;
	}
	arra->stack[arra->len - 1] = tmp;
}

void ft_rb_ch(t_stack_checker *arrb)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arrb->stack[i];
	while (i < arrb->len)
	{
		arrb->stack[i] = arrb->stack[i + 1];
		i++;
	}
	arrb->stack[arrb->len - 1] = tmp;
}

void ft_rr_ch(t_stack_checker *arrb, t_stack_checker *arra)
{
	ft_rb_ch(arrb);
	ft_ra_ch(arra);
}

void ft_rra_ch(t_stack_checker *arra)
{
	int	i;
	int	tmp;

	i = arra->len - 1;
	tmp = arra->stack[i];
	while (i > 0)
	{
		arra->stack[i] = arra->stack[i - 1];
		i--;
	}
	arra->stack[0] = tmp;
}

void ft_rrb_ch(t_stack_checker *arrb)
{
			int	i;
	int	tmp;

	i = arrb->len - 1;
	tmp = arrb->stack[i];
	while (i > 0)
	{
		arrb->stack[i] = arrb->stack[i - 1];
		i--;
	}
	arrb->stack[0] = tmp;
}

void ft_rrr_ch(t_stack_checker *arrb, t_stack_checker *arra)
{
	ft_rrb_ch(arrb);
	ft_rra_ch(arra);
}