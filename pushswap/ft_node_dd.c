
#include "libpushswap.h"

t_node	*ft_nodenew_dd(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_nodeaddback_dd(t_node **tail, int value)
{
	t_node	*curr;
	t_node	*new;

	new = ft_nodenew_dd(value);
	if (*tail == NULL)
	{
		*tail = new;
		return ;
	}
	curr = *tail;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
}

void	ft_nodeaddfront_dd(t_node **head, int value)
{
	t_node	*curr;
	t_node	*new;

	new = ft_nodenew_dd(value);
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->prev != NULL)
		curr = curr->prev;
	curr->prev = new;
	new->next = curr;
}

void	ft_nodeclear_dd(t_node **root)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *root;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(curr);
	*root = NULL;
}

void	ft_pointnode_dd(t_stack *stack)
{
	t_node	*curr;

	curr = stack->head_a;
	if (curr != NULL)
	{
		stack->snd_a = curr->prev;
		while (curr->prev != NULL)
			curr = curr->prev;
		stack->tail_a = curr;
	}

	curr = stack->head_b;
	if (curr != NULL)
	{
		stack->snd_b = curr->prev;
		while (curr->prev != NULL)
			curr = curr->prev;
		stack->tail_b = curr;
	}
}

void	ft_stackclear_dd(t_stack *stack)
{
	ft_nodeclear_dd(&stack->tail_a);
	ft_nodeclear_dd(&stack->tail_b);
	stack->head_a = NULL;
	stack->head_b = NULL;
	stack->snd_a = NULL;
	stack->snd_b = NULL;
	stack->tail_a = NULL;
	stack->tail_b = NULL;
	stack->root_a = NULL;
	stack->root_b = NULL;
	free(stack);
}
