#include "libphilo.h"

// pass argument and return

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*ft_routine(void *arg)
{
	int	index;
	int	j;
	int sum;

	j = 0;
	sum = 0;
	index = *(int *)arg;
	while (j < 5)
	{
		sum += primes[index + j];
		j++;
	}
	printf("local sum = %d\n", sum);
	*(int *)arg = sum;
	return arg;
}

int	main(void)
{
	pthread_t	*th;
	int			count;
	int			i;
	int			*arg;
	int			*result;
	int			global;


	count = 2;
	global = 0;
	i = count;
	th = malloc(sizeof(pthread_t) * count);
	while (i > 0)
	{
		i--;
		arg = malloc(sizeof(int));
		*arg = i * 5;
		pthread_create(&th[i], NULL, &ft_routine, arg);
	}
	i = count;
	while (i > 0)
	{
		i--;
		pthread_join(th[i], (void **) &result);
		global += *result;
		free(result);
	}
	printf("global = %d\n", global);
	free(th);
	return (EXIT_SUCCESS);
}



/*

// return value

pthread_mutex_t	mutex;

void	*ft_rolldice()
{
	int		value;
	int		*result;
	pthread_mutex_lock(&mutex);
	result = malloc(sizeof(int));
	value = rand() % 6 + 1;
	// printf("value = %d\n", value);
	*result = value;
	pthread_mutex_unlock(&mutex);
	return (void *) result;
}

int main(void)
{
	srand(time(NULL));
	pthread_t	*th;
	int			count;
	int			j;
	int			*result;

	j = 4;
	count = j;
	pthread_mutex_init(&mutex, NULL);
	th = malloc(sizeof(pthread_t) * count);
	while (count > 0)
	{
		count--;
		printf("thread [%d] start...\n", count);
		pthread_create(&th[count], NULL, &ft_rolldice, NULL);
	}
	count = j;
	while (count > 0)
	{
		count--;
		pthread_join(th[count], (void **) &result);
		printf("thread [%d] result = %d\n", count, *result);
		free(result);
	}
	pthread_mutex_destroy(&mutex);
	free(th);
	return (EXIT_SUCCESS);
}
*/
