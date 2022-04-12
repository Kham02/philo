#include "philo.h"

void	create_stream(t_data *data, t_philo *philo)
{
	
	int	i;

	i = 0;
	while(i < data->num_philo)
	{
		pthread_create(&philo->t, NULL, ,);
		i++;
	}
	pthread_create(&philo->t, NULL, ,);
}