
#include "libpushswap.h"

void	ft_bubblesort_dd(t_stack *stack)
{
	int		portion;

	portion = 5;
	stack->count = 0;
	stack->len = ft_nodecount_dd(stack->tail_a);
	stack->range = stack->len / portion;
	stack->limit = stack->range;
	stack->half = stack->limit / 2;
	ft_divideportion(stack);
	ft_insertback(stack);
}

void	ft_divideportion(t_stack *stack)
{
	int		first;

	while (stack->count < stack->len)
	{
		if (stack->count == stack->limit)
		{
			stack->limit += stack->range;
			stack->half += stack->range;
		}
		first = stack->head_a->index;
		if (first < stack->limit && first < stack->half)
		{
			ft_pb(stack);
			stack->count++;
		}
		else if (first < stack->limit && first >= stack->half)
		{
			ft_pb(stack);
			ft_rb(stack);
			stack->count++;
		}
		else if (first >= stack->limit)
			ft_ra(stack);
	}
}

void	ft_insertback(t_stack *stack)
{
	int		top;
	int		bot;
	int		big;

	stack->len = ft_nodecount_dd(stack->tail_b) - 1;
	ft_findbigindex(stack, &top, &bot, &big);
	if (top < bot)
	{
		while (stack->head_b->index != big)
			ft_rb(stack);
		ft_pa(stack);
	}
	else
	{
		while (stack->head_b->index != big)
			ft_rrb(stack);
		ft_pa(stack);
	}
	if (stack->head_b != NULL)
		ft_insertback(stack);
}

void	ft_findbigindex(t_stack *stack, int *top, int *bot, int *big)
{
	int		index;
	t_node	*curr;

	index = 0;
	curr = stack->head_b;
	while (curr != NULL)
	{
		if (curr->index == stack->len)
		{
			stack->half = index;
			break ;
		}
		index++;
		curr = curr->prev;
	}
	*bot = stack->len - stack->half;
	*top = stack->half;
	*big = stack->len;
}
