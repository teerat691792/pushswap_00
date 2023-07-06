
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

int	ft_findnodemin(t_node **root, int count, int min_index)
{
	t_node	*curr;

	if (*root == NULL)
		return (-2);
	curr = *root;
	count--;
	while (curr != NULL)
	{
		if (curr->index == min_index)
			return (count);
		curr = curr->next;
		count--;
	}
	return (-1);
}

void ft_sortmore(t_stack *stack, int count)
{
	int		min_index;
	int		min_rank;

	if (ft_nodechecksort(&stack->tail_a) == 0)
		return ;
	min_index = ft_findindexmin(&stack->tail_a);
	min_rank = ft_findnodemin(&stack->tail_a, count, min_index);
	if (min_index == -1 || min_rank == -1)
		return ;
	if (count == 3)
		ft_sort3(stack, count, min_index);
	else
		ft_sortrepeat(stack, count, min_index, min_rank);
}


void 	ft_sortrepeat(t_stack *stack, int count, int min_index, int min_rank)
{
	if (ft_nodechecksort(&stack->tail_a) == 0)
		return ;
	else
	{
		while (min_rank != 0)
		{
			if (min_rank == 1)
				ft_sa(stack);
			else if (min_rank < (count / 2) + 1)
				ft_ra(stack);
			else
				ft_rra(stack);
			min_rank = ft_findnodemin(&stack->tail_a, count, min_index);
		}
		ft_pb(stack);
		ft_sortmore(stack, count - 1);
		ft_pa(stack);
	}
}
