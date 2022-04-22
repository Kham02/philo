/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:20:19 by estrong           #+#    #+#             */
/*   Updated: 2022/04/22 19:14:59 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		pthread_create(&lst->t, NULL, (void *)philo_life, lst);
		write (1, "st\n", 3);
		pthread_detach(lst->t);
		i++;
		lst = lst->next;
	}
	i = 0;
	pthread_create(&data->th, NULL, (void *)check_die, philo);
	pthread_detach(data->th);
}

void	time_add(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	data->time = time.tv_sec * 1000 + time.tv_usec / 1000;
}

void	philo_life(t_philo *philo)
{
	printf("philo->id: %d\n", philo->id);
	write (1, "lf\n", 3);
	if ((philo->id % 2) != 0)
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
		if (philo->die_status == 0)
			break;
	}
}

int	check_die(t_philo *philo)
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
			{
				lst->die_status = 0;
				return (die(lst, philo));
			}
			lst = lst->next;
		}
		i++;
	}
	return (0);
}