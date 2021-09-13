/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaztar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:05:50 by vaztar            #+#    #+#             */
/*   Updated: 2021/08/29 20:25:31 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAZTAR_H
# define VAZTAR_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
 # include <fcntl.h>
# include <signal.h>
# include <limits.h>
# define MAXDIR 80

typedef struct	s_command
{
	int		in;
	int		out;
	char	*command;
	char	**argv;
	char	**envpv;

}				t_command;

typedef struct	s_commands
{
	char **envpv;
	t_command *commands;
	int		len;
}				t_commands;

typedef struct	s_com_hand
{
	int		t_in;
	int		t_out;
	int		old_fd;
	int		i;
	int		rt;
}				t_com_hand;


int		check_bin(char *b_path);
int		is_bin(char *path);
int		try_exec(char *path, t_command c);
int		exec(t_command c);
int		exec_absolute_path(t_command c);
void	exec_builtin(t_command c);
char	**get_paths(void);
int		is_builtin(t_command c);
int		command_handler(t_commands *c);
int		child_process(t_command command);
int		parent_process(pid_t *pids, int len);

void	check_errno(t_command c);
void	malloc_err(void *p);
void	dup_error(void);

void	ft_pwd(t_command c);
void	ft_exit(t_command c, int print_flag);
int		ft_cd(t_command c);
void	ft_env(t_command c);
int		ft_echo(t_command c);

#endif

