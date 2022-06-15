/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:34:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/06/15 21:17:43 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	philos_and_mutexes_init(t_all **all, t_list **philo)
{
	t_list			*lst_start;
	t_list			*lst_last;
	unsigned long	i;

	(*all)->die_status = 0;
	i = -1;
	while (++i < (*all)->philos_count)
		ft_lstadd_back(&(*philo), ft_lstnew(i + 1, (*all)));
	lst_start = (*philo);
	lst_last = ft_lstlast((*philo));
	lst_last->next = (*philo);
	(*philo)->prev = lst_last;
	(*philo) = lst_start;
	i = -1;
	while (++i < (*all)->philos_count)
	{
		if (pthread_mutex_init(&(*philo)->fork, NULL))
			return (error_write("Error: mutex: init\n"));
		(*philo) = (*philo)->next;
	}
	(*philo) = lst_start;
	if (pthread_mutex_init(&(*all)->stdout_stat, NULL))
		return (error_write("Error: mutex: init\n"));
	return (0);
}

int	threads_init(t_all *all, t_list *philo)
{
	unsigned int	i;

	all->thread = ft_calloc(all->philos_count, sizeof(pthread_t));
	i = 0;
	while (i < all->philos_count)
	{
		if (pthread_create(&all->thread[i], NULL, &philo_life, philo))
			return (error_write("Error: thread: init\n"));
		philo = philo->next;
		if (pthread_detach(all->thread[i]))
			return (error_write("Error: thread: init\n"));
		i++;
	}
	return (0);
}
