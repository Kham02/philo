#include "philo.h"

void	free_ph(t_philo *philo, t_data *data)
{
	if (data)
		free(data);
	
}

void	error(t_data *data, t_philo *philo)
{
	free_ph(philo, data);
	exit();
}

void	end(t_data *data, t_philo *philo)
{
	free_ph(philo, data);
	exit();
}
