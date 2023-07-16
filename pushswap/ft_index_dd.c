
#include "libpushswap.h"

void	ft_noderead_dd(t_stack *stack)
{
	int		len;
	t_merge	*merge;

	merge = malloc(sizeof(t_merge));
	len = ft_nodecount_dd(stack->tail_a);
	merge->arr = malloc(sizeof(int) * len);
	if (!merge->arr)
		return ;
	ft_nodecopy_dd(stack->tail_a, merge->arr);
	merge->lf = 0;
	merge->rg = len - 1;
	ft_startsort_dd(merge, merge->lf, merge->rg);
	ft_putindex_dd(&stack->tail_a, merge->arr);
	free(merge->arr);
	free(merge);
}

int	ft_nodecount_dd(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	ft_nodecopy_dd(t_node *tail, int *arr)
{
	int	i;

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
	int		i;
	t_node	*curr;

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
