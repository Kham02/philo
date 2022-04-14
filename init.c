#include "philo.h"

void	*philo_init(t_philo *philo, t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->num_philo)
	{
		list_add_back(philo, list_new(data, philo, i));
		i++;
	}
}

void	list_add_back(t_philo *philo, t_philo *lst_new)
{
	t_philo	*lst;
	t_philo	*lst1;

	lst = philo;
	lst1 = philo;
	while (lst->next != NULL)
	{
		lst = lst->next;
		lst1 = lst1->next;
	}
	lst->next = lst_new;
	lst = lst->next;
	lst->prev = lst1;
}

t_philo	*list_new(t_data *data, t_philo *philo, int i)
{
	t_philo	*lst_new;

	lst_new->eat_status = 0;
	lst_new->id = i;
	lst_new->next = NULL;
	lst_new->prev = NULL;
	lst_new->sleep_status = 0;
	lst_new->think_status = 0;
	lst_new->data = data;
	return (lst_new);
}

void	*forks_init(t_data *data, t_philo *philo, pthread_mutex_t *forks)
{
	t_philo	*lst;

	lst = philo;
	if (pthread_mutex_init() != 0)
		error("", data, philo);
	while (lst)
	{
		lst->forks_r = pthread_mutex_init();
		lst = lst->next;
	}
}