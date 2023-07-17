
#include "libphilo.h"

int i = 0;


void    *ft_compute(void *val)
{

    printf("compute\n");
    val += 1;
    printf("philo value = %d\n",i);
    return (NULL);
}

void    *ft_testshow(void)
{
    i = 1;
    usleep(1000000); 
    printf("philo value = %d\n",i);
    return (NULL);
}

void    *ft_testshow2(void)
{
    usleep(2000000); 
    printf("philo value = %d\n",i);
    return (NULL);
}

int main(void)
{
    pthread_t t1;
    int val = 0;
    // pthread_t t2;

    pthread_create(&t1, NULL, ft_compute, (void *) &val);

    printf("philo hello\n");
    // pthread_create(&t2, NULL, ft_testshow2(), NULL);
    pthread_join(t1, NULL);
    // pthread_join(t2, NULL);

    return (EXIT_SUCCESS);
}
