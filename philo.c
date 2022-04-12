#include "philo.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	philo_atoi(t_data *data, char *str, unsigned int n, int s)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		s = -1;
	}
	if (str[i] == '+' && s == 1)
		i++;
	check_int(data, str);
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
	}
	return (n * s);
}

void	check_int(t_data *data, char *str)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error(data);
		i++;
	}
}

void	check(int ac, char **av, t_data *data, t_philo *philo)
{
	data->num_philo = philo_atoi(data, av[1], 0, 1);
	data->time_die = philo_atoi(data, av[2], 0, 1);
	data->time_eat = philo_atoi(data, av[3], 0, 1);
	data->time_sleep = philo_atoi(data, av[4], 0, 1);
	if (ac == 5)
		data->num_repeat = philo_atoi(data, av[5], 0, 1);
	else
		data->num_repeat = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (ac < 4 || ac > 5)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	check(ac, av, data, philo);
}