
#include "libphilo.h"

long int	ft_caltime(struct timeval timestamp)
{
	long int		elapsed;
	struct timeval	curr;
	long int		second;
	long int		u_sec;

	gettimeofday(&curr, NULL);
	second = (curr.tv_sec - timestamp.tv_sec) * 1000;
	u_sec = (curr.tv_usec - timestamp.tv_usec) / 1000;
	elapsed = second + u_sec;
	return (elapsed);
}

void	*ft_thinking(t_philo *philo)
{
	long int		elapsed;
	long int		duration;

	elapsed = ft_caltime(philo->rule.start_time);
	printf("%ld ms philo [%d] is thinking\n", elapsed, philo->curr_id);
	while (1)
	{
		duration = ft_caltime(philo->lasteat_time);
		philo->fasting_time = duration;
		if (philo->is_full == 1)
		{
			return (NULL);
		}
		else if (philo->status == DEAD)
		{
			return (NULL);
		}
		else if (philo->eat_count == philo->rule.min_eat)
		{
			philo->is_full = 1;
			elapsed = ft_caltime(philo->rule.start_time);
			printf(YELLOW"%ld ms philo [%d] is full\n"RESET, elapsed, philo->curr_id);
			return (NULL);
		}
		else if (philo->fasting_time >= philo->rule.time_to_die || philo->next_fork == NULL)
		{
			philo->status = DEAD;
			philo->is_full = FULL;  //t	mp
			philo->is_dead = &philo->status;
			printf("philo->is_dead = %d @ %p\n", *philo->is_dead,philo->is_dead);

			elapsed = ft_caltime(philo->rule.start_time);
			printf(RED"%ld ms philo [%d] is dead\n"RESET, elapsed, philo->curr_id);
			// printf("%ld %d is dead\n", elapsed, philo->curr_id);
			return (NULL);
			// return (&philo->is_dead);
			// ft_detach_all
		}
		else if (philo->curr_fork == 0 && *philo->next_fork == 0)
		{
			ft_takeforks(philo);
		}
		usleep(100);
	}

	return (NULL);
}

void	*ft_takeforks(t_philo *philo)
{
	long int		elapsed;

	elapsed = ft_caltime(philo->rule.start_time);
	if (philo->status == DEAD)
		return (NULL);
	// printf("%ld %d has taken a fork\n", elapsed, philo->curr_id);
	printf("%ld ms philo [%d] has taken a fork\n", elapsed, philo->curr_id);
	pthread_mutex_lock(&philo[philo->curr_id].forks_mutex);
	usleep(100);
	pthread_mutex_lock(&philo[philo->next_id].forks_mutex);
	philo->curr_fork = 1;
	*philo->next_fork = 1;
	ft_eating(philo);
	return (NULL);
}

void	*ft_eating(t_philo *philo)
{
	long int elapsed;
	long int	duration;
	struct timeval curr;

	gettimeofday(&curr, NULL);
	if (philo->status == DEAD)
		return (NULL);
	elapsed = ft_caltime(philo->rule.start_time);
	duration = ft_caltime(philo->lasteat_time);
	philo->lasteat_time = curr;
	philo->eat_count++;
	printf("%ld ms philo [%d] is eating \t{dur = %ld} count = %d \n", elapsed, philo->curr_id, duration, philo->eat_count);
	usleep(philo->rule.time_to_eat * 1000);
	pthread_mutex_unlock(&philo[philo->curr_id].forks_mutex);
	pthread_mutex_unlock(&philo[philo->next_id].forks_mutex);
	philo->curr_fork = 0;
	*philo->next_fork = 0;
	ft_sleep(philo);
	return (NULL);
}

void	*ft_sleep(t_philo *philo)
{
	long int	elapsed;

	elapsed = ft_caltime(philo->rule.start_time);
	if (philo->status == DEAD)
		return (NULL);
	printf("%ld ms philo [%d] is sleeping\n", elapsed, philo->curr_id);
	usleep(philo->rule.time_to_sleep * 1000);
	ft_thinking(philo);
	return (NULL);
}
