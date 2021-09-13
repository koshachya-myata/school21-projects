#include "vaztar.h"

int		ft_is_numeric(char *s)
{
	int i;

	if (!s)
		return (0);
	i = -1;
	if (ft_strlen(s) == 1 && (s[0] == '-' || s[0] == '+'))
		return (0);
	while (s[++i])
		if (ft_isdigit(s[i]) == 0)
			if (i != 0 || (s[i] != '-' && s[i] != '+'))
				return (0);
	return(1);
	
}
void	ft_exit(t_command c, int print_flag)
{
	if (print_flag == 1)
		printf("exit\n");
	if ((c.argv)[1] == NULL)
		exit(0);
	if (ft_is_numeric((c.argv)[1]) == 0)
	{
		printf("minishell: exit: %s: numeric argument required\n", (c.argv)[1]);
		exit(255);
	}
	else if ((c.argv)[2] == NULL)
	{
		exit(ft_atoi((c.argv)[1]));
	}
	else
		printf("minishell: exit: too many arguments\n");
}