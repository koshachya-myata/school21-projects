#include "vaztar.h"
#include "tcider.h"

void	set_old_pwd(char **envpv)
{
	return ;
}

int		cd_home(char **envpv)
{
	char	*home;
	int		rt;

	home = read_env_value("HOME", get_env(envpv));
	if (home == NULL)
	{
		printf("minishell: cd: can't get HOME value");
		exit(1);
	}
	//set_old_pwd(envpv);
	rt = chdir(home);
	return (0);
}

int		cd_oldpwd(char **envpv)
{
	char	*home;
	int		rt;

	home = read_env_value("OLDPWD", get_env(envpv));
	if (home == NULL)
	{
		printf("minishell: cd: can't get OLDPWD value");
		exit(1);
	}
	//set_old_pwd(envpv);
	rt = chdir(home);
	return (0);
}
int		ft_cd(t_command c)
{
	int rt;

	if (c.argv[1] == NULL)
		return (cd_home(c.envpv));
	if (ft_strncmp(c.argv[1], "-", 2) == 0)
		return (cd_oldpwd(c.envpv));
	//set_old_pwd(envpv);
	rt = chdir(c.argv[1]);
	if (rt == -1)
	{
		printf("minishell: cd: %s: %s\n", c.argv[1], strerror(ENOENT));
		return (1);
	}
	return (0);
}