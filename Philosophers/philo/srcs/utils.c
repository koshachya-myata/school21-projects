#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (res > INT_MAX)
			return (-5);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
