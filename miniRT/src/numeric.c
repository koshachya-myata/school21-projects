/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:52:36 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 16:34:01 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_pow(double d, int u)
{
	double rt;

	rt = 1;
	while (u)
	{
		rt *= d;
		u--;
	}
	return (rt);
}

double	str_to_double(char *str)
{
	double	rt;
	int		t;
	int		q;
	int		sign;

	if (!is_double(str))
		exit_print("Can't read float number");
	sign = 1;
	rt = (double)ft_atoi(str);
	if (rt < 0)
	{
		rt *= -1;
		sign = -1;
	}
	t = find_in_str(str, '.') + 1;
	if (t == 0)
		return (rt * sign);
	q = 1;
	while (str[t] && str[t] >= '0' && str[t] <= '9')
	{
		rt += (double)((int)(str[t] - '0')) / ft_pow(10, q);
		q++;
		t++;
	}
	return (rt * sign);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	dabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
