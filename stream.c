#include "philo.h"

void	create_stream(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while(i < data->num_philo)
	{
		pthread_create(&philo->t, NULL, philo_life, philo, data);
		i++;
		philo = philo->next;
	}
	usleep(data->time_die);
	pthread_create(&data->th, NULL, check_die, philo, data);
}

void	philo_life(t_philo *philo)
{
	while (1)
	{
		
	}
}

int	check_die(t_philo *philo)
{
	t_philo	*lst;

	lst = philo;
	while (lst)
	{
		if (lst->eat_status != 0)
			return (-1);
		lst = lst->next;
	}
	return (0);
}