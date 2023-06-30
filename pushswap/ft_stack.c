
#include "libpushswap.h"

void	ft_stackinit(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	stack->root_b = NULL;
	stack->root_a = NULL;
}
