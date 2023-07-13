
#include "libpushswap.h"

int		ft_checkerror(int argc, char **argv)
{
	int i;

	if (argc == 2)
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

int		ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_isdup(int argc, char **argv)
{
	int i;
	int j;
	int num;

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
