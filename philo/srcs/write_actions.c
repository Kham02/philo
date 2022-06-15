/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:10 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 23:33:59 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	error_write(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	return (-1);
}

static int	get_num_len(int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*get_num_in_char(int num)
{
	char	*res;
	int		end;
	int		i;

	end = get_num_len(num);
	i = end;
	res = (char *) malloc((end + 1) * sizeof(char));
	while (end-- != 0)
	{
		res[end] = num % 10 + 48;
		num /= 10;
	}
	res[i] = '\0';
	return (res);
}

char	*get_str_to_print(t_all *all, unsigned long philo, char c)
{
	char	*str_to_print;
	char	*num_in_char;
	int		timestamp;

	timestamp = get_time_passed(all);
	if (timestamp < 0)
		return (NULL);
	num_in_char = get_num_in_char(timestamp);
	str_to_print = ft_strjoin(NULL, num_in_char);
	free(num_in_char);
	str_to_print = ft_strjoin(str_to_print, " ");
	num_in_char = get_num_in_char((int )philo);
	str_to_print = ft_strjoin(str_to_print, num_in_char);
	free(num_in_char);
	if (c == 'f')
		str_to_print = ft_strjoin(str_to_print, MSG_FORK);
	else if (c == 'e')
		str_to_print = ft_strjoin(str_to_print, MSG_EAT);
	else if (c == 's')
		str_to_print = ft_strjoin(str_to_print, MSG_SLEEP);
	else if (c == 't')
		str_to_print = ft_strjoin(str_to_print, MSG_THINK);
	else if (c == 'd')
		str_to_print = ft_strjoin(str_to_print, MSG_DIE);
	return (str_to_print);
}

int	write_action(t_all *all, unsigned long philo, char c)
{
	char	*str_to_print;

	str_to_print = get_str_to_print(all, philo, c);
	if (!str_to_print)
		return (1);
	if (all->die_status && c != 'd')
	{
		free(str_to_print);
		return (1);
	}
	pthread_mutex_lock(&all->stdout_stat);
	write(STDOUT_FILENO, str_to_print, ft_strlen(str_to_print));
	free(str_to_print);
	pthread_mutex_unlock(&all->stdout_stat);
	return (0);
}
