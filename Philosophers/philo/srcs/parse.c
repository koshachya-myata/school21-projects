#include "philo.h"

int	check_errors(int ac, char **av, t_table **t)
{
	int	c;

	if (ac != 6 && ac != 5)
	{
		printf("Incorrect number of arguments!\n");
		return (1);
	}
	*t = get_table(ac, av);
	if (!(*t))
	{
		printf("Error!\n");
		return (1);
	}
	c = start_threads(*t);
	if (c != 0)
	{
		printf("Cant create threads!\n");
		init_exit(*t, c);
		return (1);
	}
	return (0);
}

int	get_philos(t_table *t)
{
	int	l;
	int	i;

	l = t->philo_count;
	t->philos = (t_philo *)malloc(sizeof(t_philo) * l);
	if (!t->philos)
		return (0);
	i = -1;
	while (++i < l)
	{
		(t->philos)[i].id = i + 1;
		(t->philos)[i].eat_count = 0;
		(t->philos)[i].l_fork = &((t->forks)[i]);
		(t->philos)[i].r_fork = &((t->forks)[(i + 1) % l]);
		(t->philos)[i].table = t;
		pthread_mutex_init(&((t->philos)[i].eat_death), NULL);
		pthread_mutex_init(&((t->forks)[i]), NULL);
	}
	return (1);
}

int	check_input(char **av, int ac, t_table *rt)
{
	if (!rt)
		return (1);
	if (check_numeric(av + 1, ac - 1) == 0)
		return (1);
	rt->philo_count = ft_atoi(av[1]);
	rt->die_time = ft_atoi(av[2]);
	rt->eat_time = ft_atoi(av[3]);
	rt->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
	{
		rt->eat_count = ft_atoi(av[5]);
		if (rt->eat_count == -1)
			rt->eat_count = -5;
	}
	else
		rt->eat_count = -1;
	if (rt->philo_count <= 0 || rt->die_time <= 0 || rt->eat_count < -1
		|| rt->eat_time <= 0 || rt->sleep_time <= 0)
		return (1);
	return (0);
}

t_table	*get_table(int ac, char **av)
{
	t_table	*rt;

	rt = malloc(sizeof(t_table));
	if (!rt)
		return (NULL);
	if (check_input(av, ac, rt))
		return (NULL);
	rt->forks = malloc(sizeof(pthread_mutex_t) * rt->philo_count);
	if (!rt->forks)
		return (NULL);
	rt->sim_flag = 1;
	if (!get_philos(rt))
		return (NULL);
	pthread_mutex_init(&rt->print, NULL);
	rt->is_dead = 0;
	return (rt);
}
