
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

void	ft_test(void);

//ft_node
t_node	*ft_nodenew(int value);
void	ft_nodeaddback(void **root, t_node *node);
void	ft_nodeclear(void **root);
void	ft_nodeclear_rcs(t_node *node);

#endif
