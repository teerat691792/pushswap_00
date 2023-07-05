
#include "libpushswap.h"

int	ft_nodechecksort(t_node **root)
{
	t_node	*curr;

	curr = *root;
	while (curr->next != NULL)
	{
		if (curr->value < curr->next->value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	ft_sort2(t_stack *s)
{
	t_node *curr;

	curr = s->root_a;
	if (curr->index < curr->next->index)
		ft_ra(s);
	else
		return;
}
