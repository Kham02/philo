/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:16 by gernesto          #+#    #+#             */
/*   Updated: 2022/06/15 21:49:42 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# define MAX 4294967
# define MSG_FORK " has taken a fork\n"
# define MSG_EAT " is eating\n"
# define MSG_SLEEP " is sleeping\n"
# define MSG_THINK " is thinking\n"
# define MSG_DIE " died\n"

typedef struct all //s
{
	pthread_t		*thread;
	unsigned long	philos_count;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	long long		num_eat;
	int				die_status;
	int				i;
	struct timeval	start_time;
	pthread_mutex_t	stdout_stat;
}	t_all;

typedef struct ph //s2
{
	unsigned long	philo_num;
	unsigned long	eat_num;
	unsigned long	last_meal;
	pthread_mutex_t	fork;
	t_all			*all;
	struct ph		*next;
	struct ph		*prev;
}	t_list;

/* ~~~~~~~~~~ lib ~~~~~~~~~~~ */

t_list		*ft_lstnew(int num, t_all *all);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
size_t		ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);
long long	ft_atoi(const char *str, int *check_zero);

/* ~~~~~~~~~~ fun ~~~~~~~~~~~ */

int			error_write(char *msg);
int			parse_input(int ac, char ***av, t_all **all);
int			philos_and_mutexes_init(t_all **all, t_list **philo);
int			get_time_passed(t_all *all);
int			threads_init(t_all *all, t_list *philo);
void		*philo_life(void *all);
int			write_action(t_all *all, unsigned long philo, char c);
void		smart_sleep(t_all *all, unsigned long t2do);
void		loop_at_exit(t_all *all, t_list *philo);
int			destroy_mutexes_at_exit(t_all **all, t_list **philo);

#endif
