/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:50:47 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 14:30:19 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient(t_vec *rt, t_mini *t)
{
	rt->x = (double)t->ambient.color.r / 255.0 * t->ambient.light_ratio;
	rt->y = (double)t->ambient.color.g / 255.0 * t->ambient.light_ratio;
	rt->z = (double)t->ambient.color.b / 255.0 * t->ambient.light_ratio;
}

void	set_diff(t_vec *rt, t_light *l, t_ans *a, t_vec l_vec)
{
	double	n_l;

	n_l = scalar_product(a->normal, l_vec);
	if (n_l > EPS)
	{
		rt->x += (double)l->color.r / 255 *
				l->brightness * n_l / (v_len(a->normal) * v_len(l_vec));
		rt->y += (double)l->color.g / 255 *
				l->brightness * n_l / (v_len(a->normal) * v_len(l_vec));
		rt->z += (double)l->color.b / 255 *
				l->brightness * n_l / (v_len(a->normal) * v_len(l_vec));
	}
}

void	set_specularity(t_vec *rt, t_light *l,
						t_vec view, t_ans *a)
{
	t_vec	r;
	double	r_dot_v;
	t_vec	l_vec;

	l_vec = l->l_vec;
	r = v_substruct(vs_dot(a->normal,
						2.0 * scalar_product(a->normal, l_vec)), l_vec);
	r_dot_v = scalar_product(r, view);
	if (r_dot_v > EPS)
	{
		rt->x += (double)l->color.r / 255 * l->brightness *
				ft_pow(r_dot_v / (v_len(r) * v_len(view)), 500);
		rt->y += (double)l->color.g / 255 * l->brightness *
				ft_pow(r_dot_v / (v_len(r) * v_len(view)), 500);
		rt->z += (double)l->color.b / 255 * l->brightness *
				ft_pow(r_dot_v / (v_len(r) * v_len(view)), 500);
	}
}

t_vec	compute_light(t_mini *t, t_vec p, t_ans *a, t_vec view)
{
	t_vec	rt;
	t_ans	*shad;
	t_list	*lights;
	t_light	*l;

	shad = NULL;
	lights = t->lights;
	set_ambient(&rt, t);
	while (lights)
	{
		l = (t_light*)lights->content;
		l->l_vec = v_substruct(l->coords, p);
		shad = closest_intersection(t, p, l->l_vec, 1);
		if (shad)
		{
			lights = lights->next;
			free(shad);
			shad = NULL;
			continue;
		}
		set_diff(&rt, l, a, l->l_vec);
		set_specularity(&rt, l, view, a);
		lights = lights->next;
	}
	return (rt);
}
