/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:13:12 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:32:00 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(t_mini *t, int x, int y, t_rgb clr)
{
	char	*dst;

	dst = t->img.data + (x * (t->img.bpp / 8) + y * t->img.line_length);
	if (t->img.endian == 1)
	{
		dst[1] = (char)clr.r;
		dst[2] = (char)clr.g;
		dst[3] = (char)clr.b;
	}
	else
	{
		dst[2] = (char)clr.r;
		dst[1] = (char)clr.g;
		dst[0] = (char)clr.b;
	}
}

t_vec	to3dpixel(t_mini *t, int x, int y, t_camera *cam)
{
	t_vec	rt;
	double	f_c;
	double	a_r;
	double	n_x;
	double	n_y;

	f_c = 2 * tan((double)cam->fov * M_PI_2 / 180.0);
	a_r = (double)t->width / (double)t->height;
	if (fabs(cam->vector.y) == 1)
		return (other_3d_pxl(t, x, y, cam));
	cam->c_u = create_vec(0, -1, 0);
	cam->c_r = normalize(cross(cam->vector, cam->c_u));
	cam->c_u = normalize(cross(cam->c_r, cam->vector));
	n_x = (((double)x / (double)t->width) - 0.5) * f_c;
	n_y = (((double)y / (double)t->height) - 0.5) * f_c;
	t->width < t->height ? n_x *= a_r : 0;
	t->width > t->height ? n_y /= a_r : 0;
	rt = v_add(v_add(v_add(vs_dot(cam->c_r, n_x),
						vs_dot(cam->c_u, n_y)), cam->coords), cam->vector);
	rt = normalize(v_substruct(rt, cam->coords));
	return (rt);
}

t_rgb	put_ray(t_mini *t, t_vec camera_pos, t_vec v)
{
	t_ans	*closest_ans;
	t_vec	k;
	t_vec	p;
	t_vec	view;
	t_rgb	clr;

	closest_ans = closest_intersection(t, camera_pos, v, DBL_MAX - 10);
	if (!closest_ans)
		return (create_color(0, 0, 0));
	p = v_add(camera_pos, vs_dot(v, closest_ans->t));
	view = vs_dot(v, -1);
	k = compute_light(t, p, closest_ans, view);
	closest_ans->color.r *= k.x;
	closest_ans->color.g *= k.y;
	closest_ans->color.b *= k.z;
	clr = closest_ans->color;
	free(closest_ans);
	return (normalize_color(clr));
}

void	put_trace(t_mini *t, int s)
{
	if (s == 0)
		if (!(t->window = mlx_new_window(t->mlx_ptr,
					t->width, t->height, "miniRT")))
			exit_print("Can't create window");
	if (s == 0 || s == 2)
		mlx_put_image_to_window(t->mlx_ptr, t->window, t->img.img_ptr, 0, 0);
}

void	trace(t_mini *t, int s)
{
	int			x;
	int			y;
	t_vec		v;
	t_rgb		clr;
	t_camera	*cam;

	cam = t->current_cam;
	x = 0;
	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			v = to3dpixel(t, x, y, cam);
			clr = put_ray(t, cam->coords, v);
			put_pixel(t, x, y, clr);
			x++;
		}
		y++;
	}
	put_trace(t, s);
}
