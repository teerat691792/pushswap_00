
#include "libpushswap.h"

t_node	*ft_nodenew(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	ft_nodeaddback(void **root, int value)
{
	t_node	*curr;
	t_node	*node;

	node = ft_nodenew(value);
	if (*root == NULL)
	{
		*root = node;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = node;
}

void	ft_nodeclear(void **root)
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

void	ft_nodeclear_rcs(t_node *node)
{
	if (node->next != NULL)
	{
		ft_nodeclear_rcs(node->next);
		free(node);
	}
	else
		free(node);
}

void	ft_nodeaddfront(void **root, int value)
{
	t_node	*new;

	new = ft_nodenew(value);
	if (!new)
		return ;
	new->next = *root;
	*root = new;
}

void	ft_nodeaddback_v(void **root,int value)
{
	t_node	*curr;
	t_node	*new;

	new = ft_nodenew(value);
	if (!new)
		return ;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

/*
void	ft_nodeaddafter_i(void **root, int value , int index)
{
	t_node	*new;
	t_node	*curr;
	int		i;

	new = ft_nodenew(value);
	if (!new)
		return ;
	i = 0;
	curr = *root;
	while (i < index)
		curr = curr->next;
	new->next = curr->next;
	curr->next = new;
}
*/

int	ft_checkloopexist(void **root)
{
	t_node	*slow;
	t_node	*fast;

	slow = *root;
	fast = *root;
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			ft_printf("loop FOUND!!!!\n");
			return (1);
		}
	}
	return (0);
}

int	ft_nodecount_itr(void **root)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = *root;
	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}

int	ft_nodecount_rcs(t_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + ft_nodecount_rcs(node->next));
}
