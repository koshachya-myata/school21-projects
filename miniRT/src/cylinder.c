/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:50:16 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:40:27 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_roots_height(t_vec o, t_vec d, t_cylinder *cy)
{
	double	a;
	double	b;
	double	c;
	double	discr;

	a = scalar_product(d, d) - ft_pow(scalar_product(d, cy->orient_vec), 2);
	cy->x = v_substruct(o, cy->coords);
	b = 2 * (scalar_product(d, cy->x) - scalar_product(d, cy->orient_vec) *
		scalar_product(cy->x, cy->orient_vec));
	c = scalar_product(cy->x, cy->x) -
	ft_pow(scalar_product(cy->x, cy->orient_vec), 2) -
		cy->diametr * cy->diametr / 4.0;
	discr = b * b - 4 * a * c;
	if (discr < EPS)
		return (0);
	cy->t1 = (-b + sqrt(discr)) / (2 * a);
	cy->t2 = (-b - sqrt(discr)) / (2 * a);
	cy->h1 = scalar_product(d, cy->orient_vec) * cy->t1 +
		scalar_product(cy->x, cy->orient_vec);
	cy->h2 = scalar_product(d, cy->orient_vec) * cy->t2 +
		scalar_product(cy->x, cy->orient_vec);
	return (1);
}

double	get_root_cy(t_cylinder *cy)
{
	double	t;

	if (cy->h1 < EPS || cy->h1 > cy->height)
		cy->t1 = INF;
	if (cy->h2 < EPS || cy->h2 > cy->height)
		cy->t2 = INF;
	if (cy->t1 == INF && cy->t2 == INF)
		return (INF);
	t = min(cy->t1, cy->t2);
	if (t < EPS)
		return (max(cy->t1, cy->t2));
	return (t);
}

t_ans	*intersects_cylinder(t_vec o, t_vec d, t_cylinder *cy)
{
	t_ans	*ans;
	double	m;

	if (!(ans = (t_ans*)malloc(sizeof(t_ans))))
		exit_print(0);
	if (get_roots_height(o, d, cy) == 0)
		return (free_return_a((void*)&ans, NULL));
	ans->t = get_root_cy(cy);
	if (ans->t == INF || ans->t < EPS)
		return (free_return_a((void*)&ans, NULL));
	ans->color = cy->color;
	m = scalar_product(d, cy->orient_vec) * ans->t +
		scalar_product(cy->x, cy->orient_vec);
	cy->r = v_add(vs_dot(d, ans->t), o);
	ans->normal = normalize(v_substruct(v_substruct(cy->r, cy->coords),
		vs_dot(cy->orient_vec, m)));
	ans->normal = check_n(d, ans->normal);
	return (ans);
}
