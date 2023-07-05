
#include "libpushswap.h"

int	ft_findindexmin(t_node **root)
{
	t_node	*curr;
	int		min;

	if (*root == NULL)
		return (-1);
	curr = *root;
	min = curr->index;
	while (curr != NULL)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
	}
	return (min);
}

void	ft_sort7_a(t_stack *stack, int count)
{
	int		min_index;
	int		min_rank;

	if (ft_nodechecksort(&stack->root_a) == 0)
		return ;
	min_index = ft_findindexmin(&stack->root_a);
	min_rank = ft_findnodemin(&stack->root_a, count, min_index);
	if (min_index == -1 || min_rank == -1)
		return ;
	while (min_rank != 0)
	{
		if (min_rank == 1)
			ft_sa(stack);
		else if (min_rank < (count / 2) + 1)
			ft_ra(stack);
		else
			ft_rra(stack);
		min_rank = ft_findnodemin(&stack->root_a, count, min_index);
	}
	ft_pb(stack);
	// ft_showindex(stack);
	ft_sort6_a(stack, count);
	ft_pa(stack);
}
