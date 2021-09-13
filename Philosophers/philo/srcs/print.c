#include "philo.h"

void	print(int status, t_philo *p)
{
	long	t;

	pthread_mutex_lock(&p->table->print);
	t = timefromstart(p->table->start_time);
	if (status == 0)
	{
		printf("%ld %d died\n", t, p->id);
		return ;
	}
	if (status == 1 && !p->table->is_dead)
		printf("%ld %d has taken a fork\n", t, p->id);
	if (status == 2 && !p->table->is_dead)
		printf("%ld %d is eating\n", t, p->id);
	if (status == 3 && !p->table->is_dead)
		printf("%ld %d is sleeping\n", t, p->id);
	if (status == 4 && !p->table->is_dead)
		printf("%ld %d is thinking\n", t, p->id);
	pthread_mutex_unlock(&p->table->print);
}
