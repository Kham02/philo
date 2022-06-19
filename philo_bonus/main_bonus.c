#include "../hdrs/philo_bonus.h"

static void	free_all(t_all **all, t_philo **philo)
{
	free((*all)->family);
	(*philo)->prev->next = NULL;
	ft_lstclear(philo);
	(*all)->philos_count = 0;
	(*all)->t2die = 0;
	(*all)->t2eat = 0;
	(*all)->t2sleep = 0;
	(*all)->num_eat = 0;
	(*all)->die_status = 0;
	free(*all);
	sem_close((*all)->sem_fork);
	sem_close((*all)->sem_stdout);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_STDOUT);
}

int	main(int ac, char **av)
{
	t_all	*all;
	t_philo	*philo;

	philo = NULL;
	all = ft_calloc(1, sizeof(t_all));
	if (!all)
		return(error("Error: malloc\n"));
	if (parse_input(ac, &av, &all))
		return (-1);
	if (gettimeofday(&all->start_time, NULL))
		return (error("Error: gettimeofday\n"));
	if (sem_init(&all))
		return (-1);
	if (proc(all, philo))
		return (-1);
	free_all(&all, &philo);
	return (0);
}