#include "philo.h"

void	philo_init(t_philo *philo, t_data *data)
{
	t_philo	*lst;
	int	i;

	i = 1;
	lst = philo;
	while (i <= data->num_philo)
	{
		list_add_back(philo, list_new(data, philo, i));
		i++;
	}
	while (lst)
		lst = lst->next;
	philo->prev = lst;
	lst->next = philo;
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

	lst_new = philo;
	lst_new->eat_status = -data->num_repeat;
	lst_new->id = i;
	lst_new->next = NULL;
	lst_new->prev = NULL;
	// lst_new->sleep_status = -1;
	// lst_new->die_status = 0;
	lst_new->data = data;
	return (lst_new);
}

int	forks_init(t_data *data, t_philo *philo)
{
	t_philo	*lst;

	lst = philo;
	while (lst)
	{
		if (pthread_mutex_init(&lst->forks_r, NULL) != 0)
			return (error("", data, philo));
		lst = lst->next;
	}
	return (0);
}