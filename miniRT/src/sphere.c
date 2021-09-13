/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:45:01 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:42:00 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	check_n(t_vec d, t_vec normal)
{
	if (scalar_product(d, normal) > 0)
		return (vs_dot(normal, -1));
	return (normal);
}

t_ans	*intersects_sphere(t_vec o, t_vec d, t_sphere *sp)
{
	t_vec	oc;
	t_ans	*ans;
	t_vec	p;

	if (!(ans = (t_ans*)malloc(sizeof(t_ans))))
		exit_print("Malloc error");
	oc = v_substruct(o, sp->center);
	sp->a = scalar_product(d, d);
	sp->b = scalar_product(oc, d) * 2;
	sp->c = scalar_product(oc, oc) - ft_pow(sp->diametr / 2.0, 2);
	sp->d = sp->b * sp->b - 4 * sp->a * sp->c;
	if (sp->d < EPS)
		return (free_return_a((void**)&ans, NULL));
	sp->t1 = (-(sp->b) + sqrt(sp->d)) / (2 * sp->a);
	sp->t2 = (-(sp->b) - sqrt(sp->d)) / (2 * sp->a);
	ans->color = sp->color;
	if (sp->t1 < EPS)
		return (free_return_a((void**)&ans, NULL));
	if (sp->t2 > EPS)
		ans->t = sp->t2;
	else
		ans->t = sp->t1;
	p = v_add(o, vs_dot(d, ans->t));
	ans->normal = check_n(d, normalize(v_substruct(p, sp->center)));
	return (ans);
}
