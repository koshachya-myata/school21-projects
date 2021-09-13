/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:24:17 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 16:27:51 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx_mms/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <math.h>
# include <float.h>
# define EPS 0.0001
# define INF DBL_MAX

typedef struct	s_rgb
{
	short	r;
	short	g;
	short	b;
}				t_rgb;

typedef struct	s_ambient
{
	double	light_ratio;
	t_rgb	color;

}				t_ambient;

typedef struct	s_vec
{
	double x;
	double y;
	double z;

}				t_vec;

typedef struct	s_ans
{
	t_vec	normal;
	double	t;
	t_rgb	color;
	t_vec	coords;
}				t_ans;

typedef struct	s_sphere
{
	double	diametr;
	t_rgb	color;
	t_vec	center;
	double	a;
	double	b;
	double	c;
	double	d;
	double	t1;
	double	t2;
}				t_sphere;

typedef struct	s_plane
{
	t_vec	orient_vec;
	t_rgb	color;
	t_vec	coords;
	double	t;

}				t_plane;

typedef struct	s_square
{
	t_vec	center;
	t_rgb	color;
	t_vec	orient_vec;
	double	line;
	double	t0;
	t_vec	p;
	t_vec	c;
	t_vec	down_s;
	double	aplha;
	t_vec	delta;

}				t_square;

typedef struct	s_triangle
{
	t_rgb	color;
	t_vec	a;
	t_vec	b;
	t_vec	c;
	double	s;
	double	s1;
	double	s2;
	double	s3;
}				t_triangle;

typedef struct	s_cylinder
{
	t_rgb	color;
	t_vec	coords;
	t_vec	orient_vec;
	double	diametr;
	double	height;
	t_vec	x;
	t_vec	r;
	double	t1;
	double	t2;
	double	h1;
	double	h2;
}				t_cylinder;

typedef	struct	s_camera
{
	t_vec	coords;
	t_vec	vector;
	double	fov;
	t_vec	c_r;
	t_vec	c_u;
}				t_camera;

typedef	struct	s_light
{
	t_vec	coords;
	double	brightness;
	t_rgb	color;
	t_vec	l_vec;
}				t_light;

typedef	struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef	struct	s_bmpheader
{
	unsigned	sizefile;
	unsigned	reserved;
	unsigned	pxl_offset;
	unsigned	size_heder;
	unsigned	width;
	unsigned	height;
	short		planes;
	short		clr_depth;
	unsigned	compression;
	unsigned	raw_size;
	int			hor_res;
	int			ver_res;
	unsigned	color_entries;
	unsigned	imp_col;
}				t_bmpheader;

typedef struct	s_objlst
{
	short			obj_type;
	void			*content;
	struct s_objlst	*next;
}				t_objlst;

typedef struct	s_mini
{
	t_img			img;
	void			*window;
	void			*mlx_ptr;
	int				width;
	int				height;
	int				resolution[2];
	short			is_r;
	short			is_a;
	t_camera		*current_cam;
	t_ambient		ambient;
	t_list			*cameras;
	t_list			*lights;
	t_objlst		*objects;
}				t_mini;

/*
** numeric functions
*/
double			ft_pow(double d, int u);
double			str_to_double(char *str);
double			max(double a, double b);
double			min(double a, double b);
double			dabs(double x);

/*
** functions for vectors
*/
double			v_len(t_vec v);
t_vec			normalize(t_vec v);
t_vec			v_substruct(t_vec v1, t_vec v2);
t_vec			v_add(t_vec v1, t_vec v2);
t_vec			v_dot(t_vec v1, t_vec v2);
t_vec			vs_dot(t_vec v, double s);
t_vec			vs_plus(t_vec v, double s);
double			scalar_product(t_vec v1, t_vec v2);
t_vec			create_vec(double x, double y, double z);
t_vec			cross(t_vec a, t_vec b);
t_vec			v_abs(t_vec v);
t_vec			set_vector(double x, double y, double z);
t_rgb			normalize_color(t_rgb clr);
t_rgb			create_color(int r, int g, int b);
double			dots_len(t_vec a, t_vec b);

/*
** additional functions
*/
double			geron(double a, double b, double c);
double			tri_s_dots(t_vec a, t_vec b, t_vec c);
void			exit_print(char *str);
t_vec			check_n(t_vec d, t_vec normal);
t_plane			create_pl(t_vec coords, t_vec normal, t_rgb clr);
double			get_pl_intersect(t_vec o, t_vec d, t_vec coords, t_vec normal);
int				free_return_i(void *o, int rt);
t_ans			*free_return_a(void **o, t_ans *rt);
void			free_tab(char ***tab);
t_vec			other_3d_pxl(t_mini *t, int x, int y, t_camera *cam);
void			next_camera(t_mini *t);
void			set_t_mini(t_mini *t);
int				is_rt_file(char *str);
int				exit_hook(void);
int				check_open(int ac, char **av);
int				find_in_str(char *str, char c);
/*
** intesections
*/
t_ans			*intersects_sphere(t_vec o, t_vec d, t_sphere *sphere);
t_ans			*intersects_plane(t_vec o, t_vec d, t_plane *plane);
t_ans			*intersects_triangle(t_vec o, t_vec d, t_triangle *tr);
t_ans			*intersects_square(t_vec o, t_vec d, t_square *sq);
t_ans			*intersects_cylinder(t_vec o, t_vec d, t_cylinder *cy);
t_ans			*closest_intersection(t_mini *t, t_vec o,
										t_vec d, double t_max);

/*
** light
*/
t_vec			compute_light(t_mini *t, t_vec p, t_ans *a, t_vec view);

/*
** obj functions
*/
t_objlst		*ft_objnew(void *content, short type);
void			ft_objclear(t_objlst **lst, void (*del)(void*));
void			ft_objadd_back(t_objlst **lst, t_objlst *new);

/*
** parser
*/

void			parse(t_mini *t, int fd);
int				tab_len(char **str);
int				is_num(char *str);
int				is_double(char *str);
int				is_color(char *str);
int				is_coords(char *str);
void			add_plane(t_mini *t, char **tab);
void			add_square(t_mini *t, char **tab);
void			add_cylinder(t_mini *t, char **tab);
void			add_triangle(t_mini *t, char **tab);
void			get_resolution(t_mini *t, char **tab);
t_vec			get_coords(char *str);
t_rgb			get_color(char *str);
void			add_camera(t_mini *t, char **tab);
void			add_light(t_mini *t, char **tab);
void			add_sphere(t_mini *t, char **tab);

void			trace(t_mini *t, int s);

void			create_bmp(t_mini *t);

#endif
