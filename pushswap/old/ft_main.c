
#include "libpushswap.h"

int	main(int argc, char **argv)
{
	int num;
	int i;
	t_stack		*s;

	if (argc < 2)
	{
		ft_printf("Error: no arguments\n");
		return (1);
	}
	s = malloc(sizeof(t_stack));
	s->root_a = NULL;
	s->root_b = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_nodeaddfront(&s->root_a, num);
		i++;
	}
	ft_noderead(s);
	// ft_showindex(s);
	// ft_printf("argc - 1: %d\n", argc- 1);
	if (argc - 1 == 2)
		ft_sort2(s);
	// else if (argc - 1 == 3)
		// ft_sort3_a(s, argc - 1);
	// else if (argc - 1 == 4)
		// ft_sort4_a(s, argc - 1);
	// else if (argc - 1 == 5)
		// ft_sort5_a(s, argc - 1);
	else
		ft_sortmore(s, argc - 1);
	// ft_showindex(s);
	// ft_nodechecksort(&s->root_a);

	ft_nodeclear(&s->root_a);
	ft_nodeclear(&s->root_b);
	free(s);
	return (0);
}

/*

int	main(void)
{
	int num[10] = {0, 20, 30, 10, 40, 50, 70, 60, 80 ,90};
	int i = 0;
	int len = 3;
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
	ft_noderead(s);
	ft_showindex(s);

	ft_sort3_a(s);
	ft_showindex(s);
	ft_nodechecksort(&s->root_a);

	ft_nodeclear(&s->root_a);
	ft_nodeclear(&s->root_b);
//	ft_printf("linked list count = %d \n",ft_nodecount_rcs(s->root_a));
//	ft_printf("linked list count = %d \n",ft_nodecount_itr(&s->root_a));
	// ft_nodeclear_rcs(s->root);
	// s->root = NULL;
	free(s);

	return (0);
}

*/
