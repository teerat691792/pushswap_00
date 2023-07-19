
#include "libphilo.h"

// ft_sleeping
// ft_eating
// ft_thinking
// ft_dead
// ft_full
// ft_takeforks

/*

// colours

int	main(int argc, char **argv)
{
	int			philo_num;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	int			min_eat;

	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	else
	{
		philo_num = atoi(argv[1]);
		die_time = atoi(argv[2]);
		eat_time = atoi(argv[3]);
		sleep_time = atoi(argv[4]);
		if (argv[5])
		{
			min_eat = atoi(argv[5]);
			printf(GREEN"min_eat = %d\n"RESET, min_eat);
		}
		printf(CYAN"philo_num = %d\n"RESET, philo_num);
		printf(ORANGE"die_time = %d\n"RESET, die_time);
		printf(YELLOW"eat_time = %d\n"RESET, eat_time);
		printf(PINK"sleep_time = %d\n"RESET, sleep_time);
	}
	return (0);
}


*/

/*

// time

int main(void)
{
	struct timeval curr;
	struct timeval start;
	int i;
	int j;
	int	len;
	long int elapsed;

	len = 100000;
	i = 0;
	gettimeofday(&start, NULL);
	printf(" start =	%ld s \n", start.tv_sec);
	printf(" start = 	%ld us \n", start.tv_usec);
	printf("\n");
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			j++;
		}

		i++;
	}
	gettimeofday(&curr, NULL);
	printf(" curr =		%ld s \n", curr.tv_sec);
	printf(" curr =		%ld us \n", curr.tv_usec);
	elapsed = (curr.tv_sec - start.tv_sec) * 1000000 + curr.tv_usec - start.tv_usec;
	printf(" elapsed =	%ld ms \n", elapsed);
	return (0);
}

*/
