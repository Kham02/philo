#include "../hdrs/philo_bonus.h"

static int	create_philos_list(t_all **all, t_philo **philo)
{
	t_philo			*lst_start;
	t_philo			*lst_last;
	unsigned long	i;

	(*all)->die_status = 0;
	i = -1;
	while (++i < (*all)->philos_count)
		ft_lstadd_back(&(*philo), ft_lstnew(i + 1, (*all)));
	if (ft_lstsize(*philo) != (*all)->philos_count)
		return (error("Error: malloc\n"));
	lst_start = (*philo);
	lst_last = ft_lstlast((*philo));
	lst_last->next = (*philo);
	(*philo)->prev = lst_last;
	(*philo) = lst_start;
	return (0);
}

int	parse_input(int ac, char ***av, t_all **all)
{
	int	i;
	int	status[5];

	if (ac < 5)
		return (error("Error: lack of arguments\n"));
	else if (ac > 6)
		return (error("Error: arguments: more than needed\n"));
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
		return (error("Error: invalid arguments\n"));
	return (0);
}