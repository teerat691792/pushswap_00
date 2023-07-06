
#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				index;
	int				value;
	int				target;
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


/*singly linked list functions*/

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
// void	ft_sa(t_stack *stack);
// void	ft_sb(t_stack *stack);
// void	ft_ss(t_stack *stack);
// void	ft_ra(t_stack *stack);
// void	ft_rb(t_stack *stack);
// void	ft_rr(t_stack *stack);
// void	ft_rra(t_stack *stack);
// void	ft_rrb(t_stack *stack);
// void	ft_rrr(t_stack *stack);
// void	ft_pb(t_stack *stack);
// void	ft_pa(t_stack *stack);

//ft_sort_a.c
int		ft_nodechecksort(t_node **root);
void	ft_sort2(t_stack *s);

//ft_sortmore.c
int		ft_findindexmin(t_node **root);
int		ft_findnodemin(t_node **root, int count, int min_index);
void	ft_sortmore(t_stack *s, int count);
void 	ft_sortrepeat(t_stack *stack, int count, int min_index, int min_rank);
void	ft_sort3(t_stack *s, int count, int min_index);

#endif
