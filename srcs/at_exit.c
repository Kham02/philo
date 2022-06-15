/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:23 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 22:06:25 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../hdrs/philo.h"

static int	check_all_eat_count(t_all *all, t_list *philo)
{
	unsigned long	i;
	unsigned long	fed;
	t_list			*tmp;

	tmp = philo;
	i = -1;
	fed = 0;
	while (++i < all->philos_count)
	{
		if (tmp->eat_num == (unsigned long )all->num_eat)
			fed++;
		if (fed == all->philos_count)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	loop_at_exit(t_all *all, t_list *philo)
{
	t_list			*lst_start;
	unsigned long	cur_time;

	lst_start = philo;
	while (philo)
	{
		cur_time = get_time_passed(philo->all);
		if (cur_time >= philo->last_meal + philo->all->t2die
			&& philo->eat_num < (unsigned long )all->num_eat)
		{
			philo->all->die_status = 1;
			write_action(all, philo->philo_num, 'd');
			pthread_mutex_lock(&all->stdout_stat);
			return ;
		}
		if (check_all_eat_count(all, lst_start))
			return ;
		philo = philo->next;
	}
}

int	destroy_mutexes_at_exit(t_all **all, t_list **philo)
{
	unsigned long	i;

	i = -1;
	while (++i < (*all)->philos_count)
	{
		pthread_mutex_unlock(&(*philo)->fork);
		if (pthread_mutex_destroy(&(*philo)->fork))
		{
			pthread_mutex_unlock(&(*philo)->fork);
			if (pthread_mutex_destroy(&(*philo)->fork))
				return (error_write("Error: mutex: destroy fork\n"));
		}
		*philo = (*philo)->next;
	}
	pthread_mutex_unlock(&(*all)->stdout_stat);
	if (pthread_mutex_destroy(&(*all)->stdout_stat))
		return (error_write("Error: mutex: destroy stdout\n"));
	return (0);
}
