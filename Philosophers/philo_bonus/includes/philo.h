#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <signal.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	int				eat_need;
	int				philo_count;
	sem_t			**sems;
	sem_t			**is_eated;
	long			start_time;
	long			start_eat;
	int				is_dead;
	pthread_t		monitor;
	pthread_t		eated_check;
	pid_t			*pids;
}			t_philo;

int		check_numeric(char **av, int ac);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
void	print(int status, t_philo *p);
long	timefromstart(long time);
long	timestamp(void);
void	ft_usleep(long dt, t_philo *t);
void	free_all(t_philo *t, int j);
void	*monitoring(void *ph);
int		is_dead(t_philo *p);
void	*is_all_eat(void *ph);
void	*routine(void *philo);
t_philo	*get_table(int ac, char **av);
int		check_errors(int ac, char **av, t_philo **t);
int		start_threads(t_philo *t);
void	print_exit(char *str, int c);
int		take_forks(t_philo *t);
int		eat(t_philo *t);
void	free_exit(t_philo *t, int j);
#endif
