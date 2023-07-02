
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
	void	*root_a;
	void	*root_b;
}	t_stack;

//ft_stack.c
void	ft_stackinit(t_stack **stack);

//ft_show.c
void ft_print_stack(t_node *stack);
void ft_showstack(t_stack *stack);

//ft_pushswap.c
void	ft_test(void);

//ft_node.c
t_node	*ft_nodenew(int value);
void	ft_nodeaddback(void **root, int value);
void	ft_nodeclear(void **root);
void	ft_nodeclear_rcs(t_node *node);
void	ft_nodeaddfront(void **root, int value);
void	ft_nodeaddback_v(void **root, int value);
//void	ft_nodeaddafter_i(void **root, int value , int index);
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


#endif
