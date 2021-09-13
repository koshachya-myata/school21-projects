/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:21:12 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:54:47 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_print(char *str)
{
	if (*str == 0)
	{
		ft_putstr_fd("Memory alloc error\n", 1);
		exit(0);
	}
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}

void	free_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

int		free_return_i(void *o, int rt)
{
	free(o);
	return (rt);
}

t_ans	*free_return_a(void **o, t_ans *rt)
{
	free(*o);
	return (rt);
}

t_vec	other_3d_pxl(t_mini *t, int x, int y, t_camera *cam)
{
	t_vec	rt;
	double	f_c;
	double	a_r;
	double	n_x;
	double	n_y;

	f_c = 2 * tan((double)cam->fov * M_PI_2 / 180.0);
	a_r = (double)t->width / (double)t->height;
	cam->c_r = create_vec(-1, 0, 0);
	cam->c_u = normalize(cross(cam->c_r, cam->vector));
	cam->c_r = normalize(cross(cam->vector, cam->c_u));
	n_x = (((double)x / (double)t->width) - 0.5) * f_c;
	n_y = (((double)y / (double)t->height) - 0.5) * f_c;
	t->width < t->height ? n_x *= a_r : 0;
	t->width > t->height ? n_y /= a_r : 0;
	rt = v_add(v_add(v_add(vs_dot(cam->c_r, n_x),
						vs_dot(cam->c_u, n_y)), cam->coords), cam->vector);
	rt = normalize(v_substruct(rt, cam->coords));
	return (rt);
}
