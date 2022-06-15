/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:06:41 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 22:06:44 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/philo.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		if ((lst->next))
			return (ft_lstlast(lst->next));
	return (lst);
}
