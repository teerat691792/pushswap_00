
#include "libphilo.h"

// void	ft_initphilo(t_rule main)
void	ft_startphilo(t_rule main)
{
	t_philo		*philo;
	int			i;
	int			count;
	int			release;
	// int			*result = NULL;

	count = main.philo_num;
	printf("sizeof(t_philo) = %ld\n",sizeof(t_philo));
	philo = malloc(sizeof(t_philo) * count);
	i = 0;
	while (i < count)
	{
		philo[i].curr_id = i;
		if (i + 1 == count)
			philo[i].next_id = 0;
		else
			philo[i].next_id = i + 1;
		philo[i].eat_count = 0;
		philo[i].fasting_time = 0;
		philo[i].lasteat_time = main.start_time;
		philo[i].rule.start_time = main.start_time;
		philo[i].rule.time_to_die = main.time_to_die;
		philo[i].rule.time_to_eat = main.time_to_eat;
		philo[i].rule.time_to_sleep = main.time_to_sleep;
		if (main.min_eat == -1)
			philo[i].rule.min_eat = -1;
		else
			philo[i].rule.min_eat = main.min_eat;
		if ( pthread_mutex_init(&philo[i].forks_mutex, NULL) == 0)
			philo[i].curr_fork = 0;
		// if ( pthread_mutex_init(&philo[i].full_mutex, NULL) == 0)
		// 	philo[i].is_full = 0;
		if (i + 1 != count)
			philo[i].next_fork = &philo[i + 1].curr_fork;
		else if (i + 1 == count && count != 1)
			philo[i].next_fork = &philo[0].curr_fork;
		else if (count == 1)
			philo[i].next_fork = NULL;
		philo[i].status = ALIVE;
		// philo[i].is_dead = malloc(sizeof(int));
		// philo[i].is_dead = NULL;
		// printf("val philo[%d].my_fork = %d\n", i, philo[i].curr_fork);
		// printf("ads philo[%d].my_fork = %p\n", i, &philo[i].curr_fork);
		// printf("val philo[%d].other_fork = %d\n", i, *philo[i].next_fork);
		// printf("ads philo[%d].other_fork = %p\n", i, philo[i].next_fork);
		// printf("\n");
		i++;
	}
	// i = 0;
	// while (i < count / 2)
	// {
	// 	pthread_create(&philo[i].thread, NULL, (void *)ft_thinking, &philo[i]);
	// 	pthread_create(&philo[i + 2].thread, NULL, (void *)ft_thinking, &philo[i + 2]);
	// 	usleep(10000);
	// 	i++;
	// }
	// if (count % 2 == 1)
	// 	pthread_create(&philo[count - 1].thread, NULL, (void *)ft_thinking, &philo[count - 1]);
	i = 0;
	release = (main.time_to_eat * (main.philo_num - 0)* 1);
	printf(GREEN"release = %d\n"RESET, release);
	while (i < count)
	{
		pthread_create(&philo[i].thread, NULL, (void *)&ft_thinking, &philo[i]);
		// usleep(main.time_to_eat * 100);
		usleep(release);
		i++;
	}
	i = 0;
	while (count > 0)
	{
		printf("count = %d\t i = %d\n", count, i);
		if (philo[i].is_full == FULL)
		{
			if ( pthread_join(philo[i].thread, NULL) == 0)
			{
			printf(PINK"%ld after full \t", ft_caltime(main.start_time));
			printf("	thread [%d] joined\n"RESET, i);
			philo[i].is_full = ALIVE;
			count--;
			}
		}
		else
		{
			if (i + 1 == main.philo_num)
				i = 0;
			else
				i++;
		}
		usleep(release * 100);
	}
	i = 0;
	while (i < main.philo_num)
	{
		printf("ENTER free\n");
		// printf
		pthread_mutex_destroy(&philo[i].forks_mutex);
		// free(philo[i].is_dead);
		// pthread_mutex_destroy(&philo[i].full_mutex);
		i++;
	}
	free(philo);


}
