
#include "libpushswap.h"

void	ft_bubblesort_dd(t_stack *stack)
{
	int		portion;

	portion = 5;
	stack->count = 0;
	stack->len = ft_nodecount_dd(stack->tail_a);
	if (stack->len > 300)
		portion = 11;
	stack->range = stack->len / portion;
	stack->limit = stack->range;
	stack->half = stack->limit / 2;
	ft_divideportion(stack);
	stack->limit = stack-> len - stack->range;
	stack->count = 0;
	ft_insertback(stack);
}

void	ft_divideportion(t_stack *stack)
{
	while (stack->count < stack->len)
	{
		if (stack->count == stack->limit)
		{
			stack->limit += stack->range;
			stack->half += stack->range;
		}
		ft_pushportion(stack);
	}
}

void	ft_pushportion(t_stack *stack)
{
	t_node	*first;

	first = stack->head_a;
	if (first->index < stack->limit && first->index < stack->half)
	{
		ft_pb(stack);
		stack->count++;
	}
	else if (first->index < stack->limit && first->index >= stack->half)
	{
		if (first->prev != NULL)
			first = first->prev;
		ft_pb(stack);
		if (first->index >= stack->limit)
			ft_rr(stack);
		else
			ft_rb(stack);
		stack->count++;
	}
	else if (first->index >= stack->limit)
		ft_ra(stack);
}
