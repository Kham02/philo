#include "../hdrs/philo_bonus.h"

int	get_time_passed(t_all *all)
{
	struct timeval	cur_time;
	int				res;

	if (gettimeofday(&cur_time, NULL))
		return (error("Error: gettime\n"));
	res = ((int )(cur_time.tv_sec - s->start_time.tv_sec)) * 1000;
	res += ((int )cur_time.tv_usec - (int )s->start_time.tv_usec) / 1000;
	return (res);
}

void	smart_sleep(t_all *all, unsigned long t2do)
{
	unsigned long	end_time;

	if (all->die_status)
		return ;
	end_time = get_time_passed(all) + t2do;
	while ((unsigned long )get_time_passed(all) < end_time)
		usleep(100);
}