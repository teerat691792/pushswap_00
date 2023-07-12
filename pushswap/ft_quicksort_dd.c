
#include "libpushswap.h"


void	ft_initquick_dd(t_stack *stack)
{
	int len;

	// ft_showvertical_dd(stack);
	// ft_showindex_dd(stack);
	len = ft_nodecount_dd(stack->tail_a);
	// ft_partition_dd(stack, 0, len - 1);
	ft_quicksort_dd(stack, 0, len - 1);
	// ft_showvertical_dd(stack);
}


void	ft_quicksort_dd(t_stack *stack, int low, int high)
{
	int mid;
	// int pop;

	if (low < high)
	{
		mid = ft_partition_dd(stack, low, high);
		// ft_showvertical_dd(stack);
		// mid = ft_partition_min_dd(stack, low, high);

		ft_quicksort_dd(stack, mid + 1, high);
		ft_popback(stack, low, mid);
	}
	// else
		// ft_printf("END TREE ___+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_____\n");
	// ft_showvertical_dd(stack);
}

int		ft_partition_dd(t_stack *stack, int low, int high)
{
	int pivot;
	int push;

	// ft_printf("ENTER MAX+++++\t");
	pivot = ((high - low) / 2) + low;
	push = (high - low + 1) / 2;
	// ft_printf("range count = %d\t", high - low + 1);
	// ft_printf("mod = %d\t", (high - low + 1) % 2);
	if ((high - low + 1) % 2 == 1)
		push = push + 1;

	// ft_printf("push: %d\t", push);
	// ft_printf("low: %d\t", low);
	// ft_printf("pivt: %d\t", pivot);
	// ft_printf("high: %d\n", high);

	if (push == 0)
		return (pivot);
	else if (push == 1)
	{
		if (stack->head_a->index > stack->head_a->prev->index)
			ft_sa(stack);
		// ft_pb(stack);
	}
	else
	{
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
		if (stack->tail_a->index < stack->head_a->index)
			ft_rra(stack);
	}
	// push = (high + 1 - low) / 2;
	// while (push > 0)
	// {
	// 	ft_pa(stack);
	// 	push--;
	// }
	// ft_showvertical_dd(stack);
	return (pivot);
}

void	ft_popback(t_stack *stack, int low, int high)
{
	int		pop;
	int 	mid;

	// ft_printf("ENTER ----POP\t");
	pop = (high + 1 - low);
	// ft_printf("range count = %d\t", high - low + 1);
	// ft_printf("pop: %d\t", pop);
	// ft_printf("low: %d\t", low);
	// ft_printf("high: %d\n", high);
	if (pop == 0)
		return ;
	else if (pop == 1)
	{
		// ft_pa(stack);
		return ;
	}
	else if (pop == 2)
	{
		ft_pa(stack);
		ft_pa(stack);
		if (stack->head_a->index > stack->head_a->prev->index)
			ft_sa(stack);
	}
	// else if (pop < 5)
	// {
	// 	mid = (high - low) / 2 + low;
	// 	ft_printf("more pop => mid: %d\n", mid);
	// 	ft_popback(stack, mid + 1, high);
	// 	ft_popback(stack, low, mid);
	// }
	else
	{
		mid = (high - low + 1);
		// ft_printf("exceed pop => mid: %d\n", mid);
		while (mid > 0)
		{
			ft_pa(stack);
			mid--;
		}
		ft_quicksort_dd(stack, low, high);
	}
	// ft_showvertical_dd(stack);

}
