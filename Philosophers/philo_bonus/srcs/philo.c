#include "philo.h"

int	take_forks(t_philo *t)
{
	if (t->is_dead == 1)
		return (0);
	sem_wait(t->sems[0]);
	print(1, t);
	sem_wait(t->sems[0]);
	print(1, t);
	return (1);
}

int	eat(t_philo *t)
{
	if (t->is_dead)
		return (0);
	t->start_eat = timestamp();
	print(2, t);
	ft_usleep(t->eat_time * 1000, t);
	sem_post(t->sems[0]);
	sem_post(t->sems[0]);
	t->eat_count += 1;
	return (1);
}
