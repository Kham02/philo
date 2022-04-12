#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_t		t;
	int				id;
	int				eat_status;
	int				think_status;
	int				sleep_status;
	t_data			*data;
	struct s_philo	*next;
	struct s_philo	*prev;
}t_philo;

typedef struct s_data
{
	size_t	time_eat;
	size_t	time_sleep;
	size_t	time_die;
	int		num_philo;
	int		num_fork;
	int		num_repeat;
}t_data;

typedef struct s_forks
{
	int	left;
	int	right;
}t_forks;


/*########### func ##############*/

void	check(int ac, char **av, t_data *data, t_philo *philo);
int		philo_atoi(t_data *data, char *str, unsigned int n, int s);
void	check_int(t_data *data, char *str);
int		ft_isdigit(int c);


#endif
