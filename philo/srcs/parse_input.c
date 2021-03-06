/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:05:46 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 23:33:45 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	parse_input(int ac, char ***av, t_all **all)
{
	int	i;
	int	status[5];

	if (ac < 5)
		return (error_write("Error: lack of arguments\n"));
	else if (ac > 6)
		return (error_write("Error: arguments: more than needed\n"));
	i = 0;
	(*all)->num_eat = -1;
	(*all)->philos_count = ft_atoi((*av)[++i], &status[0]);
	(*all)->time_die = ft_atoi((*av)[++i], &status[1]);
	(*all)->time_eat = ft_atoi((*av)[++i], &status[2]);
	(*all)->time_sleep = ft_atoi((*av)[++i], &status[3]);
	status[4] = -1;
	if (ac == 6)
		(*all)->num_eat = ft_atoi((*av)[++i], &status[4]);
	if (!status[0] || !status[1] || !status[2] || !status[3] || !status[4] || \
	(*all)->time_die > MAX || (*all)->time_eat > MAX || (*all)->time_sleep > MAX || \
	(*all)->philos_count < 1 || !(*all)->num_eat)
		return (error_write("Error: invalid arguments\n"));
	return (0);
}
