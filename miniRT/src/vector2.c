/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:46:20 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 12:18:50 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vs_dot(t_vec v, double s)
{
	t_vec rt;

	rt.x = v.x * s;
	rt.y = v.y * s;
	rt.z = v.z * s;
	return (rt);
}

t_vec	vs_plus(t_vec v, double s)
{
	t_vec rt;

	rt.x = v.x + s;
	rt.y = v.y + s;
	rt.z = v.z + s;
	return (rt);
}

double	scalar_product(t_vec v1, t_vec v2)
{
	double rt;

	rt = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (rt);
}

t_vec	create_vec(double x, double y, double z)
{
	t_vec rt;

	rt.x = x;
	rt.y = y;
	rt.z = z;
	return (rt);
}

t_vec	cross(t_vec a, t_vec b)
{
	t_vec rt;

	rt.x = a.y * b.z - a.z * b.y;
	rt.y = a.z * b.x - a.x * b.z;
	rt.z = a.x * b.y - a.y * b.x;
	return (rt);
}
