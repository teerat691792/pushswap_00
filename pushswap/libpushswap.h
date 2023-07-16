
#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include "libft/libft.h"

# define RANGE_MAX 100

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct s_merge
{
	int		*arr;
	int		lf;
	int		mid;
	int		rg;
	int		*tmp_lf;
	int		*tmp_rg;
}	t_merge;

typedef struct s_stack
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*snd_a;
	t_node	*snd_b;
	t_node	*tail_a;
	t_node	*tail_b;
	int		len;
	int		limit;
	int		range;
	int		half;
	int		count;
}	t_stack;

/*double linked list functions*/

//ft_stack.c
void	ft_stackinit(t_stack *stack);
void	ft_startpushswap(t_stack *stack, int argc, char **argv);
int		ft_checkerror(int argc, char **argv);
int		ft_isnumber(char *str);
int		ft_isdup(int argc, char **argv);

//ft_node_dd.c
void	ft_nodeaddfront_dd(t_node **head, int value);
t_node	*ft_nodenew_dd(int value);
void	ft_pointnode_dd(t_stack *stack);
void	ft_nodeclear_dd(t_node **head);
void	ft_stackclear_dd(t_stack *stack);

//ft_index_dd.c
void	ft_noderead_dd(t_stack *stack);
int		ft_nodecount_dd(t_node *node);
void	ft_nodecopy_dd(t_node *tail, int *arr);
void	ft_putindex_dd(t_node **tail, int *arr);

//ft_mergesort_dd.c
void	ft_startsort_dd(t_merge *merge, int lf, int rg);
void	ft_mergearr_dd(t_merge *merge, int lf, int mid, int rg);
void	ft_mergeoption(t_merge *merge, int lf, int mid, int rg);
void	ft_mergeput_dd(int *arr, int *tmp, int *k, int *index);
void	ft_copyarr_dd(int *dst, int *src, int index, int len);

//ft_sortmin_dd.c
int		ft_nodechecksort(t_node **root);
void	ft_sort2_dd(t_stack *stack);
void	ft_sort3_dd(t_stack *stack, int count, int min_index);

//ft_operate_dd.c
void	ft_pushcont_(t_node **head_dst, t_node **head_src);
void	ft_push_stack(t_node **head_dst, t_node **head_src);
void	ft_pb(t_stack *stack);
void	ft_pa(t_stack *stack);

//ft_swap_dd.c
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_swapsecondtop(t_node **head, t_node **snd);

//ft_rotate_dd.c
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_shiftup(t_node **head, t_node **tail);

//ft_reverse_dd.c
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);
void	ft_shiftdown(t_node **head, t_node **tail);

//ft_sortmore_dd.c
void	ft_sortmore_dd(t_stack *stack, int count);
void	ft_sortrepeat(t_stack *stack, int count, int min_index, int min_rank);

//ft_bubblesort_dd.c
void	ft_bubblesort_dd(t_stack *stack);
void	ft_divideportion(t_stack *stack);
void	ft_pushportion(t_stack *stack);

//ft_bubblecont_dd.c
void	ft_insertback(t_stack *stack);
int		ft_findbigindex(t_stack *stack, int *top, int *bot, int *big);
void	ft_pushbig(t_stack *stack, int top, int bot);

#endif
