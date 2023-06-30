
#include "libpushswap.h"


int	main(void)
{
	int num[10] = {1, 2, 3, 4, 5, 6, 7 ,8 ,9};
	int i = 0;
	int len = 9;
	t_stack		*s;

	s = malloc(sizeof(t_stack));
	s->root_a = NULL;
	s->root_b = NULL;
	while (i < len)
	{
		ft_nodeaddback(&s->root_a,ft_nodenew(num[i]));
		i++;
	}
	ft_showstack(s);
//	ft_nodeaddfront(&s->root, 50);
//	ft_nodeaddfront(&s->root, 5020);
//	ft_nodeaddback_v(&s->root,888);

	ft_ra(&s->root_a);
	ft_showstack(s);

	ft_nodeclear(s->root_a);
	// ft_nodeclear_rcs(s->root);
	// s->root = NULL;
	ft_showstack(s);
	free(s);

	return (0);
}
