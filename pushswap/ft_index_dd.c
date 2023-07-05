
#include "libpushswap.h"

void	ft_noderead_dd(t_stack *stack)
{
	int len;
	int *arr;

	len = ft_nodecount_dd(stack->tail_a);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return ;
	ft_nodecopy_dd(stack->tail_a, arr);
	ft_mergesort_dd(arr, len);
	ft_putindex_dd(&stack->tail_a, arr);
	free(arr);
}

int	ft_nodecount_dd(t_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + ft_nodecount_dd(node->next));
}

void	ft_nodecopy_dd(t_node *tail, int *arr)
{
	int i;

	i = 0;
	while (tail != NULL)
	{
		arr[i] = tail->value;
		tail = tail->next;
		i++;
	}
}

void	ft_putindex_dd(t_node **tail, int *arr)
{
	int i;
	t_node *curr;

	curr = *tail;
	while (curr != NULL)
	{
		i = 0;
		while (arr[i] != curr->value)
			i++;
		curr->index = i;
		curr = curr->next;
	}
}
