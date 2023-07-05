
#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	void			*content;
	int				index;
	int				value;
	int				target;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node	*root_a;
	t_node	*root_b;
}	t_stack;

//ft_stack.c
void	ft_stackinit(t_stack **stack);

//ft_mergesort.c
void	ft_merge_sort(int *arr, int len);
void	ft_merge_rcs(int *arr, int lf, int rg);
void	ft_merge_arr(int *arr,int lf, int mid, int rg);
void	ft_merge_put(int *arr, int *tmp, int *k, int *index);
void	ft_copyarr(int *dst, int *src, int index, int len);
void	ft_readarr(int *arr, int len);
void	ft_noderead(t_stack *stack);
void	ft_nodecopy(t_node *stack, int *arr);
void	ft_putindex(t_node **root, int *arr);

//ft_show.c
void	ft_print_stack(t_node *stack);
void	ft_showstack(t_stack *stack);
void	ft_showindex(t_stack *stack);

//ft_pushswap.c
void	ft_test(void);

//ft_node.c
t_node	*ft_nodenew(int value);
void	ft_nodeaddback(t_node **root, int value);
void	ft_nodeclear(t_node **root);
void	ft_nodeclear_rcs(t_node *node);
void	ft_nodeaddfront(t_node **root, int value);
void	ft_nodeaddback_v(void **root, int value);
int		ft_checkloopexist(void **root);
int		ft_nodecount_itr(void **root);
int		ft_nodecount_rcs(t_node *node);

//ft_operate.c
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_pa(t_stack *stack);

//ft_sort_a.c
t_node	*ft_findtop(t_node **root);
t_node	*ft_findsecond(t_node **root);
t_node	*ft_findthird(t_node **root);
int		ft_nodechecksort(t_node **root);
void	ft_sort2_b(t_stack *s);
void	ft_sort2_a(t_stack *s);
void	ft_sort3_a(t_stack *s, int count);
void	ft_sort4_a(t_stack *s, int count);
void	ft_sort5_a(t_stack *s, int count);
void	ft_sort6_a(t_stack *s, int count);


#endif
