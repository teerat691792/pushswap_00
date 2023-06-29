
#include "libpushswap.h"

void ft_print_stack(t_node *stack);

int	main(void)
{
	int num[10] = {1, 2, 3, 4, 5, 6, 7 ,8 ,100};
	int i = 0;
	int len = 3;
	void *root;

	root = NULL;
	while (i < len)
	{
		ft_nodeaddback(&root,ft_nodenew(num[i]));
		ft_print_stack(root);
		i++;
	}

	ft_test();

	ft_nodeclear(&root);

	// ft_nodeclear_rcs(root);
	// root = NULL;
	ft_print_stack(root);

	return (0);
}

void ft_print_stack(t_node *stack)
{
	t_node	*curr;

	if (!stack)
	{
		ft_printf("NULL stack\n");
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
