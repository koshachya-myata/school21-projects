/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:52:30 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 14:08:17 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	free_vars(char **arr, char **line, int fd, int rt)
{
	int	z;

	z = 1024;
	if (arr && fd != -1)
	{
		free(arr[fd]);
		arr[fd] = NULL;
	}
	else if (arr && fd == -1)
	{
		while (z--)
		{
			free(arr[z]);
			arr[z] = NULL;
		}
		free(arr);
		arr = NULL;
	}
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	return (rt);
}

int	func(char **line, char **arr, int fd, int len)
{
	char	*tmp;
	char	*t;

	if (len < 0)
		return (free_vars(arr, line, fd, -1));
	if (arr[fd] && (tmp = ft_strchr(arr[fd], '\n')))
	{
		free(*line);
		if (!(*line = gnl_ft_substr(tmp, 0, (int)(tmp - arr[fd]))))
			return (-1);
		if (!(t = gnl_ft_strdup(tmp + 1, 0)))
			return (free_vars(arr, line, fd, -1));
		free(arr[fd]);
		arr[fd] = t;
		return (1);
	}
	if (!(t = gnl_ft_strdup(*line, 1)))
		return (free_vars(arr, line, fd, -1));
	if (!(*line = gnl_ft_strjoin(t, arr[fd])))
		return (free_vars(arr, line, fd, -1));
	return (free_vars(arr, NULL, fd, 0));
}

int	init_vars(char ***line, char ***arr, int fd, char *buf)
{
	char	*tmp;

	tmp = NULL;
	if ((*arr)[fd])
		if (!(tmp = gnl_ft_strdup((*arr)[fd], 1)))
			return (free_vars(*arr, *line, fd, 1));
	if (!((*arr)[fd] = gnl_ft_strjoin(tmp, buf)))
		return (free_vars(*arr, *line, fd, 1));
	return (0);
}

int	read_lines(char **line, char **arr, int *len, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*t;
	char	*tt;

	while (((*len = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[*len] = '\0';
		if (init_vars(&line, &arr, fd, buf))
			return (-1);
		if ((t = ft_strchr(arr[fd], '\n')))
		{
			*t = '\0';
			free(*line);
			if (!(*line = gnl_ft_strdup(arr[fd], 0)))
				return (free_vars(arr, line, fd, -1));
			if (!(tt = gnl_ft_strdup(t + 1, 0)))
				return (free_vars(arr, line, fd, -1));
			free(arr[fd]);
			arr[fd] = tt;
			return (1);
		}
	}
	return (-2);
}

int	get_next_line(int fd, char **line)
{
	static char	*arr[513];
	int			len;
	char		*tmp;
	int			z;
	char		*t;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
			(!(*line = gnl_ft_strdup("", 0))))
		return (-1);
	if (arr[fd] && (tmp = ft_strchr(arr[fd], '\n')))
	{
		free(*line);
		if (!(*line = gnl_ft_substr(arr[fd], 0, (int)(tmp - arr[fd]))))
			return (-1);
		if (!(t = gnl_ft_strdup(tmp + 1, 0)))
			return (free_vars(arr, line, fd, -1));
		free(arr[fd]);
		arr[fd] = t;
		return (1);
	}
	if (!arr[fd] && (!(arr[fd] = gnl_ft_strdup("", 0))))
		return (-1);
	if ((z = read_lines(line, arr, &len, fd)) == -2)
		return (func(line, arr, fd, len));
	return (z);
}
