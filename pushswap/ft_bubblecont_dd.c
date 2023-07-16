
#include "libpushswap.h"

void	ft_insertback(t_stack *stack)
{
	int		top;
	int		bot;
	int		big;

	if (stack->len == stack->limit)
			stack->limit = stack->limit - stack->range;
	big = ft_findbigindex(stack, &top, &bot, &big);
	ft_pushbig(stack, top, bot);
	if (stack->head_b != NULL)
		ft_insertback(stack);
}

int	ft_findbigindex(t_stack *stack, int *top, int *bot, int *big)
{
	int		index;
	t_node	*curr;

	index = 0;
	stack->len = ft_nodecount_dd(stack->tail_b) - 1;
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
	*bot = stack->len - stack->half + 1;
	*top = stack->half;
	*big = stack->len;
	if (*top < *bot)
		return (*top);
	else
		return (*bot);
}

void	ft_pushbig(t_stack *stack, int top, int bot)
{
	if (top < bot)
	{
		while (top-- > 0)
			ft_rb(stack);
		ft_pa(stack);
		stack->count++;
	}
	else if (top >= bot)
	{
		while (bot-- > 0)
			ft_rrb(stack);
		ft_pa(stack);
		stack->count++;
	}
}
