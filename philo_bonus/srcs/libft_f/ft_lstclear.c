/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:11:55 by gernesto          #+#    #+#             */
/*   Updated: 2022/06/15 21:29:09 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/philo_bonus.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*prev_ptr;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		prev_ptr = tmp->next;
		tmp->philo_num = 0;
		tmp->eat_num = 0;
		tmp->last_meal = 0;
		tmp->all = NULL;
		tmp->prev = NULL;
		free(tmp);
		tmp = prev_ptr;
	}
	*lst = NULL;
}
