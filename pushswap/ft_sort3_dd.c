
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

void	ft_sort2(t_stack *stack)
{
	t_node *curr;

	curr = stack->tail_a;
	if (curr->index < curr->next->index)
		ft_ra(stack);
	else
		return;
}

void	ft_sort3(t_stack *stack, int count, int min_index)
{
	int max_index;

	if (ft_nodechecksort(&stack->tail_a) == 0)
		return ;
	else
	{
		max_index = min_index + count - 1;
		if (stack->tail_a->next->next->index == max_index)
			ft_ra(stack);
		else if (stack->tail_a->next->index == max_index)
			ft_rra(stack);
		if (ft_nodechecksort(&stack->tail_a) == 1)
			ft_sa(stack);
	}

}

