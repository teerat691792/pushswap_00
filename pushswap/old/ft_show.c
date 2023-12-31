
#include "libpushswap.h"

void	ft_print_stack(t_node *stack)
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

void	ft_showstack(t_stack *stack)
{
	ft_printf("*****************************************************************\n");
	ft_printf("stack_a : ");
	ft_print_stack(stack->root_a);
	ft_printf("stack_b : ");
	ft_print_stack(stack->root_b);
	ft_printf("*****************************************************************\n");
	ft_printf("\n");
}

void	ft_print_index(t_node *stack)
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
void	ft_showindex(t_stack *stack)
{
	ft_printf("*****************************************************************\n");
	ft_printf("stack_a :\t");
	ft_print_stack(stack->root_a);
	ft_printf("index_a :\t");
	ft_print_index(stack->root_a);
	ft_printf("\n");
	ft_printf("stack_b :\t");
	ft_print_stack(stack->root_b);
	ft_printf("index_b :\t");
	ft_print_index(stack->root_b);
	ft_printf("*****************************************************************\n");
	ft_printf("\n");
}
