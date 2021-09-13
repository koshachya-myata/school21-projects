/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:46:02 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 17:06:56 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_plane(t_mini *t, char **tab)
{
	t_plane *s;

	if (tab_len(tab) != 4)
		exit_print("Invalid number of arguments of pl in .rt file");
	if (!(s = ft_calloc(1, sizeof(t_plane))))
		exit_print(0);
	s->coords = get_coords(tab[1]);
	s->orient_vec = normalize(get_coords(tab[2]));
	s->color = get_color(tab[3]);
	ft_objadd_back(&(t->objects), ft_objnew(s, 1));
}

void	add_square(t_mini *t, char **tab)
{
	t_square *s;

	if (tab_len(tab) != 5)
		exit_print("Invalid number of arguments of cy in .rt file");
	if (!(s = ft_calloc(1, sizeof(t_square))))
		exit_print(0);
	s->center = get_coords(tab[1]);
	s->orient_vec = normalize(get_coords(tab[2]));
	s->line = str_to_double(tab[3]);
	s->color = get_color(tab[4]);
	ft_objadd_back(&(t->objects), ft_objnew(s, 2));
}

void	add_cylinder(t_mini *t, char **tab)
{
	t_cylinder *s;

	if (tab_len(tab) != 6)
		exit_print("Invalid number of arguments of cy in .rt file");
	if (!(s = ft_calloc(1, sizeof(t_cylinder))))
		exit_print(0);
	s->coords = get_coords(tab[1]);
	s->orient_vec = normalize(get_coords(tab[2]));
	s->diametr = str_to_double(tab[4]);
	s->height = str_to_double(tab[5]);
	s->color = get_color(tab[3]);
	ft_objadd_back(&(t->objects), ft_objnew(s, 4));
}

void	add_triangle(t_mini *t, char **tab)
{
	t_triangle *s;

	if (tab_len(tab) != 5)
		exit_print("Invalid number of arguments of tr in .rt file");
	if (!(s = ft_calloc(1, sizeof(t_triangle))))
		exit_print(0);
	s->a = get_coords(tab[1]);
	s->b = get_coords(tab[2]);
	s->c = get_coords(tab[3]);
	s->color = get_color(tab[4]);
	ft_objadd_back(&(t->objects), ft_objnew(s, 3));
}

void	get_resolution(t_mini *t, char **tab)
{
	int u_x;
	int u_y;

	if (t->is_r)
		exit_print("More than 1 R i .rt file");
	if (tab[0][1])
		exit_print("Error key name in .rt file");
	if (tab_len(tab) != 3)
		exit_print("Invalid number of arguments of R in .rt file");
	mlx_get_screen_size(t->mlx_ptr, &u_x, &u_y);
	if (ft_atoi(tab[1]) > u_x)
		t->width = u_x;
	else
		t->width = ft_atoi(tab[1]);
	if (ft_atoi(tab[2]) > u_y)
		t->height = u_y;
	else
		t->height = ft_atoi(tab[2]);
	t->is_r = 1;
}
