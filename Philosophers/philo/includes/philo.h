#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	long			start_eat;
	int				status;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	eat_death;
}				t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	int				philo_count;
	pthread_mutex_t	*forks;
	int				sim_flag;
	long			start_time;
	pthread_t		monitor;
	pthread_mutex_t	print;
	int				is_dead;
}			t_table;

int		check_numeric(char **av, int ac);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
void	print(int status, t_philo *p);
long	timefromstart(long time);
long	timestamp(void);
void	ft_usleep(long dt, t_table *t);
void	init_exit(t_table *t, int c);
void	*monitoring(void *table);
int		is_dead(t_philo *p);
int		is_all_eat(t_table *t);
void	*routine(void *philo);
t_table	*get_table(int ac, char **av);
int		check_errors(int ac, char **av, t_table **t);
int		start_threads(t_table *t);

#endif
