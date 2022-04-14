#include "philo.h"

void	create_stream(t_data *data, t_philo *philo)
{
	
	int	i;

	i = 0;
	while(i < data->num_philo)
	{
		pthread_create(&philo->t, NULL, philo_life, philo);
		i++;
		philo = philo->next;
	}
}

void	philo_life(t_philo *philo)
{
	while (1)
	{
		
	}
}