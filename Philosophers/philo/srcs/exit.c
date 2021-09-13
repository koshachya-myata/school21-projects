#include "philo.h"

void	destoy_philo(t_philo *p)
{
	pthread_mutex_destroy(p->r_fork);
}

void	close_all(t_table *t, int c)
{
	int	i;

	i = -1;
	while (++i < c)
		destoy_philo(t->philos + i);
	free(t->philos);
	pthread_mutex_destroy(&(t->print));
}

void	init_exit(t_table *t, int c)
{
	close_all(t, c);
	free(t->forks);
	free(t);
}
