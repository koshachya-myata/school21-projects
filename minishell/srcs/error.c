/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:15:34 by vaztar            #+#    #+#             */
/*   Updated: 2021/07/11 19:05:22 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vaztar.h"

void	malloc_err(void *p)
{
	if (p == NULL)
	{
		printf("minishell: malloc error");
		exit(1);
	}
}

void	dup_error(void)
{
	if (errno == EBADF)
	{
		ft_putstr_fd("minishell: fd error\n", 1);
		exit(1);
	}
	if (errno == EMFILE)
	{
		ft_putstr_fd("minishell: limit of open file descriptors has been reached\n", 1);
		exit(1);
	}
	if (errno == EINTR)
	{
		ft_putstr_fd("minishell: dup call was interrupted by a signal\n", 1);
		exit(1);
	}
}

void	check_errno(t_command c)
{
	if (errno == E2BIG)
	{
		ft_putstr_fd("minishell: Too many arguments\n", 1);
		exit(1);
	}
	if (errno == EACCES)
	{
		printf("minishell: %s Permission denied\n", c.command);
		exit(126);
	}
	if (errno == EMFILE)
	{
		ft_putstr_fd("minishell: Too many openfiles\n", 1);
		exit(1);
	}
	if (errno == ENOENT)
	{
		printf("minishell: %s no such file or directore\n", c.command);
		exit(127);
	}
	if (errno == ENOEXEC)
	{
		printf("minishell: error exec format\n");
		exit(1);
	}
	if (errno == ENOMEM)
	{
		printf("minishell: not enough memory\n");
		exit(1);
	}
	if (errno == EIO)
	{
		printf("minishell: an I/O error occurred\n");
		exit(1);
	}
	if (errno == ENAMETOOLONG)
	{
		printf("minishell: pathname is too long\n");
		exit(1);
	}
	printf("minishell: execute error occurred\n");
	exit(1);
}