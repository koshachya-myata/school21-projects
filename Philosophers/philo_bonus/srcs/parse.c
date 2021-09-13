#include "philo.h"

int	check_input(char **av, int ac, t_philo *rt)
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
		rt->eat_need = ft_atoi(av[5]);
		if (rt->eat_need == -1 || rt->eat_need == 0)
			rt->eat_need = -5;
	}
	else
		rt->eat_need = -1;
	if (rt->philo_count <= 0 || rt->die_time <= 0 || rt->eat_need < -1
		|| rt->eat_time <= 0 || rt->sleep_time <= 0)
		return (1);
	return (0);
}

void	check_sem_errors(t_philo *t)
{
	int	i;

	i = -1;
	while (++i < t->philo_count)
		if (t->is_eated[i] == SEM_FAILED)
			free_exit(t, t->philo_count);
	i = -1;
	while (++i < 3)
		if (t->sems[i] == SEM_FAILED)
			free_exit(t, t->philo_count);
}

void	create_sems(t_philo *rt)
{
	int		i;
	char	c[4];

	i = -1;
	memset(c, '1', 3);
	c[3] = 0;
	sem_unlink("PHIL_FORKS");
	sem_unlink("PHIL_DEATH");
	sem_unlink("PHIL_PRINT");
	while (++i < rt->philo_count)
	{
		c[3] = c[3] + 1;
		sem_unlink(c);
		rt->is_eated[i] = sem_open(c, O_CREAT | O_EXCL, S_IRWXG, 0);
	}
	rt->sems[0] = sem_open("PHIL_FORKS",
			O_CREAT | O_EXCL, S_IRWXG, rt->philo_count);
	rt->sems[1] = sem_open("PHIL_DEATH", O_CREAT | O_EXCL, S_IRWXG, 0);
	rt->sems[2] = sem_open("PHIL_PRINT", O_CREAT | O_EXCL, S_IRWXG, 1);
	check_sem_errors(rt);
}

t_philo	*get_philo(int ac, char **av)
{
	t_philo	*rt;

	rt = malloc(sizeof(t_philo));
	if (!rt)
		return (NULL);
	if (check_input(av, ac, rt))
		return (NULL);
	rt->sems = malloc(sizeof(sem_t *) * (4));
	rt->pids = malloc(sizeof(pid_t) * (rt->philo_count));
	rt->is_eated = malloc(sizeof(sem_t *) * (rt->philo_count));
	if (!rt->is_eated || !rt->sems || !rt->philo_count)
		return (NULL);
	create_sems(rt);
	rt->is_dead = 0;
	rt->eat_count = 0;
	return (rt);
}

int	check_errors(int ac, char **av, t_philo **t)
{
	if (ac != 6 && ac != 5)
	{
		printf("Incorrect number of arguments!\n");
		exit(1);
	}
	*t = get_philo(ac, av);
	if (!(*t))
		print_exit("Error", 1);
	return (0);
}
