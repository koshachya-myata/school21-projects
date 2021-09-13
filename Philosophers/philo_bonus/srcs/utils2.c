#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (0);
	return (1);
}

int	check_numeric(char **av, int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
	{
		if (is_numeric(av[i]) == 0)
			return (0);
	}
	return (1);
}
