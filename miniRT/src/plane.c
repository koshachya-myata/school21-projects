/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:51:52 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:40:33 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	create_pl(t_vec coords, t_vec normal, t_rgb clr)
{
	t_plane	pl;

	pl.color = clr;
	pl.orient_vec = normal;
	pl.coords = coords;
	return (pl);
}

double	get_pl_intersect(t_vec o, t_vec d, t_vec coords, t_vec normal)
{
	t_plane	pl;
	double	t;
	t_ans	*t0;

	pl = create_pl(coords, normal, create_color(5, 5, 5));
	t0 = intersects_plane(o, d, &pl);
	if (t0 == NULL)
		return (0);
	t = t0->t;
	free(t0);
	return (t);
}

t_ans	*intersects_plane(t_vec o, t_vec d, t_plane *pl)
{
	t_ans	*ans;
	double	n_d;
	double	v_dot_d;
	double	v0;

	if (!(ans = (t_ans*)malloc(sizeof(t_ans))))
		exit_print("Malloc error");
	pl->orient_vec = check_n(d, pl->orient_vec);
	n_d = -1 * scalar_product(pl->orient_vec, pl->coords);
	v_dot_d = scalar_product(pl->orient_vec, d);
	if (v_dot_d > EPS)
		return (free_return_a((void*)&ans, NULL));
	v0 = -1 * scalar_product(pl->orient_vec, o) - n_d;
	pl->t = v0 / v_dot_d;
	if (pl->t < EPS)
		return (free_return_a((void*)&ans, NULL));
	ans->color = pl->color;
	ans->normal = pl->orient_vec;
	ans->t = pl->t;
	return (ans);
}
