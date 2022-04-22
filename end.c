/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:20:29 by estrong           #+#    #+#             */
/*   Updated: 2022/04/22 17:13:35 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_ph(t_philo *philo)
{
	t_philo	*lst;
	t_philo	*lst1;

	lst = philo;
	// if (data)
	// {
	// 	free(data);
	// 	data = NULL;
	// }
	while (philo)
	{
		lst1 = lst;
		lst = lst->next;
		free(lst1);
	}
	philo = NULL;
	return (0);
}

int	die(t_philo *lst, t_philo *philo)
{
	printf("%d %s\n", lst->id, "die");
	destr_forks(philo);
	free_ph(philo);
	return (0);
}

int	error(char *str, t_philo *philo)
{
	printf("%s\n", str);
	free_ph(philo);
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