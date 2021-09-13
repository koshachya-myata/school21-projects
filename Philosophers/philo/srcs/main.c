#include "philo.h"

int	create_thread(t_table *t, int i)
{
	int	er;

	er = pthread_create(&t->philos[i].thread,
			NULL, routine, (void *)&(t->philos[i]));
	if (er != 0)
		return (i);
	return (-1);
}

int	start_threads(t_table *t)
{
	int	i;

	i = -1;
	t->start_time = timestamp();
	while (++i < t->philo_count)
	{
		t->philos[i].start_eat = timestamp();
		if (i % 2 == 0)
			if (create_thread(t, i) != -1)
				return (i);
	}
	usleep(500);
	i = 0;
	while (++i < t->philo_count)
		if (i % 2 == 1)
			if (create_thread(t, i) != -1)
				return (i);
	i = -1;
	while (++i < t->philo_count)
		pthread_detach(t->philos[i].thread);
	return (0);
}

int	all_eat(t_table *t)
{
	t->sim_flag = 0;
	init_exit(t, t->philo_count);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*t;
	int		i;

	t = NULL;
	if (check_errors(ac, av, &t))
		return (1);
	usleep(1000);
	while (t->sim_flag)
	{
		i = -1;
		if (is_all_eat(t) && t->eat_count >= 0)
			all_eat(t);
		while (++i < t->philo_count)
		{
			if (is_dead(&(t->philos[i])))
			{
				t->is_dead = 1;
				init_exit(t, t->philo_count);
				return (0);
			}
		}
	}
	return (0);
}
