
#include "libphilo.h"

int	main(int argc, char **argv)
{
	t_rule		main;

	printf("sizeof(t_rule) = %ld\n",sizeof(t_rule));
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	else
	{
		main.philo_num = atoi(argv[1]);
		main.time_to_die = atoi(argv[2]);
		main.time_to_eat = atoi(argv[3]);
		main.time_to_sleep = atoi(argv[4]);
		if (argv[5])
		{
			main.min_eat = atoi(argv[5]);
			printf(GREEN"min_eat = %d\n"RESET, main.min_eat);
		}
		else
			main.min_eat = -1;
		gettimeofday(&main.start_time, NULL);
		printf(CYAN"philo_num = %d\n"RESET, main.philo_num);
		printf(ORANGE"die_time = %d\n"RESET, main.time_to_die);
		printf(YELLOW"eat_time = %d\n"RESET, main.time_to_eat);
		printf(PINK"sleep_time = %d\n"RESET, main.time_to_sleep);

		ft_startphilo(main);
	}
	printf("simulate duration = %ld\n", ft_caltime(main.start_time));
	printf("end\n");
	return (0);
}
