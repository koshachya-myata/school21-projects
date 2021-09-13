#include "philo.h"

long	timestamp(void)
{
	struct timeval	t;
	long			rt;

	gettimeofday(&t, 0);
	rt = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (rt);
}

void	ft_usleep(long dt, t_table *t)
{
	long	needed_time;

	needed_time = timestamp() + dt / 1000;
	while (timestamp() < needed_time)
	{
		if (t->is_dead)
			return ;
		usleep(500);
	}
}

long	timefromstart(long time)
{
	return ((timestamp() - time));
}
