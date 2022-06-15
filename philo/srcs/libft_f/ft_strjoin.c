/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:33 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 22:06:36 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/philo.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *) malloc (1);
		s1[0] = '\0';
	}
	joint = (char *) malloc ((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!joint)
		return (NULL);
	while (s1[++i] != '\0')
		joint[i] = s1[i];
	while (s2[j] != '\0')
		joint[i++] = s2[j++];
	joint[i] = '\0';
	free (s1);
	return (joint);
}
