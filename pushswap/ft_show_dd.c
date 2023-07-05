
#include "libpushswap.h"

void	ft_printstack_dd(t_node *stack)
{
	t_node	*curr;

	if (!stack)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	curr = stack;
	while (curr != NULL)
	{
		ft_printf(" %d\t",curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	ft_showstack_dd(t_stack *stack)
{
	ft_printf("*****************************************************************\n");
	ft_printf("stack_a : ");
	ft_printstack_dd(stack->tail_a);
	ft_printf("stack_b : ");
	ft_printstack_dd(stack->tail_b);
	ft_printf("*****************************************************************\n");
	ft_printf("\n");
}

void	ft_printindex_dd(t_node *stack)
{
	t_node	*curr;

	if (!stack)
	{
		ft_printf("[NULL]\n");
		return ;
	}
	curr = stack;
	while (curr != NULL)
	{
		ft_printf("[%d]\t",curr->index);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	ft_showindex_dd(t_stack *stack)
{
	ft_printf("*****************************************************************\n");
	ft_printf("stack_a :\t");
	ft_printstack_dd(stack->tail_a);
	ft_printf("index_a :\t");
	ft_printindex_dd(stack->tail_a);
	ft_printf("\n");
	ft_printf("stack_b :\t");
	ft_printstack_dd(stack->tail_b);
	ft_printf("index_b :\t");
	ft_printindex_dd(stack->tail_b);
	ft_printf("*****************************************************************\n");
	ft_printf("\n");
}

