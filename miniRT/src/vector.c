/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:45:36 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 12:19:09 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	v_len(t_vec v)
{
	double rt;

	rt = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (rt);
}

t_vec	normalize(t_vec v)
{
	t_vec	rt;
	double	len;

	len = v_len(v);
	rt.x = v.x / len;
	rt.y = v.y / len;
	rt.z = v.z / len;
	return (rt);
}

t_vec	v_substruct(t_vec v1, t_vec v2)
{
	t_vec rt;

	rt.x = v1.x - v2.x;
	rt.y = v1.y - v2.y;
	rt.z = v1.z - v2.z;
	return (rt);
}

t_vec	v_add(t_vec v1, t_vec v2)
{
	t_vec rt;

	rt.x = v1.x + v2.x;
	rt.y = v1.y + v2.y;
	rt.z = v1.z + v2.z;
	return (rt);
}

t_vec	v_dot(t_vec v1, t_vec v2)
{
	t_vec rt;

	rt.x = v1.x * v2.x;
	rt.y = v1.y * v2.y;
	rt.z = v1.z * v2.z;
	return (rt);
}
