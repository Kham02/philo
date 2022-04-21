#include "philo.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	philo_atoi(t_data *data, t_philo *philo, char *str, unsigned int n, int s)
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
	check_int(data, philo, str);
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			return (error("", data, philo));
	}
	return (n * s);
}

int	check_int(t_data *data, t_philo *philo, char *str)
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
			return (error("", data, philo));
		i++;
	}
	return (0);
}

int	check(int ac, char **av, t_data *data, t_philo *philo)
{
	if (data->num_philo == philo_atoi(data, philo, av[1], 0, 1) < 1)
		return (-1);
	if (data->time_die == philo_atoi(data, philo, av[2], 0, 1) < 1)
		return (-1);
	if (data->time_eat == philo_atoi(data, philo, av[3], 0, 1) < 1)
		return (-1);
	if (data->time_sleep == philo_atoi(data, philo, av[4], 0, 1) < 1)
		return (-1);
	if (ac == 5)
	{
		if (data->num_repeat == philo_atoi(data, philo, av[5], 0, 1) < 1)
			return (-1);
	}
	else
		data->num_repeat = 1;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (philo == NULL)
		return (-1);
	philo_init(philo, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	philo = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL || ac < 4 || ac > 5)
		return(error("Error\n", data, philo));
	if (check(ac, av, data, philo) == -1)
		return(error("Error\n", data, philo));
	forks_init(data, philo);
	create_stream(data, philo);
	return (0);
}
