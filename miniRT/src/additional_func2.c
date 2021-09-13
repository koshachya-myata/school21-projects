/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:16:41 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 14:47:25 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		exit_hook(void)
{
	exit(0);
}

int		is_rt_file(char *str)
{
	char *p;

	p = ft_strrchr(str, '.');
	if (p && *p && ft_strncmp(p, ".rt", 3) == 0)
		return (1);
	return (0);
}

void	set_t_mini(t_mini *t)
{
	t->current_cam = NULL;
	t->is_r = 0;
	t->is_a = 0;
}

int		check_open(int ac, char **av)
{
	int fd;

	if (ac < 1 || ac > 3)
		exit_print("Invalid number of arguments");
	if (is_rt_file(av[1]) == 0)
		exit_print("Not .rt file");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_print("Open file error");
	return (fd);
}

void	next_camera(t_mini *t)
{
	t_list		*cam_lst;
	t_camera	*first_cam;

	cam_lst = (t_list*)t->cameras;
	first_cam = (t_camera*)(cam_lst->content);
	while (cam_lst)
	{
		if ((t_camera*)(cam_lst->content) == t->current_cam)
			break ;
		cam_lst = cam_lst->next;
	}
	if (cam_lst->next == NULL)
		t->current_cam = first_cam;
	else
		t->current_cam = (t_camera*)(cam_lst->next->content);
}
