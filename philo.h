#ifndef PHILO_H
#define PHILO_H

typedef struct s_philo
{
	pthread_t	t;
	int			id;
}t_philo;

typedef struct s_data
{
	size_t	time_eat;
	size_t	time_sleep;
	size_t	time_die;
	int		num_philo;
}t_data;

typedef struct s_forks
{
	int	left;
	int	right;
}t_forks;

#endif
