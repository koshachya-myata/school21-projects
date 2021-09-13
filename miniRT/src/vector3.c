/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:47:14 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 14:29:38 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	v_abs(t_vec v)
{
	t_vec rt;

	rt.x = dabs(v.x);
	rt.y = dabs(v.y);
	rt.z = dabs(v.z);
	return (rt);
}

t_vec	set_vector(double x, double y, double z)
{
	t_vec rt;

	rt.x = x;
	rt.y = y;
	rt.z = z;
	return (rt);
}

t_rgb	normalize_color(t_rgb clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.b > 255)
		clr.b = 255;
	return (clr);
}

t_rgb	create_color(int r, int g, int b)
{
	t_rgb clr;

	clr.r = r;
	clr.b = b;
	clr.g = g;
	return (clr);
}

double	dots_len(t_vec a, t_vec b)
{
	double len;

	len = sqrt(ft_pow(a.x - b.x, 2) +
			ft_pow(a.y - b.y, 2) + ft_pow(a.z - b.z, 2));
	return (len);
}
