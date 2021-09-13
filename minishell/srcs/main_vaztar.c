/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vaztar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:05:40 by vaztar            #+#    #+#             */
/*   Updated: 2021/07/13 19:54:30 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vaztar.h"

char	**get_paths(void)
{
	char *path;
	char **paths;

	path = getenv("PATH"); // WHAT DO IF PATH == NULL?
	paths = ft_split(path, ':');
	malloc_err((void*)paths);
	//free(path);
	return (paths);
}

int		is_builtin(t_command c)
{
	if (ft_strncmp(c.command, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(c.command, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(c.command, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(c.command, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(c.command, "env", 4) == 0)
		return (1);
	if (ft_strncmp(c.command, "exit", 5) == 0)
		return (1);
	return (0);
}

int		child_process(t_command command)
{
	int	rt;

	rt = 0;
	if (command.in != 0)
		if (dup2(command.in , 0) == -1)
			dup_error();
	if (command.out != 1)
		if (dup2(command.out , 1) == -1)
			dup_error();

	if (command.command[0] == '/' || command.command[0] == '.')
		rt = exec_absolute_path(command);
	else if (is_builtin(command))
		exec_builtin(command);
	else if (check_bin(command.command))
		rt = exec(command);
	else
		exit(127);
	if (command.in != 0)
		close(command.in);
	if (command.out != 1)
		close(command.out);
	return (rt);
}

int		parent_process(pid_t *pids, int len)
{
	int	status;
	int	rt;
	int i;
	rt = 0;
	waitpid(pids[--len], &status, 0);
	if (WIFEXITED(status) != 0)
		rt = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		rt = WTERMSIG(status);
	i = -1;
	while (++i < len)
		waitpid(pids[len - i - 1], &status, 0);
	return (rt);
}

void	init_com_hand(t_com_hand *s)
{
	s->t_in = dup(0);
	s->t_out = dup(1);
	s->old_fd = 0;
	s->i = -1;
	s->rt = 0;
}

void	last_command(pid_t *pids, t_com_hand *s, t_commands *c)
{
	if (pids[s->i] == 0)
	{
		dup2(s->t_out, 1);
		child_process((c->commands)[s->i]);
		close(s->old_fd);
	}
	else if (pids[s->i] < 0) //Error
	{
		ft_putstr_fd("minishell: fork: Resource temporarily unavailable\n", s->t_out);
		s->rt = parent_process(pids, c->len);
		close(s->old_fd);
		s->rt = 1;
	}
	else
	{
		close(s->old_fd);
		s->rt = parent_process(pids, c->len);
	}
}

void	create_pipe_commands(pid_t *pids, t_com_hand *s, t_commands *c, int fd[2])
{
	if (pids[s->i] == 0) // Child
	{
		close(fd[0]);
		if (dup2(fd[1], 1) == -1)
			dup_error();
		close(fd[1]);
		child_process((c->commands)[s->i]);
	}
	else if (pids[s->i] < 0) //Error
	{
		ft_putstr_fd("minishell: fork: Resource temporarily unavailable\n", s->t_out);
		close(fd[1]);
		close(s->old_fd);
		s->old_fd = dup(fd[0]);
		close(fd[0]);
		s->rt = parent_process(pids, s->i);
		s->i = c->len;
		s->rt = 1;
	}
	else // Parent
	{
		close(fd[1]);
		close(s->old_fd);
		s->old_fd = dup(fd[0]);
		close(fd[0]);
	}
}

int		close_all_return(t_com_hand *s)
{
	dup2(s->t_in, 0); // return stdin stdout
	dup2(s->t_out, 1);
	close(s->t_in);
	close(s->t_out);
	return (s->rt);
}

int		command_handler(t_commands *c)
{
	t_com_hand	s;
	pid_t		pids[c->len];
	int			fd[2];
	
	if (c->len == 1)
	{
		if (ft_strncmp((c->commands)[0].command, "exit", 5) == 0)
		{
			ft_exit((c->commands)[0], 1);
			return (1);
		}
		if (ft_strncmp((c->commands)[0].command, "cd", 3) == 0)
		{
			return (ft_cd((c->commands)[0]));
			return (1);
		}
	}
	init_com_hand(&s);
	while (++(s.i) < c->len)
	{
		dup2(s.old_fd, 0);
		if (s.i == c->len - 1) // last command? 
		{
			pids[s.i] = fork();
			last_command(pids, &s, c);
		}
		else
		{
			if (pipe(fd) == -1) // FIX ME
			{
				printf("minishell: too many fd opens\n");
				s.rt = parent_process(pids, s.i - 1);
				s.rt = 1;
				break;
			}
			pids[s.i] = fork();
			create_pipe_commands(pids, &s, c, fd);
		}
	}
	return (close_all_return(&s));
}