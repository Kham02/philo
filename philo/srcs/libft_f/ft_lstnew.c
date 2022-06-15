/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:13:22 by gernesto          #+#    #+#             */
/*   Updated: 2022/06/15 21:28:47 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/philo.h"

t_list	*ft_lstnew(int num, t_all *all)
{
	t_list	*list;

	list = (t_list *) ft_calloc(1, sizeof(t_list));
	if (list)
	{
		list->philo_num = num;
		list->all = all;
	}
	return (list);
}
