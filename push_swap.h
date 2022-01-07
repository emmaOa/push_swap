#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int *stack;
	int len;
}	t_stack;
int	ft_atoi(const char *str);
void ft_sa(t_stack *arra);
void ft_swap(int *a, int *b);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void ft_rra(t_stack *arra);
void ft_ra(t_stack *arra);
void ft_pb(t_stack *arra, t_stack *arrb);
void ft_pa(t_stack *arra, t_stack *arrb);
void ft_sb(t_stack *arrb);
void ft_rb(t_stack *arrb);
void ft_rrb(t_stack *arrb);
void call(char *s, void (*f)(t_stack *arr), t_stack *t);
#endif