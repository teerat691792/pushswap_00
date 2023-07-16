
#include "libpushswap.h"

void	ft_rb(t_stack *stack)
{
	ft_shiftup(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rb\n");
}

void	ft_ra(t_stack *stack)
{
	ft_shiftup(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_printf("ra\n");
}

void	ft_rr(t_stack *stack)
{
	ft_shiftup(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_shiftup(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rr\n");
}

void	ft_shiftup(t_node **head, t_node **tail)
{
	t_node	*last;
	t_node	*first;

	last = *tail;
	first = *head;
	last->prev = first;
	if (first->prev != NULL)
	{
		*head = first->prev;
		first->prev->next = NULL;
	}
	first->next = last;
	first->prev = NULL;
	*tail = first;
}
