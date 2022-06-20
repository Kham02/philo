/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:07:04 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 22:07:07 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/philo_bonus.h"

static int	ft_isspace(char c, int *m)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == '+')
		return (1);
	else if (c == '-')
	{
		*m = -1 * *m;
		return (1);
	}
	return (0);
}

long long	ft_atoi(const char *str, int *check_zero)
{
	long long	res;
	int			m;
	int			i;

	res = 0;
	m = 1;
	i = 0;
	*check_zero = 0;
	while (ft_isspace(str[i], &m))
		i++;
	while ((str[i] > 47) && (str[i] < 58))
	{
		res = res * 10 + str[i++] - 48;
		*check_zero = 1;
	}
	if ((res > UINT32_MAX || m < 0) \
	|| ((str[i] < '0' || str[i] > '9') && str[i]))
	{
		*check_zero = 0;
		return (0);
	}
	return (res);
}
