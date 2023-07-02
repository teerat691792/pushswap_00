
#include "libpushswap.h"

//swap last 2 nodes of stack_a |OR| do nothing if there is only one or NO
void	ft_sa(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;
	t_node	*tmp;

	if (ft_nodecount_rcs(stack->root_a) < 2)
		return ;
	else if (ft_nodecount_rcs(stack->root_a) == 2)  //should call ft_ra instead
	{
		second_last = stack->root_a;
		last = second_last->next;
		stack->root_a = last;
	}
	else
	{
		tmp = stack->root_a;
		while (tmp->next->next->next != NULL)
			tmp = tmp->next;
		second_last = tmp->next;
		last = second_last->next;
		tmp->next = last;
	}
	last->next = second_last;
	second_last->next = NULL;
	ft_printf("sa\n");
	ft_showstack(stack);
}
//swap last 2 nodes of stack_b |OR| do nothing if there is only one or NO
// do sa && sb , ss


//take last node of stack_a to first node of stack_a
void	ft_ra(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	first = stack->root_a;
	ft_printf("firsti->value : %d\t",first->value);
	last = stack->root_a;
	while (last->next->next != NULL)
		last = last->next;
	ft_printf("last->value : %d\t\t", last->value);
	ft_printf("move->value : %d\n", last->next->value);

	last->next->next = first;
	stack->root_a = last->next;
	last->next = NULL;
	ft_printf("ra\n");
	ft_showstack(stack);
}
//take last node of stack_b to first node of stack_b
//do ra & rb , rr

//take first node of stack_a to last node of stack_a
void	ft_rra(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	first = stack->root_a;
	last = stack->root_a;
	while (last->next != NULL)
		last = last->next;

	stack->root_a = first->next;
	last->next = first;
	first->next = NULL;
	ft_printf("rra\n");
	ft_showstack(stack);
}
//take first node of stack_b to last node of stack_b
///do rra & rrb , rrr

//take last node of stack_b to last node of stack_a |OR| do nothing if stack_b is empty, pa
//take last node of stack_a to last node of stack_b |OR| do nothing if stack_a is empty, pb
void	ft_pb(t_stack *stack)
{
	t_node	*last_a;
	t_node	*last_b;

	if (stack->root_a == NULL)
		return ;
	last_a = stack->root_a;
	while (last_a->next->next != NULL)
		last_a = last_a->next;
	last_b = stack->root_b;
	if (last_b == NULL)
		stack->root_b = last_a->next;
	else
	{
		while (last_b->next != NULL)
			last_b = last_b->next;
		last_b->next = last_a->next;
	}
	last_a->next = NULL;
	ft_printf("pb\n");
	ft_showstack(stack);
}

