#include "philo.h"

void	print(int status, t_philo *p)
{
	long	t;

	sem_wait(p->sems[2]);
	t = timefromstart(p->start_time);
	if (status == 0)
	{
		printf("%ld %d died\n", t, p->id);
		return ;
	}
	if (status == 1 && !p->is_dead)
		printf("%ld %d has taken a fork\n", t, p->id);
	if (status == 2 && !p->is_dead)
		printf("%ld %d is eating\n", t, p->id);
	if (status == 3 && !p->is_dead)
		printf("%ld %d is sleeping\n", t, p->id);
	if (status == 4 && !p->is_dead)
		printf("%ld %d is thinking\n", t, p->id);
	sem_post(p->sems[2]);
}
