/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:49:07 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:41:31 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	geron(double a, double b, double c)
{
	double p;
	double s;

	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	return (s);
}

double	tri_s_dots(t_vec a, t_vec b, t_vec c)
{
	double l1;
	double l2;
	double l3;

	l1 = dots_len(a, b);
	l2 = dots_len(a, c);
	l3 = dots_len(b, c);
	l1 = l1 > 0 ? l1 : -l1;
	l2 = l2 > 0 ? l2 : -l2;
	l3 = l3 > 0 ? l3 : -l3;
	return (geron(l1, l2, l3));
}

int		check_tr(t_triangle *tr, t_vec r)
{
	tr->s1 = v_len(cross(v_substruct(tr->c, tr->b), v_substruct(r, tr->b))) / 2;
	tr->s2 = v_len(cross(v_substruct(tr->a, tr->c), v_substruct(r, tr->c))) / 2;
	tr->s3 = v_len(cross(v_substruct(tr->b, tr->a), v_substruct(r, tr->a))) / 2;
	tr->s = tri_s_dots(tr->a, tr->b, tr->c);
	if (tr->s1 < EPS || tr->s2 < EPS || tr->s3 < EPS)
		return (0);
	if (tr->s1 + tr->s2 + tr->s3 - tr->s > EPS)
		return (0);
	return (1);
}

t_ans	*intersects_triangle(t_vec o, t_vec d, t_triangle *tr)
{
	t_ans	*ans;
	double	t0;
	t_vec	r;

	if (!(ans = (t_ans *)malloc(sizeof(t_ans))))
		exit_print("Malloc error");
	ans->normal = check_n(d, normalize(cross(v_substruct(tr->b, tr->a),
				v_substruct(tr->c, tr->a))));
	t0 = get_pl_intersect(o, d, tr->a, ans->normal);
	if (t0 == 0)
		return (free_return_a((void**)&ans, NULL));
	r = v_add(vs_dot(d, t0), o);
	ans->t = t0;
	if (check_tr(tr, r) == 0)
		return (free_return_a((void**)&ans, NULL));
	ans->color = tr->color;
	return (ans);
}
