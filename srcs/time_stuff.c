/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:04 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 22:06:06 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../hdrs/philo.h"

int	get_time_passed(t_all *all)
{
	struct timeval	cur_time;
	int				res;

	if (gettimeofday(&cur_time, NULL))
		return (error_write("Error: gettime\n"));
	res = ((int )(cur_time.tv_sec - all->start_time.tv_sec)) * 1000;
	res += ((int )cur_time.tv_usec - (int )all->start_time.tv_usec) / 1000;
	return (res);
}

void	smart_sleep(t_all *all, unsigned long t2do)
{
	unsigned long	end_time;

	end_time = get_time_passed(all) + t2do;
	while ((unsigned long )get_time_passed(all) < end_time)
		usleep(50);
}
