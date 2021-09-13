/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:20:55 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 15:27:35 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int g_save = 0;

int		key_press(int key, t_mini *t)
{
	if (key == 53)
		exit(0);
	else if (key == 2)
	{
		next_camera(t);
		trace(t, 2);
	}
	return (1);
}

void	set_hooks(t_mini *v)
{
	mlx_do_key_autorepeatoff(v->mlx_ptr);
	mlx_hook(v->window, 2, 0, key_press, v);
	mlx_hook(v->window, 17, 0, exit_hook, v);
}

int		is_equal(int ac, int n)
{
	if (ac == n)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_mini	t;
	int		fd;

	g_save = is_equal(ac, 3);
	fd = check_open(ac, av);
	if (!(t.mlx_ptr = mlx_init()))
		exit_print("Can't init mlx");
	set_t_mini(&t);
	parse(&t, fd);
	if (!(t.img.img_ptr = mlx_new_image(t.mlx_ptr, t.width, t.height)))
		exit_print("Cant create new image");
	if (!(t.img.data = mlx_get_data_addr(t.img.img_ptr,
			&(t.img.bpp), &(t.img.line_length), &(t.img.endian))))
		exit_print("Cant create image data");
	trace(&t, g_save);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) == 0)
			create_bmp(&t);
		else
			exit_print("Invalid flag");
		exit(0);
	}
	set_hooks(&t);
	mlx_loop(t.mlx_ptr);
}
