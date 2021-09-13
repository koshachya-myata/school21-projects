/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:01:55 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 14:05:44 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_header(t_bmpheader *h, t_mini *t)
{
	h->reserved = 0;
	h->pxl_offset = 54;
	h->size_heder = 40;
	h->width = t->width;
	h->height = -t->height;
	h->clr_depth = 24;
	h->planes = 1;
	h->compression = 0;
	h->raw_size = 0;
	h->ver_res = 3780;
	h->hor_res = 3780;
	h->imp_col = 0;
	h->color_entries = 0;
	h->sizefile = 54 + 3 * t->height * t->width;
}

void	write_img_to_bmp(t_mini *t, int fd)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			write(fd,
			(unsigned int*)(t->img.data + y * t->img.line_length + x * 4), 3);
			x++;
		}
		y++;
	}
}

void	write_header(t_bmpheader h, int fd)
{
	int c;

	c = 0;
	c += write(fd, "BM", 2);
	c += write(fd, &h.sizefile, 4);
	c += write(fd, &h.reserved, 4);
	c += write(fd, &h.pxl_offset, 4);
	c += write(fd, &h.size_heder, 4);
	c += write(fd, &h.width, 4);
	c += write(fd, &h.height, 4);
	c += write(fd, &h.planes, 2);
	c += write(fd, &h.clr_depth, 2);
	c += write(fd, &h.compression, 4);
	c += write(fd, &h.raw_size, 4);
	c += write(fd, &h.hor_res, 4);
	c += write(fd, &h.ver_res, 4);
	c += write(fd, &h.color_entries, 4);
	c += write(fd, &h.imp_col, 4);
	if (c != 54)
		exit_print("Error in create .bmp file");
}

void	create_bmp(t_mini *t)
{
	int			fd;
	t_bmpheader	header;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU)) <= 0)
		exit_print("Cant create .bmp file");
	init_header(&header, t);
	write_header(header, fd);
	write_img_to_bmp(t, fd);
}
