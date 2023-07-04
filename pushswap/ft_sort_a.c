
#include "libpushswap.h"

int	ft_nodechecksort(t_node **root)
{
	t_node	*curr;

	curr = *root;
	// ft_printf("Check sort: ");
	while (curr->next != NULL)
	{
		if (curr->value < curr->next->value)
		{
			// ft_printf(" no !!!!!!!!\n");
			return (1);
		}
		curr = curr->next;
	}
	// ft_printf("YES <3\n");
	return (0);
}

void	ft_sort2_b(t_stack *s)
{
	if (ft_nodechecksort(&s->root_a) == 1)
		ft_sb(s);
	else
		return;
}

void	ft_sort2_a(t_stack *s)
{
	t_node *curr;

	curr = s->root_a;
	if (curr->index < curr->next->index)
		ft_ra(s);
	else
		return;
}

void	ft_sort3_a(t_stack *stack, int count)
{
	// int min_index;
	int max_index;

	if (ft_nodechecksort(&stack->root_a) == 0)
		return ;
	// min_index = count - 3;
	max_index = count - 1;
	// ft_printf("min_index: %d\n", min_index);
	// ft_printf("max_index: %d\n", max_index);
	if (stack->root_a->next->next->index == max_index)
		ft_ra(stack);
	else if (stack->root_a->next->index == max_index)
		ft_rra(stack);
	if (ft_nodechecksort(&stack->root_a) == 1)
		ft_sa(stack);
}

void	ft_sort4_a(t_stack *stack, int count)
{
	int min_index;

	min_index = count - 4;
	// ft_printf("min_index: %d\n", min_index);
	if (ft_nodechecksort(&stack->root_a) == 0)
		return ;
	while (stack->root_a->next->next->next->index != min_index)
	{
		if (stack->root_a->index == min_index)
			ft_rra(stack);
		else if (stack->root_a->next->index == min_index)
			ft_ra(stack);
		else if (stack->root_a->next->next->index == min_index)
			ft_sa(stack);
	}
	ft_pb(stack);
	// ft_showindex(stack);
	ft_sort3_a(stack, count);
	ft_pa(stack);
}

void	ft_sort5_a(t_stack *stack, int count)
{
	int min_index;

	min_index = count - 5;
	// ft_printf("min_index: %d\n", min_index);
	if (ft_nodechecksort(&stack->root_a) == 0)
		return ;
	while (stack->root_a->next->next->next->next->index != min_index)
	{
		if (stack->root_a->next->next->next->index == min_index)
			ft_sa(stack);
		else if (stack->root_a->next->next->index == min_index)
			ft_ra(stack);
		else
			ft_rra(stack);
	}
	ft_pb(stack);
	// ft_showindex(stack);
	ft_sort4_a(stack, count);
	ft_pa(stack);
}

void	ft_sort6_a(t_stack *stack, int count)
{
	int min_index;

	min_index = count - 6;
	// ft_printf("min_index: %d\n", min_index);
	if (ft_nodechecksort(&stack->root_a) == 0)
		return ;
	while (stack->root_a->next->next->next->next->next->index != min_index)
	{
		if (stack->root_a->next->next->next->next->index == min_index)
			ft_sa(stack);
		else if (stack->root_a->next->next->next->index == min_index)
			ft_rra(stack);
		else
			ft_ra(stack);
	}
	ft_pb(stack);
	// ft_showindex(stack);
	ft_sort5_a(stack, count);
	ft_pa(stack);
}
