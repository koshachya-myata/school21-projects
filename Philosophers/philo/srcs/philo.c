#include "philo.h"

int	take_forks(t_philo *p)
{
	if (p->table->is_dead == 1)
		return (0);
	pthread_mutex_lock(p->l_fork);
	print(1, p);
	pthread_mutex_lock(p->r_fork);
	print(1, p);
	return (1);
}

int	eat(t_philo *p)
{
	if (p->table->is_dead)
		return (0);
	pthread_mutex_lock(&(p->eat_death));
	p->start_eat = timestamp();
	pthread_mutex_unlock(&(p->eat_death));
	print(2, p);
	ft_usleep((p->table)->eat_time * 1000, p->table);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
	p->eat_count += 1;
	return (1);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	p->start_eat = timestamp();
	while ((p->table)->sim_flag)
	{
		if (!take_forks(p))
			return (0);
		if (!(eat(p)))
			return (0);
		print(3, p);
		if (p->table->is_dead == 1)
			return (0);
		ft_usleep((p->table)->sleep_time * 1000, p->table);
		print(4, p);
		if (p->table->is_dead == 1)
			return (0);
		if (p->id % 2 == 1)
			usleep(500);
	}
	return (0);
}
