/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:51:27 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:41:48 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v_get_sin(t_vec a, t_vec b)
{
	double rt;

	rt = v_len(cross(a, b)) / (v_len(a) * v_len(b));
	return (rt);
}

double	v_get_cos(t_vec a, t_vec b)
{
	double rt;

	rt = scalar_product(a, b) / (v_len(a) * v_len(b));
	return (rt);
}

double	get_algebr_proection(t_vec a, t_vec o)
{
	double rt;

	rt = scalar_product(a, o) / v_len(o);
	return (fabs(rt));
}

void	set_sq(t_square *sq)
{
	if (fabs(sq->orient_vec.y) == 1)
		sq->down_s = create_vec(-1, 0, 0);
	else
		sq->down_s = create_vec(0, -1, 0);
	sq->down_s = cross(sq->orient_vec, sq->down_s);
	sq->delta = v_substruct(sq->p, sq->center);
	sq->c = v_abs(sq->delta);
}

t_ans	*intersects_square(t_vec o, t_vec d, t_square *sq)
{
	t_ans *ans;

	if (!(ans = (t_ans*)malloc(sizeof(t_ans))))
		exit_print(0);
	if (scalar_product(sq->orient_vec, d) > 0)
		sq->orient_vec = vs_dot(sq->orient_vec, -1);
	sq->t0 = get_pl_intersect(o, d, sq->center, sq->orient_vec);
	if (sq->t0 == 0)
		return (free_return_a((void**)&ans, NULL));
	sq->p = v_add(o, vs_dot(d, sq->t0));
	set_sq(sq);
	ans->color = sq->color;
	ans->normal = sq->orient_vec;
	ans->t = sq->t0;
	if (sq->c.x < EPS && sq->c.y < EPS && sq->c.z < EPS)
		return (ans);
	sq->aplha = fabs(v_get_cos(sq->down_s, sq->delta));
	if (sq->aplha <= sqrt(2) / 2)
		sq->aplha = cos(M_PI_2 - acos(sq->aplha));
	if (v_len(sq->delta) <= (sq->line / 2) / sq->aplha)
		return (ans);
	return (free_return_a((void**)&ans, NULL));
}
