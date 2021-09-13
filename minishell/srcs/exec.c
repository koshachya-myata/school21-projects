/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:20:17 by vaztar            #+#    #+#             */
/*   Updated: 2021/08/29 20:19:19 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vaztar.h"

int		try_exec(char *path, t_command c)
{
	int		f;
	char	*new_str;
	char	*p;

	new_str = ft_strjoin("/", c.command);
	malloc_err((void*)new_str);
	p = ft_strjoin(path, new_str);
	malloc_err((void*)p);
	f = execve(p, c.argv, c.envpv);
	free(new_str);
	free(p);
	new_str = NULL;
	p = NULL;
	return (f);
}

int		exec(t_command c)
{
	char **paths;
	int i;
	int f;

	f = 0;
	paths = get_paths();
	i = -1;
	while (paths[++i] != NULL)
	{
		f = try_exec(paths[i], c);
		if (f == 1)
			return (1);
	}
	// printf("BAD to exec");
	check_errno(c); // Может надо и в другое время вызывать, а то так получается, что он выхватывает ошибку последнего в PATH
	return (f);
}

int		exec_absolute_path(t_command c)
{
	int f;


	f = execve(c.command, c.argv, c.envpv);
	if (f == -1)
	{
		check_errno(c);
	}
	return (f);
}

void	exec_builtin(t_command c)
{
	if (ft_strncmp(c.command, "echo", 5) == 0)
		ft_echo(c);
	if (ft_strncmp(c.command, "cd", 3) == 0)
		exit(0);
	if (ft_strncmp(c.command, "pwd", 4) == 0)
		ft_pwd(c);
	if (ft_strncmp(c.command, "unset", 6) == 0)
		exit(0);
	if (ft_strncmp(c.command, "env", 4) == 0)
		ft_env(c);
	if (ft_strncmp(c.command, "exit", 5) == 0)
	{
		ft_exit(c, 0);
		exit(1);
	}
	exit(0);
}
