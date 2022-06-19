#include "../hdrs/philo_bonus.h"

static void	*check_for_death(void *tmp)
{
	t_philo			*philo;
	unsigned long	cur_time;

	philo = (t_philo *)tmp;
	while (1)
	{
		cur_time = get_time_passed(philo->all);
		if (cur_time >= philo->last_meal + philo->all->time_die
			&& philo->eat_num < (unsigned long )philo->all->num_eat)
		{
			philo->all->die_status = 1;
			write_action(philo->all, philo->philo_num, 'd');
			sem_wait(philo->all->sem_stdout);
			exit(2);
		}
	}
}

int	philo_routine(t_philo *philo)
{
	if (philo->philo_num > philo->all->philos_count / 2)
		usleep(100);
	if (pthread_create(&philo->death_check, NULL, &check_for_death, philo))
		exit(error("Error: thread: create\n"));
	if (pthread_detach(philo->death_check))
		exit(error("Error: thread: detach\n"));
	while (!philo->all->die_status)
	{
		sem_wait(philo->all->sem_fork);
		write_action(philo->all, philo->philo_num, 'f');
		sem_wait(philo->all->sem_fork);
		write_action(philo->all, philo->philo_num, 'f');
		write_action(philo->all, philo->philo_num, 'e');
		philo->last_meal = get_time_passed(philo->all);
		smart_sleep(philo->all, philo->all->time_eat);
		sem_post(philo->all->sem_fork);
		sem_post(philo->all->sem_fork);
		philo->eat_num += 1;
		if ((long long)philo->eat_num == philo->all->num_eat)
			exit(1);
		write_action(philo->all, philo->philo_num, 's');
		smart_sleep(philo->all, philo->all->time_sleep);
		write_action(philo->all, philo->philo_num, 't');
	}
	exit(2);
}