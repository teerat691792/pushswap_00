
#include "libpushswap.h"

t_node	*ft_nodenew(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_nodeaddback(void **root, t_node *node)
{
	t_node	*curr;

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
	while (curr->next != NULL)
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
