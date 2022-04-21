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
		pthread_create(&lst->t, NULL, (void *)philo_life, philo);
		//detach
		i++;
		lst = lst->next;
	}
	i = 0;
	pthread_create(&data->th, NULL, (void *)check_die, philo);
}

void	time_add(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	data->time = time.tv_sec * 1000 + time.tv_usec / 1000;
}

void	philo_life(t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep(philo->data->time_eat / 2);
	while (philo->data->all_eat_status != 0)
	{
		pthread_mutex_lock(philo->forks_r);
		printf("%d, %s\n", philo->id, ": philosopher took the right fork");
		pthread_mutex_lock(philo->prev->forks_r);
		printf("%d, %s\n", philo->id, ": philosopher took the left fork");
		printf("%d, %s\n", philo->id, ": philosopher eat");
		philo->eat_status++;
		usleep(philo->data->time_eat);
		pthread_mutex_unlock(philo->forks_r);
		pthread_mutex_unlock(philo->prev->forks_r);
		printf("%d, %s\n", philo->id, ": philosopher sleep");
		usleep(philo->data->time_sleep);
		printf("%d, %s\n", philo->id, ": philosopher think");
		// if (philo->eat_status == 0);
		// 	philo->data->all_eat_status++;
	}
}

// void	process(t_data *data, t_philo *philo)
// {
// 	printf("%d, %s\n", philo->id, ": philosopher eat");
// 	philo->eat_status++;
// 	usleep(data->time_eat);
// 	printf("%d, %s\n", philo->id, ": philosopher sleep");
// 	usleep(data->time_sleep);
// 	printf("%d, %s\n", philo->id, ": philosopher think");
// }

// int	check_all_eat(t_philo *philo)
// {
// 	if (philo->eat_status != 0);
// 		return (-1);
// }

void	check_die(t_philo *philo)
{
	t_philo	*lst;
	int		i;

	i = 0;
	lst = philo;
	while (i != philo->data->num_repeat)
	{
		usleep(philo->data->time_die);
		while (lst)
		{
			if (lst->eat_status < 0)
				return (die());
			lst = lst->next;
		}
		i++;
	}
}