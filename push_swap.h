#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>

int	ft_atoi(const char *str);
void ft_sa(int *arra);
void ft_swap(int *a, int *b);
void ft_rra(int *arra);
void ft_ra(int *arra);
void ft_pb(int *arra, int *arrb, int len_arra);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
#endif