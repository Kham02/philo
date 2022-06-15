/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:05:59 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 22:06:02 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../hdrs/philo.h"

static void	philo_eats(t_list *tmp)
{
	pthread_mutex_lock(&tmp->next->fork);
	write_action(tmp->all, tmp->philo_num, 'f');
	pthread_mutex_lock(&tmp->fork);
	write_action(tmp->all, tmp->philo_num, 'f');
	write_action(tmp->all, tmp->philo_num, 'e');
	tmp->last_meal = get_time_passed(tmp->all);
	smart_sleep(tmp->all, tmp->all->t2eat);
	pthread_mutex_unlock(&tmp->fork);
	pthread_mutex_unlock(&tmp->next->fork);
}

void	*philo_life(void *philo)
{
	t_list			*tmp;

	tmp = (t_list *)philo;
	if (!(tmp->philo_num % 2))
		usleep(100);
	while (!tmp->all->die_status)
	{
		philo_eats(tmp);
		tmp->eat_num += 1;
		if ((long long)tmp->eat_num == tmp->all->num_eat)
			return (NULL);
		write_action(tmp->all, tmp->philo_num, 's');
		smart_sleep(tmp->all, tmp->all->t2sleep);
		write_action(tmp->all, tmp->philo_num, 't');
	}
	return (NULL);
}
