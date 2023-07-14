
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
	// ft_showvertical_dd(stack);
	ft_insertback(stack);
	// ft_showvertical_dd(stack);
}

void	ft_divideportion(t_stack *stack)
{
	t_node	*first;

	while (stack->count < stack->len)
	{
		if (stack->count == stack->limit)
		{
			stack->limit += stack->range;
			stack->half += stack->range;
			// ft_printf("limit: %d\n", stack->limit);
		}
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
}

void	ft_insertback(t_stack *stack)
{
	int		top;
	int		bot;
	int		big;
	// int		small;
	// int		first;

	if (stack->len == stack->limit)
			stack->limit = stack->limit - stack->range;
	// ft_printf("***count: %d\t", stack->count);
	// ft_printf("*****len: %d\t", stack->len);
	// ft_printf("***limit: %d\t", stack->limit);
	// ft_printf("***range: %d\n", stack->range);
	// if (stack->count == 0)
	// {
		// big = ft_findbigindex(stack, &top, &bot, &big);
		// ft_printf("FIRST ==>> big   : %d\t top : %d\t bot : %d\n", big, top, bot);
		// ft_pushbig(stack, top, bot);
		// ft_insertback(stack);
	// }
	// if (stack->count > 2)
	// {
	// 	first = stack->head_a->prev->index;
	// 	if (first - 1 != stack->head_a->index)
	// 		ft_ra(stack);
	// 	small = stack->tail_a->index;
	// 	if (small + 1 == stack->head_a->index)
	// 		ft_rra(stack);
	// }
	// small = ft_findsmallindex(stack, &top, &bot, &small);
	// ft_printf("small : %d\t top : %d\t bot : %d\n", small, top, bot);
	big = ft_findbigindex(stack, &top, &bot, &big);
	// ft_printf("big   : %d\t top : %d\t bot : %d\n", big, top, bot);
	// if (big <= small)
		ft_pushbig(stack, top, bot);
	// else
		// ft_pushsmall(stack, top, bot);
	// ft_showvertical_dd(stack);
	if (stack->head_b != NULL)
		ft_insertback(stack);
}

int		ft_findbigindex(t_stack *stack, int *top, int *bot, int *big)
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
	// ft_printf("*****big : %d\t top : %d\t bot : %d\n", big, top, bot);
	if (top < bot)
	{
		// while (stack->head_b->index != big)
		while (top-- > 0)
		{
			// ft_printf("top big LOOP\n");
			ft_rb(stack);
		}
		ft_pa(stack);
		stack->count++;
	}
	else if (top >= bot)
	{
		// while (stack->head_b->index != big)
		while (bot-- > 0)
		{
			ft_rrb(stack);
			// ft_printf("bot big LOOP\n");
		}
		ft_pa(stack);
		stack->count++;
	}
}

int		ft_findsmallindex(t_stack *stack, int *top, int *bot, int *small)
{
	t_node	*node;
	int		index;

	index = 0;
	stack->len = ft_nodecount_dd(stack->tail_b) - 1;
	node = stack->head_b;
	while (node != NULL)
	{
		if (node->index == stack->limit)
		{
			stack->half = index;
			break ;
		}
		index++;
		node = node->prev;
	}
	*bot = stack->len - stack->half + 1;
	*top = stack->half;
	*small = stack->limit;
	if (*top < *bot)
		return (*top);
	else
		return (*bot);
}

void	ft_pushsmall(t_stack *stack, int top, int bot)
{
	// ft_printf("***small : %d\t top : %d\t bot : %d\n", small, top, bot);
	if (top < bot)
	{
		// while (stack->head_b->index != small)
		while (top-- > 0)
		{
			// ft_printf("top small LOOP\n");
			ft_rb(stack);
		}
		ft_pa(stack);
		ft_ra(stack);
		stack->count++;
	}
	else if (top >= bot)
	{
		// while (stack->head_b->index != small)
		while (bot-- > 0)
		{
			// ft_printf("bot small LOOP\n");
			ft_rrb(stack);
		}
		ft_pa(stack);
		ft_ra(stack);
		stack->count++;
	}
}
