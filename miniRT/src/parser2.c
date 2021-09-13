/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:43:13 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 16:20:28 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_coords(char *str)
{
	char	**tab;
	t_vec	rt;

	if (!is_coords(str))
		exit_print("Can't get coordinates in .rt file");
	tab = ft_split(str, ',');
	rt.x = str_to_double(tab[0]);
	rt.y = str_to_double(tab[1]);
	rt.z = str_to_double(tab[2]);
	free_tab(&tab);
	return (rt);
}

t_rgb	get_color(char *str)
{
	char	**tab;
	t_rgb	color;

	if (!is_color(str))
		exit_print("Can't get color in .rt file");
	tab = ft_split(str, ',');
	color.r = ft_atoi(tab[0]);
	color.g = ft_atoi(tab[1]);
	color.b = ft_atoi(tab[2]);
	free_tab(&tab);
	return (color);
}

void	add_camera(t_mini *t, char **tab)
{
	t_camera *cam;

	if (tab_len(tab) != 4)
		exit_print("Invalid number of arguments of c in .rt file");
	if (!(cam = ft_calloc(1, sizeof(t_camera))))
		exit_print(0);
	cam->coords = get_coords(tab[1]);
	cam->vector = normalize(get_coords(tab[2]));
	cam->fov = str_to_double(tab[3]);
	if (!(t->current_cam))
		t->current_cam = cam;
	ft_lstadd_back(&(t->cameras), ft_lstnew(cam));
}

void	add_light(t_mini *t, char **tab)
{
	t_light *rt;

	if (tab_len(tab) != 4)
		exit_print("Invalid number of arguments of l in .rt file");
	if (!(rt = ft_calloc(1, sizeof(t_camera))))
		exit_print(0);
	rt->coords = get_coords(tab[1]);
	rt->brightness = str_to_double(tab[2]);
	rt->color = get_color(tab[3]);
	ft_lstadd_back(&(t->lights), ft_lstnew(rt));
}

void	add_sphere(t_mini *t, char **tab)
{
	t_sphere *s;

	if (tab_len(tab) != 4)
		exit_print("Invalid number of arguments of sp in .rt file");
	if (!(s = ft_calloc(1, sizeof(t_sphere))))
		exit_print(0);
	s->center = get_coords(tab[1]);
	s->diametr = str_to_double(tab[2]);
	s->color = get_color(tab[3]);
	ft_objadd_back(&(t->objects), ft_objnew(s, 0));
}
