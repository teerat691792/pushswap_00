
#include "libphilo.h"

int mail = 0;
pthread_mutex_t mutex;

void    *ft_routine()
{
    int j = 0;
    int k;

    k = 1000000;
    while (j < k)
    {
		pthread_mutex_lock(&mutex);
        mail++;
        j++;
		pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

void    *ft_compute(void *val)
{

    printf("compute\n");
    val += 10;
    return (NULL);
}

int main(void)
{
	pthread_t	*th;
	int			count;
	int			i;

	i = 16;
	count = i;
	pthread_mutex_init(&mutex, NULL);
	th = malloc(sizeof(pthread_t) * count);
	while (count > 0)
	{
		count--;
		printf("thread [%d] start...\n", count);
		pthread_create(&th[count], NULL, &ft_routine, NULL);
	}
	count = i;
	while (count > 0)
	{
		count--;
		pthread_join(th[count], NULL);
		printf("finished thread [%d]\n", count);
	}
	printf("mail = %d\n", mail);
	pthread_mutex_destroy(&mutex);
	free(th);
	return (EXIT_SUCCESS);
}
