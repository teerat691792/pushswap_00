
#include "libphilo.h"

// ft_sleeping
// ft_eating
void	*ft_eating(t_philo *philo);
void	*ft_takeforks(t_philo *philo);
// ft_thinking
// ft_dead
// ft_full
// ft_takeforks

// if n = 1  ==> take fork and die
// die_time <  +/- 10ms
//  max_n = 200 , eat_min = 60ms, sleep_min = 60ms, die_time = 60ms

long int	ft_calelapsed(struct timeval start)
{
	long int		duration;
	struct timeval	curr;
	long int		second;
	long int		u_sec;

	gettimeofday(&curr, NULL);
	second = (curr.tv_sec - start.tv_sec) * 1000;
	u_sec = (curr.tv_usec - start.tv_usec) / 1000;
	duration = second + u_sec;
	return (duration);
}

long int	ft_calduration(struct timeval laststamp)
{
	long int		elapsed;
	struct timeval	curr;
	long int		second;
	long int		u_sec;

	gettimeofday(&curr, NULL);
	second = (curr.tv_sec - laststamp.tv_sec) * 1000;
	u_sec = (curr.tv_usec - laststamp.tv_usec) / 1000;
	elapsed = second + u_sec;
	return (elapsed);
}

void	*ft_thinking(t_philo *philo)
{
	long int		elapsed;
	long int		duration;

	elapsed = ft_calelapsed(philo->rule.start_time);
	printf("%ld ms philo [%d] is thinking\n", elapsed, philo->curr_id);

	while (1)
	{
		// printf ("curr_fork[%d] = %d, next_fork = %d\n", philo->curr_id,philo->curr_fork, *philo->next_fork);
		if (philo->eat_count == philo->rule.min_eat)
		{
			philo->is_full = 1;
			elapsed = ft_calelapsed(philo->rule.start_time);
			printf("%ld ms philo [%d] is full\n", elapsed, philo->curr_id);
			break ;
		}
		duration = ft_calduration(philo->lasteat_time);
		philo->fasting_time = duration;
		if (philo->fasting_time >= philo->rule.time_to_die)
		{
			philo->is_dead = 1;
			elapsed = ft_calelapsed(philo->rule.start_time);
			printf("%ld ms philo [%d] is dead\n", elapsed, philo->curr_id);
			break ;
			// ft_detach_all
		}
		else if (philo->curr_fork == 0 && *philo->next_fork == 0)
		{
			pthread_mutex_lock(&philo[philo->curr_id].forks_mutex);
			usleep(1000);
			pthread_mutex_lock(&philo[philo->next_id].forks_mutex);
			philo->curr_fork = 1;
			*philo->next_fork = 1;
			ft_takeforks(philo);
		}
		usleep(10000);
	}

	return (NULL);
}

void	*ft_takeforks(t_philo *philo)
{
	long int		elapsed;

	elapsed = ft_calelapsed(philo->rule.start_time);
	printf("%ld ms philo [%d] has taken a fork\n", elapsed, philo->curr_id);
	ft_eating(philo);
		// if (philo[philo->curr_id].curr_fork == 0 && *philo[philo->curr_id].next_fork == 0)
		// {
		// 	pthread_mutex_lock(&philo[philo->curr_id].forks_mutex);
		// 	pthread_mutex_lock(&philo[philo->next_id].forks_mutex);
		// 	philo->curr_fork = 1;
		// 	*philo->next_fork = 1;
		// ft_eating(philo);
		// pthread_mutex_lock(&philo[philo->curr_id].forks_mutex);
		// pthread_mutex_lock(&philo[philo->next_id].forks_mutex);
		// philo->curr_fork = 0;
		// *philo->next_fork = 0;
	// }
	// else
	// 	go_think...
	return (NULL);
}

void	*ft_sleep(t_philo *philo)
{
	long int	elapsed;

	usleep(philo->rule.time_to_sleep * 1000);
	elapsed = ft_calelapsed(philo->rule.start_time);
	printf("%ld ms philo [%d] is sleeping\n", elapsed, philo->curr_id);
	ft_thinking(philo);
	return (NULL);
}

void	*ft_eating(t_philo *philo)
{
	long int elapsed;
	long int	duration;
	struct timeval curr;

	usleep(philo->rule.time_to_eat * 1000);
	gettimeofday(&curr, NULL);
	elapsed = ft_calelapsed(philo->rule.start_time);
	duration = ft_calduration(philo->lasteat_time);
	philo->lasteat_time = curr;
	philo->eat_count++;

	pthread_mutex_unlock(&philo[philo->curr_id].forks_mutex);
	pthread_mutex_unlock(&philo[philo->next_id].forks_mutex);
	philo->curr_fork = 0;
	*philo->next_fork = 0;

	printf("%ld ms philo [%d] is eating \t{dur = %ld} count = %d \n", elapsed, philo->curr_id, duration, philo->eat_count);
	ft_sleep(philo);
	return (NULL);
}


void	ft_initphilo(t_rule main)
{
	t_philo		*philo;
	int			i;
	int			count;

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
		if (i + 1 != count)
			philo[i].next_fork = &philo[i + 1].curr_fork;
		else if (i + 1 == count)
			philo[i].next_fork = &philo[0].curr_fork;
		// printf("val philo[%d].my_fork = %d\n", i, philo[i].curr_fork);
		// printf("ads philo[%d].my_fork = %p\n", i, &philo[i].curr_fork);
		// printf("val philo[%d].other_fork = %d\n", i, *philo[i].next_fork);
		// printf("ads philo[%d].other_fork = %p\n", i, philo[i].next_fork);
		// printf("\n");
		i++;
	}
	i = 0;
	while (i < count / 2)
	{
		pthread_create(&philo[i].thread, NULL, (void *)ft_thinking, &philo[i]);
		pthread_create(&philo[i + 2].thread, NULL, (void *)ft_thinking, &philo[i + 2]);
		usleep(10000);
		i++;
	}
	i = 0;
	while (1)
	{
		// if (philo[i].is_dead == 1)
		// {
		// 	printf("philo [%d] is dead\n", i);
		// 	//dtach all
		// 	break ;
		// }
		if ( pthread_join(philo[i].thread, NULL) == 0)
		{
			printf("				thread [%d] joined\n", i);
			count--;
			if (count == 0)
				break ;
		}
		if (i + 1 == main.philo_num)
			i = 0;
		else
			i++;
		usleep(100);
	}
	free(philo);


}

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

		ft_initphilo(main);
	}
	printf("end\n");
	return (0);
}
