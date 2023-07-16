
#include "libpushswap.h"

void	ft_sa(t_stack *stack)
{
	ft_swapsecondtop(&stack->head_a, &stack->snd_a);
	ft_pointnode_dd(stack);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *stack)
{
	ft_swapsecondtop(&stack->head_b, &stack->snd_b);
	ft_pointnode_dd(stack);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *stack)
{
	ft_swapsecondtop(&stack->head_a, &stack->snd_a);
	ft_pointnode_dd(stack);
	ft_swapsecondtop(&stack->head_b, &stack->snd_b);
	ft_pointnode_dd(stack);
	ft_printf("ss\n");
}

void	ft_swapsecondtop(t_node **head, t_node **snd)
{
	t_node	*first;
	t_node	*sec;
	t_node	*tmp;

	if (ft_nodecount_dd(*snd) < 2)
		return ;
	first = *head;
	sec = *snd;
	if (sec->prev != NULL)
	{
		tmp = sec->prev;
		tmp->next = first;
		first->prev = tmp;
	}
	first->next = sec;
	sec->next = NULL;
	sec->prev = first;
	*head = sec;
	*snd = first;
}
