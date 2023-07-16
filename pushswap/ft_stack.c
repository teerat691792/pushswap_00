
#include "libpushswap.h"

int	ft_checkerror(int argc, char **argv)
{
	int	i;

	if (argc <= 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]))
			return (1);
		i++;
	}
	if (ft_isdup(argc, argv) != 0)
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdup(int argc, char **argv)
{
	int	i;
	int	j;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			if (num == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_stackinit(t_stack *stack)
{
	stack->head_a = NULL;
	stack->head_b = NULL;
	stack->snd_a = NULL;
	stack->snd_b = NULL;
	stack->tail_a = NULL;
	stack->tail_b = NULL;
	stack->len = 0;
	stack->limit = 0;
	stack->range = 0;
	stack->half = 0;
	stack->count = 0;
}

void	ft_startpushswap(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_nodeaddfront_dd(&stack->head_a, num);
		i++;
	}
	ft_pointnode_dd(stack);
	ft_noderead_dd(stack);
	if (ft_nodechecksort(&stack->tail_a) == 1)
	{
		if (argc - 1 == 2)
			ft_sort2_dd(stack);
		else if (argc - 1 < 50)
			ft_sortmore_dd(stack, argc - 1);
		else
			ft_bubblesort_dd(stack);
	}
}
