#include "vaztar.h"
#include "tcider.h"

void	ft_env(t_command c)
{
	t_list *env;

	env = get_env(c.envpv);
	if (env == NULL)
	{
		printf("minishell: env: Error to get env");
		exit(1);
	}
	print_env(env);
}

void	implement_env(t_command *c, t_list *env)
{
	free(c->envpv);
}
void	set_env(t_command c, char *name , char *value)
{
	t_list *env;

	env = get_env(c.envpv);
	if (env == NULL)
	{
		printf("minishell: env: Error to get env");
		exit(1);
	}
	while (env)
	{
		if (ft_strcmp(((t_env *)env->content)->name, name) == 0)
		{
			free(((t_env *)env->content)->value);
			((t_env *)env->content)->value = ft_strdup(value);// CHECK NULL
			implement_env(&c, env);
		}
		env = env->next;
	}

}
