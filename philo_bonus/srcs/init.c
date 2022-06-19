#include "../hdrs/philo_bonus.h"

static int	end_check_loop(t_all *all, int *res)
{
	int				child_stat;
	unsigned int	i;

	i = -1;
	while (++i < all->philos_count)
	{
		if (waitpid(-1, &child_stat, 0) == -1)
			return (error("Error: waitpid\n"));
		if (WSTOPSIG(child_stat) == 1)
		{
			*res += 1;
			if (*res == (int )all->philos_count)
				break ;
		}
		else if (WSTOPSIG(child_stat) == 2)
		{
			*res = 0;
			break ;
		}
	}
	return (0);
}

static int	launch_child_processes(t_all *all, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	all->family = (pid_t *)ft_calloc(all->philos_count, sizeof(pid_t));
	if (!all->family)
		return (error("Error: malloc\n"));
	while (i < all->philos_count)
	{
		all->family[i] = fork();
		if (all->family[i] < 0)
			exit(error("Error: fork\n"));
		if (!all->family[i])
			philo_routine(philo);
		i++;
		philo = philo->next;
	}
	philo = philo->next;
	return (0);
}

int	launch_thread_and_processes(t_all *all, t_philo *philo)
{
	unsigned int	i;
	int				res;

	if (launch_child_processes(all, philo))
		return (-1);
	res = 0;
	if (end_check_loop(all, &res))
		return (-1);
	if (res == (int )all->philos_count)
		return (0);
	else if (!(res))
	{
		i = -1;
		while (++i < all->philos_count)
			kill(all->family[i], SIGUSR1);
	}
	return (0);
}

int	semaphores_init(t_all **all)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_STDOUT);
	(*all)->sem_fork = sem_open(SEM_FORK, O_CREAT, 0660, (*all)->philos_count);
	if ((*all)->sem_fork == SEM_FAILED)
		return (error("Error: semaphore: open\n"));
	(*all)->sem_stdout = sem_open(SEM_STDOUT, O_CREAT, 0660, 1);
	if ((*all)->sem_stdout == SEM_FAILED)
		return (error("Error: semaphore: open\n"));
	return (0);
}