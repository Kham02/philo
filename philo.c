/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:20:22 by estrong           #+#    #+#             */
/*   Updated: 2022/04/22 18:50:01 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	philo_atoi(t_philo *philo, char *str, unsigned int n, int s)
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
	check_int(philo, str);
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			return (error("", philo));
	}
	return (n * s);
}

int	check_int(t_philo *philo, char *str)
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
			return (error("", philo));
		i++;
	}
	return (0);
}

int	check(int ac, char **av, t_data *data, t_philo *philo)
{
	data->num_philo = philo_atoi(philo, av[1], 0, 1);
	data->time_die = philo_atoi(philo, av[2], 0, 1);
	data->time_eat = philo_atoi(philo, av[3], 0, 1);
	data->time_sleep = philo_atoi(philo, av[4], 0, 1);
	if (ac == 6)
		data->num_repeat = philo_atoi(philo, av[5], 0, 1);
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
	if (data == NULL || ac < 5 || ac > 6)
		return(error("Error\n", philo));
	if (check(ac, av, data, philo) == -1)
		return(error("Error\n", philo));
	forks_init(philo);
	create_stream(data, philo);
	write (1, "do\n", 3);
	if (data)
	{
		free(data);
		data = NULL;
	}
	return (0);
}

// void	print(t_philo *list)
// {
// 	t_philo *p;
// 	p = list;
// 	printf("\033[38;05;32;48;05;232m""| id |\t|eat_status|\t| die_status |""\033[m""\n");
// 	while (p->next != NULL)
// 	{
// 		printf("\033[38;05;115m""  %d\t  %d\t  %d""\033[m""\n", \
// 		(int)p->id, (int)p->eat_status, p->die_status);
// 		p = p->next;
// 	}
// }