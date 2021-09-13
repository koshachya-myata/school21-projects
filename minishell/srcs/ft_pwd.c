#include "vaztar.h"

void	ft_pwd(t_command c)
{
	char pwd[MAXDIR];

	getcwd(pwd, MAXDIR);
	/*if (pwd == NULL)
	{
		printf("minishell: getcwd error\n");
		exit(1);
	}*/
	printf("%s\n", pwd);
	exit(0);
}