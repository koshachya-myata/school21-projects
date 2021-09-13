#include "philo.h"

int	is_eat(t_philo *t)
{
	if ((t->eat_count < t->eat_need))
		return (0);
	return (1);
}

int	is_dead(t_philo *p)
{
	if (p->start_eat + p->die_time < timestamp())
	{
		print(0, p);
		return (1);
	}
	return (0);
}

void	*monitoring(void *ph)
{
	t_philo	*t;

	t = (t_philo *) ph;
	while (1)
	{
		if (is_eat(t) && t->eat_count >= 0)
		{
			sem_post(t->is_eated[t->id - 1]);
		}
		if (is_dead(t))
		{
			sem_post(t->sems[1]);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
