
#include "libpushswap.h"

void	ft_initquick_dd(t_stack *stack)
{
	int len;

	len = ft_nodecount_dd(stack->tail_a);
	ft_quicksort_dd(stack, 0, len - 1);
}

void	ft_quicksort_dd(t_stack *stack, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = ft_partition_dd(stack, low, high);
		// ft_showvertical_dd(stack);
		ft_quicksort_dd(stack, mid + 1, high);
		// ft_quicksort_dd(stack, low, mid);
	}
}

int		ft_partition_dd(t_stack *stack, int low, int high)
{
	int pivot;
	int push;

	pivot = ((high - low) / 2) + low;
	push = (high + 1 - low) / 2;
	// ft_printf("low: %d\n", low);
	// ft_printf("pivot: %d\n", pivot);
	// ft_printf("high: %d\n", high);
	// ft_printf("push: %d\n", push);

	while (push > 0)
	{
		if (stack->head_a->index > pivot)
		{
			ft_ra(stack);
		}
		else if (stack->head_a->index == pivot)
		{
			ft_pb(stack);
			push--;
			ft_rb(stack);
		}
		else //head_a->index < pivot
		{
			// ft_ra(stack);
			ft_pb(stack);
			push--;
		}
	}
	ft_rrb(stack);
	return (pivot);
}
