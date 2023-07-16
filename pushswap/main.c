
#include "libpushswap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;

	if (ft_checkerror(argc, argv) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	else
	{
		stack = malloc(sizeof(t_stack));
		if (stack == NULL)
			return (EXIT_FAILURE);
		ft_stackinit(stack);
		ft_startpushswap(stack, argc, argv);
		ft_stackclear_dd(stack);
	}
	return (EXIT_SUCCESS);
}
