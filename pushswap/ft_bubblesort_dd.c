
#include "libpushswap.h"

void	ft_bubblesort_dd(t_stack *stack)
{
	int		portion;

	portion = 5;
	stack->count = 0;
	stack->len = ft_nodecount_dd(stack->tail_a);
	if (stack->len > 100)
		portion = 11;
	stack->range = stack->len / portion;
	stack->limit = stack->range;
	stack->half = stack->limit / 2;
	ft_divideportion(stack);
	// ft_showvertical_dd(stack);
	stack->limit = stack-> len - stack->range;
	stack->count = 0;
	ft_insertback(stack);
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

void	ft_findsmallindex(t_stack *stack, int *top, int *bot, int *small)
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
	*bot = stack->len - stack->half;
	*top = stack->half;
	*small = stack->limit;
}

void	ft_insertback(t_stack *stack)
{
	int		top;
	int		bot;
	int		big;
	// int		small;

	if (stack->len == stack->limit)
	{

			stack->limit = stack->limit - stack->range;

	}
	// ft_printf("*******count: %d\n", stack->count);
	// ft_printf("*******len: %d\n", stack->len);
	// ft_printf("*******stack-limit: %d\n", stack->limit);
	// ft_printf("*******stack-range: %d\n", stack->range);
	// ft_findsmallindex(stack, &top, &bot, &small);
	// ft_printf("small : %d\t top : %d\t bot : %d\n", small, top, bot);
	ft_findbigindex(stack, &top, &bot, &big);
	// ft_printf("big   : %d\t top : %d\t bot : %d\n", big, top, bot);
	// if (stack->head_b->index >= stack->limit)
	// if (stack->head_b->index == stack->limit || stack->head_b->index - 1 == stack->tail_b->index)
	// {
	// 	ft_pa(stack);
	// 	ft_ra(stack);
	// 	stack->count++;
	// }

	// if (stack->tail_a != NULL)
	// {
	// 	if (stack->tail_a->index + 1 == stack->head_a->index)
	// 		ft_rra(stack);
	// }
	if (top < bot)
	{
		while (stack->head_b->index != big)
			ft_rb(stack);
		ft_pa(stack);
		stack->count++;
	}
	else if (top >= bot)
	{
		while (stack->head_b->index != big)
			ft_rrb(stack);
		ft_pa(stack);
		stack->count++;
	}


	if (stack->head_b != NULL)
	// if (stack->head_b != NULL || stack->head_a->index != 0)
		ft_insertback(stack);
}

void	ft_findbigindex(t_stack *stack, int *top, int *bot, int *big)
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
	*bot = stack->len - stack->half;
	*top = stack->half;
	*big = stack->len;
}
