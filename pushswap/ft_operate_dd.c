
#include "libpushswap.h"

void	ft_swapsecondtop(t_node **head, t_node **snd)
{
	t_node	*tmp;
	t_node	*first;
	t_node	*sec;

	if (ft_nodecount_dd(*snd) < 2)
		return ;
	first = *head;
	sec = *snd;
	tmp = sec->prev;
	first->prev = tmp;
	sec->prev = first;
	tmp->next = first;
	first->next = sec;
	sec->next = NULL;
	*head = sec;
	*snd = first;
}

//swap last 2 nodes of stack_a |OR| do nothing if there is only one or NO
void	ft_sa(t_stack *stack)
{
	ft_swapsecondtop(&stack->head_a, &stack->snd_a);
	ft_pointnode_dd(stack);
	ft_printf("sa\n");
}

//swap last 2 nodes of stack_b |OR| do nothing if there is only one or NO
void	ft_sb(t_stack *stack)
{
	ft_swapsecondtop(&stack->head_b, &stack->snd_b);
	ft_pointnode_dd(stack);
	ft_printf("sb\n");
}

// do sa && sb ==> ss
void	ft_ss(t_stack *stack)
{
	ft_swapsecondtop(&stack->head_a, &stack->snd_a);
	ft_pointnode_dd(stack);
	ft_swapsecondtop(&stack->head_b, &stack->snd_b);
	ft_pointnode_dd(stack);
	ft_printf("ss\n");
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

//take last node of stack_b to first node of stack_b
void	ft_rb(t_stack *stack)
{
	ft_shiftup(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rb\n");
}

//take last node of stack_a to first node of stack_a
void	ft_ra(t_stack *stack)
{
	ft_shiftup(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_printf("ra\n");
}

// ra & rb ==> rr
void	ft_rr(t_stack *stack)
{
	ft_shiftup(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_shiftup(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rr\n");
}

void	ft_shiftdown(t_node **head, t_node **tail)
{
	t_node	*last;
	t_node	*first;

	first = *head;
	last = *tail;
	first->next = last;
	if (last->next != NULL)
	{
		*tail = last->next;
		last->next->prev = NULL;
	}
	last->prev = first;
	last->next = NULL;
	*head = last;
}

//take first node of stack_a to last node of stack_a
void	ft_rra(t_stack *stack)
{
	ft_shiftdown(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_printf("rra\n");
}

//take first node of stack_b to last node of stack_b
void ft_rrb(t_stack *stack)
{
	ft_shiftdown(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rrb\n");
}

///do rra & rrb ==> rrr
void	ft_rrr(t_stack *stack)
{
	ft_shiftdown(&stack->head_a, &stack->tail_a);
	ft_pointnode_dd(stack);
	ft_shiftdown(&stack->head_b, &stack->tail_b);
	ft_pointnode_dd(stack);
	ft_printf("rrr\n");
}

void	ft_push_b(t_node **head_dst, t_node **head_src)
{
	t_node	*first_dst;
	t_node	*first_src;

	if (!*head_src)
		return ;
	first_dst = *head_dst;
	first_src = *head_src;
	if (first_dst == NULL)
	{
		*head_src = first_src->prev;
		first_src->prev->next = NULL;
		first_src->prev = NULL;
		*head_dst = first_src;
	}
	else
	{
		if (first_src->prev != NULL)
		{
			*head_src = first_src->prev;
			first_src->prev->next = NULL;
		}
		first_dst->next = first_src;
		first_src->prev = first_dst;
		*head_dst = first_src;
	}
}

//take last node of stack_a to last node of stack_b |OR| do nothing if stack_a is empty, pb
void	ft_pb(t_stack *stack)
{
	ft_push_b(&stack->head_b, &stack->head_a);
	ft_pointnode_dd(stack);
	ft_printf("pb\n");
}

void	ft_pa(t_stack *stack)
{
	ft_push_b(&stack->head_a, &stack->head_b );
	ft_pointnode_dd(stack);
	ft_printf("pa\n");
}
