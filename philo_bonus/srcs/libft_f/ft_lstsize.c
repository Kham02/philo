#include "../../hdrs/philo_bonus_bonus.h"

unsigned long	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	if ((lst->next) == NULL)
		return (1);
	else
		return (ft_lstsize(lst->next) + 1);
}