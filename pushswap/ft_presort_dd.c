
#include "libpushswap.h"

void	ft_portionsort_dd(t_stack *stack)
{
	// int	max_port;

	stack->len = ft_nodecount_dd(stack->tail_a);
	while (stack->len / stack->portion > RANGE_MAX)
		stack->portion++;
	stack->max_port = stack->len / stack->portion;
	// ft_printf("stack->len : %d\t\t", stack->len);
	// ft_printf("portion: %d\t\t", stack->portion);
	// ft_printf("max_port: %d\n", max_port);
	ft_presortoption(stack);
	// ft_showvertical_dd(stack);
}

void	ft_presortoption(t_stack *stack)
{
	while (stack->head_a->prev->prev->prev != NULL)
	{
		// ft_printf("stack->max_port: %d\n", stack->max_port);
		if (stack->push >= stack->max_port)
			stack->max_port = stack->max_port + RANGE_MAX;
		else
		if (stack->head_a->index < stack->max_port)
		{
			ft_pb(stack);
			stack->push++;
			// ft_printf("push: %d\n", stack->push);
		}
		else if (stack->head_a->index > stack->snd_a->index \
				&& stack->snd_a->index < stack->max_port)
			ft_sa(stack);
		else if (stack->snd_a->index > stack->snd_a->prev->index \
				&& stack->snd_a->prev->index < stack->max_port)
			ft_ra(stack);
		else if (stack->head_a->index > stack->tail_a->index \
				&& stack->tail_a->index < stack->max_port)
			ft_rra(stack);
		else
			ft_rra(stack);
	}
	ft_sortmore(stack, 3);
}

