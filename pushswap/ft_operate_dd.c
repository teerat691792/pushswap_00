
#include "libpushswap.h"

void	ft_pushcont_(t_node **head_dst, t_node **head_src)
{
	t_node	*first_dst;
	t_node	*first_src;

	first_dst = *head_dst;
	first_src = *head_src;
	if (first_src->prev != NULL)
	{
		*head_src = first_src->prev;
		first_src->prev->next = NULL;
	}
	else
		*head_src = NULL;
	first_dst->next = first_src;
	first_src->prev = first_dst;
	*head_dst = first_src;
}

void	ft_push_stack(t_node **head_dst, t_node **head_src)
{
	t_node	*first_dst;
	t_node	*first_src;

	first_dst = *head_dst;
	first_src = *head_src;
	if (!first_src)
	{
		*head_src = NULL;
		return ;
	}
	if (first_dst == NULL)
	{
		if (first_src->prev != NULL)
		{
			*head_src = first_src->prev;
			first_src->prev->next = NULL;
		}
		first_src->prev = NULL;
		*head_dst = first_src;
	}
	else
		ft_pushcont_(&*head_dst, &*head_src);
}

void	ft_pb(t_stack *stack)
{
	ft_push_stack(&stack->head_b, &stack->head_a);
	ft_pointnode_dd(stack);
	ft_printf("pb\n");
}

void	ft_pa(t_stack *stack)
{
	ft_push_stack(&stack->head_a, &stack->head_b);
	ft_pointnode_dd(stack);
	ft_printf("pa\n");
}
