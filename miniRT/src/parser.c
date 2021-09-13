/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:21:51 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:54:23 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_ambient(t_mini *t, char **tab)
{
	if (t->is_a)
		exit_print("Too many A in .rt file");
	if (tab[0][1])
		exit_print("Error key name in .rt file");
	t->ambient.light_ratio = str_to_double(tab[1]);
	t->ambient.color = get_color(tab[2]);
	t->is_a = 1;
}

int		check_line(char ***line, char ***tab)
{
	if (!***line)
	{
		free(**line);
		return (0);
	}
	if (!(*tab = ft_split(**line, ' ')))
		exit_print(0);
	return (1);
}

void	free_parse(char ***line, char ***tab)
{
	free(**line);
	free_tab(tab);
	**line = NULL;
	*tab = NULL;
}

void	parse_in(t_mini *t, char **line)
{
	char **tab;

	if (check_line(&line, &tab) == 0)
		return ;
	if (tab[0][0] == 'R')
		get_resolution(t, tab);
	else if (tab[0][0] == 'A')
		get_ambient(t, tab);
	else if (ft_strncmp(tab[0], "sp", 3) == 0)
		add_sphere(t, tab);
	else if (ft_strncmp(tab[0], "l", 2) == 0)
		add_light(t, tab);
	else if (ft_strncmp(tab[0], "pl", 3) == 0)
		add_plane(t, tab);
	else if (ft_strncmp(tab[0], "sq", 3) == 0)
		add_square(t, tab);
	else if (ft_strncmp(tab[0], "tr", 3) == 0)
		add_triangle(t, tab);
	else if (ft_strncmp(tab[0], "cy", 3) == 0)
		add_cylinder(t, tab);
	else if (ft_strncmp(tab[0], "c", 2) == 0)
		add_camera(t, tab);
	else if (tab[0][0] != '#')
		exit_print("Error key name in .rt file");
	free_parse(&line, &tab);
}

void	parse(t_mini *t, int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		parse_in(t, &line);
	}
	parse_in(t, &line);
}
