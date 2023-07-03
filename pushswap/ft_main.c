
#include "libpushswap.h"


int	main(void)
{
	int num[10] = {-10, 90, 80, 30, 40, 10, 70, 60, 50 ,20};
	int i = 0;
	int len = 10;
	t_stack		*s;

	s = malloc(sizeof(t_stack));
	s->root_a = NULL;
	s->root_b = NULL;
	while (i < len)
	{
		ft_nodeaddback(&s->root_a, num[i]);
		i++;
	}
//	ft_showstack(s);
//	ft_nodeaddfront(&s->root_a, 50);
//	ft_nodeaddfront(&s->root, 5020);
//	ft_nodeaddback_v(&s->root,888);
	ft_showindex(s);
	ft_noderead(s);
	ft_showindex(s);

	ft_nodeclear(&s->root_a);
	ft_nodeclear(&s->root_b);
//	ft_printf("linked list count = %d \n",ft_nodecount_rcs(s->root_a));
//	ft_printf("linked list count = %d \n",ft_nodecount_itr(&s->root_a));
	// ft_nodeclear_rcs(s->root);
	// s->root = NULL;
	free(s);

	return (0);
}
