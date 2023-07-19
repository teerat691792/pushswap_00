
#ifndef LIBPHILO_H
# define LIBPHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <limits.h>
# include <pthread.h>
# include <error.h>
# include <semaphore.h>

# define RED	"\033[0;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[0;34m"
# define CYAN	"\033[0;36m"
# define YELLOW	"\033[0;33m"
# define PURPLE	"\033[0;35m"
# define WHITE	"\033[0;37m"
# define PINK	"\033[38;5;206m"
# define ORANGE	"\033[38;5;208m"
# define GREY	"\033[38;5;246m"
# define BLACK	"\033[0;30m"
# define MAGENTA	"\033[0;35m"
# define BOLD	"\033[1m"
# define RESET	"\033[0m"

typedef struct s_rule
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat;
	struct timeval		start_time;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*full_mutex;
}	t_rule;

typedef struct s_philo
{
	pthread_t		thread;
	int				curr_id;
	int				next_id;
	int				curr_fork;
	int				*next_fork;
	int				eat_count;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				is_dead;
	int				is_full;
	int				fasting_time;
	t_rule			rule;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				start_time;
	struct	timeval		lasteat_time;
	int				*forks;
	pthread_mutex_t	forks_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*full_mutex;
}	t_philo;



//ft_philo.c
void    ft_test(void);


#endif
