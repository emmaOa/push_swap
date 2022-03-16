/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:41:55 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/16 10:38:22 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct t_stack_checker
{
	int		*stack;
	int		len;
}	t_stack_checker;

typedef struct t_sign_checker
{
	int		nb;
	int		nb2;
}	t_sign_checker;

void			ft_swap_ch(int *a, int *b);
void			ft_sa_ch(t_stack_checker *arra);
void			ft_sb_ch(t_stack_checker *arrb);
void			ft_ss_ch(t_stack_checker *arrb, t_stack_checker *arra);
void			ft_pa_ch(t_stack_checker *arra, t_stack_checker *arrb);
void			ft_pb_ch(t_stack_checker *arra, t_stack_checker *arrb);
void			ft_ra_ch(t_stack_checker *arra);
void			ft_rb_ch(t_stack_checker *arrb);
void			ft_rr_ch(t_stack_checker *arrb, t_stack_checker *arra);
void			ft_rra_ch(t_stack_checker *arra);
void			ft_rrb_ch(t_stack_checker *arrb);
void			ft_rrr_ch(t_stack_checker *arrb, t_stack_checker *arra);
int				ft_atoi_checker(const char *str);
int				ft_checker(t_stack_checker *arra);
int				ft_double_checker(t_stack_checker *lin, int nb, int ac);
void			ft_instraction(char *out_get, t_stack_checker *arra,
					t_stack_checker *arrb);
void			ft_error_checker(void);
t_sign_checker	ft_sign_checker(char *str);
int				ft_isdigit_chacker(int a);

#endif