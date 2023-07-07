
#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include "libft/libft.h"

# define RANGE_MAX 30

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*snd_a;
	t_node	*snd_b;
	t_node	*tail_a;
	t_node	*tail_b;
	t_node	*root_a;
	t_node	*root_b;
	int		len;
	int		portion;
	int		max_port;
	int		push;
}	t_stack;

/*double linked list functions*/

//ft_node_dd.c
t_node	*ft_nodenew_dd(int value);
void	ft_nodeaddback_dd(t_node **tail, int value);
void	ft_nodeaddfront_dd(t_node **head, int value);
void	ft_nodeclear_dd(t_node **head);
void	ft_pointnode_dd(t_stack *stack);
void	ft_stackclear_dd(t_stack *stack);

//ft_show_dd.c
void	ft_printstack_dd(t_node *stack);
void	ft_showstack_dd(t_stack *stack);
void	ft_showindex_dd(t_stack *stack);
void	ft_printindex_dd(t_node *stack);
void	ft_showvertical_dd(t_stack *stack);

//ft_index_dd.c
void	ft_noderead_dd(t_stack *stack);
int		ft_nodecount_dd(t_node *node);
void	ft_nodecopy_dd(t_node *tail, int *arr);
void	ft_putindex_dd(t_node **tail, int *arr);


//ft_mergesort_dd.c
void ft_mergesort_dd(int *arr, int len);
void	ft_startsort_dd(int *arr, int lf, int rg);
void	ft_mergearr_dd(int *arr,int lf, int mid, int rg);
void	ft_mergeput_dd(int *arr, int *tmp, int *k, int *index);
void	ft_copyarr_dd(int *dst, int *src, int index, int len);

//ft_operate_dd.c
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

//ft_sort3_dd.c
int		ft_nodechecksort(t_node **root);
void	ft_sort2(t_stack *stack);
void	ft_sort3(t_stack *stack, int count, int min_index);

//ft_sortmore_dd.c
void ft_sortmore(t_stack *stack, int count);
void 	ft_sortrepeat(t_stack *stack, int count, int min_index, int min_rank);

//ft_presort_dd.c
void	ft_portionsort_dd(t_stack *stack);
void	ft_presortoption(t_stack *stack);

#endif
