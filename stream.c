#include "philo.h"

void	create_stream(t_data *data, t_philo *philo)
{
	int		i;
	t_philo	*lst;

	i = 0;
	lst = philo;
	time_add(data);
	while(i < data->num_philo)
	{
		pthread_create(&lst->t, NULL, philo_life, philo, data);
		//detach
		i++;
		lst = lst->next;
	}
	i = 0;
	pthread_create(&data->th, NULL, check_die, philo, data);
}

void	time_add(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	data->time = time.tv_sec * 1000 + time.tv_usec / 1000;
}

void	philo_life(t_data *data, t_philo *philo)
{
	if (lst->id % 2 != 0)
		usleep(data->time_eat / 2);
	while (data->all_eat_status != 0)
	{
		pthread_mutex_lock(philo->forks_r);
		printf("%d, %s\n", philo->id, ": philosopher took the right fork");
		pthread_mutex_lock(philo->prev->forks_r);
		printf("%d, %s\n", philo->id, ": philosopher took the left fork");
		process(data, philo);
		pthread_mutex_unlock(philo->forks_r);
		pthread_mutex_unlock(philo->prev->forks_r);
		if (check_all_eat(data, philo) == 0)
			data->all_eat_status++;
	}
}

void	process(t_data *data, t_philo *philo)
{
	printf("%d, %s\n", philo->id, ": philosopher eat");
	philo->eat_status++;
	usleep(data->time_eat);
	printf("%d, %s\n", philo->id, ": philosopher sleep");
	usleep(data->time_sleep);
	printf("%d, %s\n", philo->id, ": philosopher think");
}

int	check_all_eat(t_data *data, t_philo *philo)
{
	t_philo	*lst;

	lst = philo;
	while (lst)
	{
		if (lst->eat_status != 0);
			return (-1);
		lst = lst->next;
	}
	return (0);
}

void	check_die(t_data *data, t_philo *philo)
{
	t_philo	*lst;
	int		i;

	i = 0;
	lst = philo;
	while (i != data->num_repeat)
	{
		usleep(data->time_die);
		while (lst)
		{
			if (lst->eat_status < 0)
				return (die());
			lst = lst->next;
		}
		i++;
	}
}