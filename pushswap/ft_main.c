
#include "libpushswap.h"

int	main(int argc, char **argv)
{
	int num;
	int i;
	t_stack		*s;

	if (ft_checkerror(argc, argv) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	else
	{
		s = malloc(sizeof(t_stack));
		s->head_a = NULL;
		s->head_b = NULL;
		s->snd_a = NULL;
		s->snd_b = NULL;
		s->tail_a = NULL;
		s->tail_b = NULL;
		i = 1;
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			ft_nodeaddfront_dd(&s->head_a, num);
			i++;
		}
		ft_pointnode_dd(s);
		ft_noderead_dd(s);
		if (argc - 1 == 2)
			ft_sort2(s);
		else if (argc - 1 < 10)
			ft_sortmore(s, argc - 1);
		else
			ft_bubblesort_dd(s);
		ft_stackclear_dd(s);
	}
	return (0);
}
