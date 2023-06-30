
#include "libpushswap.h"

void ft_print_stack(t_node *stack)
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
		ft_printf("%d ",curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
}

void ft_showstack(t_stack *stack)
{
	ft_printf("*****************************************************************\n");
	ft_printf("stack_a : ");
	ft_print_stack(stack->root_a);
	ft_printf("stack_b : ");
	ft_print_stack(stack->root_b);
	ft_printf("*****************************************************************\n");
	ft_printf("\n");
}
