/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:10:21 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 16:27:05 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ans	*intersect(t_vec o, t_vec d, t_objlst *obj)
{
	t_ans *ans;

	ans = NULL;
	if (obj->obj_type == 0)
		ans = intersects_sphere(o, d, (t_sphere*)obj->content);
	else if (obj->obj_type == 1)
		ans = intersects_plane(o, d, (t_plane*)obj->content);
	else if (obj->obj_type == 2)
		ans = intersects_square(o, d, (t_square*)obj->content);
	else if (obj->obj_type == 3)
		ans = intersects_triangle(o, d, (t_triangle*)obj->content);
	else if (obj->obj_type == 4)
		ans = intersects_cylinder(o, d, (t_cylinder*)obj->content);
	return (ans);
}

t_ans	*copy_ans(t_ans *x)
{
	t_ans *ans;

	if (!(ans = (t_ans*)malloc(sizeof(t_ans))))
		exit_print(0);
	ans->t = x->t;
	ans->color = x->color;
	ans->normal = x->normal;
	return (ans);
}

t_ans	*closest_intersection(t_mini *t, t_vec o, t_vec d, double t_max)
{
	t_ans		*closest_ans;
	t_ans		*x;
	t_objlst	*obj;

	obj = t->objects;
	closest_ans = NULL;
	x = NULL;
	while (obj)
	{
		if ((x = intersect(o, d, obj)))
		{
			if ((closest_ans == NULL || x->t < closest_ans->t) &&
									x->t <= t_max && x->t >= EPS)
			{
				if (closest_ans)
					free(closest_ans);
				closest_ans = copy_ans(x);
			}
			free(x);
			x = NULL;
		}
		obj = obj->next;
	}
	return (closest_ans);
}
