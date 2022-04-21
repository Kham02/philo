#include "philo.h"

int	free_ph(t_philo *philo, t_data *data)
{
	t_philo	*lst;
	t_philo	*lst1;

	lst = philo;
	if (data)
	{
		free(data);
		data = NULL;
	}
	while (philo)
	{
		lst1 = lst;
		lst = lst->next;
		free(lst1);
	}
	philo = NULL;
	return (0);
}

int	error(char *str, t_data *data, t_philo *philo)
{
	printf("%s\n", str);
	free_ph(philo, data);
	return (EXIT_FAILURE);
}

void	destr_forks(t_philo *philo)
{
	t_philo	*lst;

	lst = philo;
	while (lst)
	{
		pthread_mutex_destroy(lst->forks_r);
		lst = lst->next;
	}
}