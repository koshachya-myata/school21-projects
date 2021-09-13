#include "philo.h"

int	create_thread(t_philo *t)
{
	int	er;

	er = pthread_create(&(t->monitor),
			NULL, monitoring, (void *)t);
	if (er != 0)
		return (0);
	return (1);
}

void	start_process(t_philo *t)
{
	t->start_eat = timestamp();
	if (!(create_thread(t)))
		exit (0);
	pthread_detach(t->monitor);
	while (1)
	{
		if (t->id % 2 == 0)
			ft_usleep(200, t);
		take_forks(t);
		eat(t);
		print(3, t);
		ft_usleep(t->sleep_time * 1000, t);
		print(4, t);
	}
}

void	*is_all_eat(void *ph)
{
	int		i;
	t_philo	*t;

	t = (t_philo *)ph;
	i = -1;
	while (++i < t->philo_count && t->is_dead == 0 )
		sem_wait(t->is_eated[i]);
	sem_post(t->sems[1]);
	t->is_dead = 1;
	return (NULL);
}

void	start_eat_thread(t_philo *t)
{
	int	er;

	if (t->eat_need > 0)
	{
		er = pthread_create(&(t->eated_check),
				NULL, is_all_eat, (void *)t);
		if (er < 0)
			free_exit(t, t->philo_count);
		pthread_detach(t->eated_check);
	}
}

int	main(int ac, char **av)
{
	t_philo	*t;
	int		i;

	t = NULL;
	check_errors(ac, av, &t);
	i = -1;
	t->start_time = timestamp();
	while (++i < t->philo_count)
	{
		t->id = i + 1;
		t->pids[i] = fork();
		if (t->pids[i] == 0)
			start_process(t);
		else if (t->pids[i] < 0)
			free_exit(t, i);
	}
	start_eat_thread(t);
	sem_wait(t->sems[1]);
	t->is_dead = 1;
	free_all(t, t->philo_count);
	return (0);
}
