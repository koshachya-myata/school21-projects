#include "philo.h"

void	print_exit(char *str, int c)
{
	printf("%s\n", str);
	exit (c);
}

void	free_exit(t_philo *t, int j)
{
	free_all(t, j);
	print_exit("Error", 1);
}

void	free_all(t_philo *t, int j)
{
	int		i;
	char	c[4];

	i = -1;
	while (++i < t->philo_count)
		kill(t->pids[i], 9);
	i = -1;
	memset(c, '1', 3);
	c[3] = 0;
	while (++i < j)
	{
		c[3] = c[3] + 1;
		sem_unlink(c);
	}
	sem_unlink("PHIL_FORKS");
	sem_unlink("PHIL_DEATH");
	sem_unlink("PHIL_PRINT");
	free(t->sems);
	free(t->pids);
	free(t->is_eated);
	free(t);
}
