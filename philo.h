#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data
{
	pthread_t	th;
	long long	time;
	long long	time_eat;
	long long	time_sleep;
	long long	time_die;
	int			num_philo;
	int			num_fork;
	int			num_repeat;
	int			all_eat_status;
	int			die_status;
}t_data;

typedef struct s_philo
{
	pthread_t		*t;
	int				id;
	int				eat_status;
	int				die_status;
	// int				sleep_status;
	t_data			*data;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_mutex_t	*forks_r;
}t_philo;

/*############# func ##############*/

int		check(int ac, char **av, t_data *data, t_philo *philo);
int		philo_atoi(t_philo *philo, char *str, unsigned int n, int s);
int		check_int(t_philo *philo, char *str);
int		ft_isdigit(int c);
int		free_ph(t_philo *philo);
int		error(char *str, t_philo *philo);
void	philo_init(t_philo *philo, t_data *data);
void	list_add_back(t_philo *philo, t_philo *lst_new);
t_philo	*list_new(t_data *data, t_philo *philo, int i);
int		forks_init(t_philo *philo);
void	create_stream(t_data *data, t_philo *philo);
void	time_add(t_data *data);
void	*philo_life(void *lst);

void	*check_die(void *list);
void	*die(t_philo *lst, t_philo *philo);
void	destr_forks(t_philo *philo);

/*############# deb ##############*/
void	print(t_philo *list);

#endif
