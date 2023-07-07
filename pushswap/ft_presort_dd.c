
#include "libpushswap.h"

void	ft_portionsort_dd(t_stack *stack)
{
	int	max_port;

	stack->len = ft_nodecount_dd(stack->tail_a);
	ft_printf("stack->len : %d\n", stack->len);
	while (stack->len / stack->portion > RANGE_MAX)
		stack->portion++;
	ft_printf("portion: %d\t\t", stack->portion);
	max_port = stack->len / stack->portion;
	ft_printf("max_port: %d\n", max_port);
	ft_presortoption(stack);
}

void	ft_presortoption(t_stack *stack)
{

	if (stack->push >= stack->max_port)
		stack->max_port = stack->max_port + RANGE_MAX;
	else
	if (stack->head_a->index < stack->max_port)
	{
		ft_pb(stack);
		stack->push++;
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
}
