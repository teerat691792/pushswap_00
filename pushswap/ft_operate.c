
#include "libpushswap.h"

void	ft_swapsecondlast(t_node **root)
{
	t_node	*second_last;
	t_node	*last;
	t_node	*tmp;

	if (ft_nodecount_rcs(*root) < 2)
		return ;
	else if (ft_nodecount_rcs(*root) == 2)  //should call ft_ra instead
	{
		second_last = *root;
		last = second_last->next;
		*root = last;
	}
	else
	{
		tmp = *root;
		while (tmp->next->next->next != NULL)
			tmp = tmp->next;
		second_last = tmp->next;
		last = second_last->next;
		tmp->next = last;
	}
	last->next = second_last;
	second_last->next = NULL;
}
//swap last 2 nodes of stack_a |OR| do nothing if there is only one or NO
void	ft_sa(t_stack *stack)
{
	ft_swapsecondlast(&stack->root_a);
	ft_printf("sa\n");
}

//swap last 2 nodes of stack_b |OR| do nothing if there is only one or NO
void	ft_sb(t_stack *stack)
{
	ft_swapsecondlast(&stack->root_b);
	ft_printf("sb\n");
}

// do sa && sb ==> ss
void	ft_ss(t_stack *stack)
{
	ft_swapsecondlast(&stack->root_a);
	ft_swapsecondlast(&stack->root_b);
	ft_printf("ss\n");
}

void	ft_stepdown(t_node **root)
{
	t_node	*last;
	t_node	*first;

	first = *root;
	last = *root;
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = first;
	*root = last->next;
	last->next = NULL;
}

//take last node of stack_b to first node of stack_b
void	ft_rb(t_stack *stack)
{
	ft_stepdown(&stack->root_b);
	ft_printf("rb\n");
}

//take last node of stack_a to first node of stack_a
void	ft_ra(t_stack *stack)
{
	ft_stepdown(&stack->root_a);
	ft_printf("ra\n");
}

// ra & rb ==> rr
void	ft_rr(t_stack *stack)
{
	ft_stepdown(&stack->root_a);
	ft_stepdown(&stack->root_b);
	ft_printf("rr\n");
}

void	ft_stepup(t_node **root)
{
	t_node	*last;
	t_node	*first;

	first = *root;
	last = *root;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*root = first->next;
	first->next = NULL;
}

//take first node of stack_b to last node of stack_b
void ft_rrb(t_stack *stack)
{
	ft_stepup(&stack->root_b);
	ft_printf("rrb\n");
}

///do rra & rrb ==> rrr
void	ft_rrr(t_stack *stack)
{
	ft_stepup(&stack->root_a);
	ft_stepup(&stack->root_b);
	ft_printf("rrr\n");
}
//take first node of stack_a to last node of stack_a
void	ft_rra(t_stack *stack)
{
	ft_stepup(&stack->root_a);
	ft_printf("rra\n");
}

//take last node of stack_b to last node of stack_a |OR| do nothing if stack_b is empty, pa
void	ft_pa(t_stack *stack)
{
	t_node	*last_a;
	t_node	*last_b;

	if (stack->root_b == NULL)
		return ;
	last_b = stack->root_b;
	last_a = stack->root_a;
	if (last_b->next == NULL)
	{
		stack->root_b = NULL;
		while (last_a->next != NULL)
			last_a = last_a->next;
		last_a->next = last_b;
		ft_printf("pa\n");
		return ;
	}
	while (last_b->next->next != NULL)
		last_b = last_b->next;
	if (last_a == NULL)
		stack->root_a = last_b->next;
	else
	{
		while (last_a->next != NULL)
			last_a = last_a->next;
		last_a->next = last_b->next;
	}
	last_b->next = NULL;
	ft_printf("pa\n");
}
//take last node of stack_a to last node of stack_b |OR| do nothing if stack_a is empty, pb
void	ft_pb(t_stack *stack)
{
	t_node	*last_a;
	t_node	*last_b;

	if (stack->root_a == NULL)
		return ;
	last_a = stack->root_a;
	last_b = stack->root_b;
	if (last_a->next == NULL)
	{
		stack->root_a = NULL;
		while (last_b->next != NULL)
			last_b = last_b->next;
		last_b->next = last_a;
		ft_printf("pb\n");
		return ;
	}
	while (last_a->next->next != NULL)
		last_a = last_a->next;
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
}

