
#include "libpushswap.h"

void	ft_rra(t_stack *stack)
{
	ft_shiftdown(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *stack)
{
	ft_shiftdown(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack *stack)
{
	ft_shiftdown(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_shiftdown(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rrr\n");
}

void	ft_shiftdown(t_node **head, t_node **tail)
{
	t_node	*last;
	t_node	*first;

	first = *head;
	last = *tail;
	if (last->next != NULL)
	{
		*tail = last->next;
		last->next->prev = NULL;
	}
	first->next = last;
	last->prev = first;
	last->next = NULL;
	*head = last;
}
