#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/* ~~~~~~~~~~~~ inc ~~~~~~~~~~~~ */

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define MAX 4294967
# define SEM_FORK "philo_42_sem_fork"
# define SEM_STDOUT "philo_42_sem_stdout"
# define MSG_FORK " has taken a fork\n"
# define MSG_EAT " is eating\n"
# define MSG_SLEEP " is sleeping\n"
# define MSG_THINK " is thinking\n"
# define MSG_DIE " died\n"

/* ~~~~~~~~~~~~ struct ~~~~~~~~~~~~ */

typedef struct s_all
{
	pthread_t		th;
	unsigned long	count_ph;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	long long		num_eat;
	sem_t			*sem_fork;
	sem_t			*sem_stdout;
	pid_t			*family;
	int				die_status;
	struct timeval	start_time;
}	t_all;

typedef struct s_philo
{
	unsigned long	philo_num;
	unsigned long	eat_num;
	unsigned long	last_meal;
	pthread_t		death_check;
	t_all			*all;
	struct s2		*next;
	struct s2		*prev;
}	t_philo;

/* ~~~~~~~~~~~~ fun ~~~~~~~~~~~~ */

unsigned long	ft_lstsize(t_philo *lst);
t_list			*ft_lstnew(int num, t_all *all);
t_list			*ft_lstlast(t_philo *lst);
void			ft_lstclear(t_philo **lst);
void			ft_lstadd_back(t_philo **lst, t_philo *new);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
long long		ft_atoi(const char *str, int *check_zero);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *str);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);

int				error_write(char *msg);
int				parse_input(int ac, char ***av, t_all **all);
int				semaphores_init(t_all **all);
int				launch_thread_and_processes(t_all *all, t_philo *philo);
int				get_time_passed(t_all *all);
int				philo_routine(t_philo *philo);
int				write_action(t_all *all, unsigned long philo, char c);
void			smart_sleep(t_all *all, unsigned long time_do);

#endif
