/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:15 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 23:33:38 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/philo.h"

static void	free_memory(t_all **all, t_list **philo)
{
	free((*all)->thread);
	(*philo)->prev->next = NULL;
	ft_lstclear(philo);
	(*all)->philos_count = 0;
	(*all)->t2die = 0;
	(*all)->t2eat = 0;
	(*all)->t2sleep = 0;
	(*all)->num_eat = 0;
	(*all)->die_status = 0;
	(*all)->i = 0;
	free(*all);
}

int	main(int ac, char **av)
{
	t_all	*all;
	t_list	*philo;

	all = ft_calloc(1, sizeof(t_all));
	if (!all)
		return (error_write("Error: malloc\n"));
	if (parse_input(ac, &av, &all))
		return (-1);
	philo = NULL;
	if (philos_and_mutexes_init(&all, &philo))
		return (-1);
	if (gettimeofday(&all->start_time, NULL))
		return (error_write("Error: gettimeofday\n"));
	if (threads_init(all, philo))
		return (-1);
	loop_at_exit(all, philo);
	if (destroy_mutexes_at_exit(&all, &philo))
		return (-1);
	free_memory(&all, &philo);
	return (0);
}
