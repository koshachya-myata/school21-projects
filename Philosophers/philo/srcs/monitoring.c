#include "philo.h"

int	is_all_eat(t_table *t)
{
	int	i;

	i = -1;
	while (++i < t->philo_count)
		if ((t->philos[i].eat_count < t->eat_count))
			return (0);
	return (1);
}

int	is_dead(t_philo *p)
{
	if (p->start_eat + p->table->die_time < timestamp())
	{
		pthread_mutex_lock(&(p->eat_death));
		if (p->start_eat + p->table->die_time < timestamp())
			p->table->sim_flag = 0;
		pthread_mutex_unlock(&(p->eat_death));
		print(0, p);
		return (1);
	}
	return (0);
}

void	*monitoring(void *table)
{
	t_table	*t;
	int		i;

	t = (t_table *) table;
	while (t->sim_flag)
	{
		i = -1;
		if (is_all_eat(t) && t->eat_count >= 0)
		{
			t->sim_flag = 0;
			return (NULL);
		}
		while (++i < t->philo_count)
			if (is_dead(&(t->philos[i])))
				return (NULL);
	}
	return (NULL);
}
