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
	int				die_status;
	int				sleep_status;
	t_data			*data;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_mutex_t	*forks_r;
}t_philo;

typedef struct s_data
{
	pthread_t		th;
	size_t	time_eat;
	size_t	time_sleep;
	size_t	time_die;
	int		num_philo;
	int		num_fork;
	int		num_repeat;
	int		all_eat_status;
}t_data;


/*############# func ##############*/

int		check(int ac, char **av, t_data *data, t_philo *philo);
int		philo_atoi(t_data *data, char *str, unsigned int n, int s);
void	check_int(t_data *data, char *str);
int		ft_isdigit(int c);
int		free_ph(t_philo *philo, t_data *data);
void	error(char *str, t_data *data, t_philo *philo);
void	*philo_init(t_philo *philo, t_data *data);
void	list_add_back(t_philo *philo, t_philo *lst_new);
t_philo	*list_new(t_data *data, t_philo *philo, int i);


#endif
