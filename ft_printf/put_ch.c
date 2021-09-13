/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:41:27 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 19:21:53 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_c(t_ptf *ptf, char c)
{
	if (ptf->limit != -1)
		return (-1);
	ptf->limit = 1;
	if (ptf->is_sp_left)
		set_space(ptf, -1);
	ft_putchar_fd(c, 1);
	(ptf->rt)++;
	if (!(ptf->is_sp_left))
		set_space(ptf, -1);
	return (0);
}

int		put_s(t_ptf *ptf, char *str)
{
	if (!str)
		return (put_null(ptf));
	if (ptf->limit_minus)
		ptf->limit = ft_strlen(str);
	if (ptf->is_dot && ptf->limit == -1)
		ptf->limit = 0;
	if (ptf->limit == -1)
		ptf->limit = ft_strlen(str);
	else
		ptf->limit = min(ptf->limit, ft_strlen(str));
	if (ptf->is_sp_left)
		set_space(ptf, -1);
	putstr_limit(ptf, str);
	if (!(ptf->is_sp_left))
		set_space(ptf, -1);
	return (0);
}

int		put_percent(t_ptf *ptf)
{
	if (ptf->space == '0' && ptf->is_sp_left != 1)
		ptf->space = ' ';
	ptf->limit = 1;
	if (ptf->is_sp_left)
		set_space(ptf, -1);
	ft_putchar_fd('%', 1);
	(ptf->rt)++;
	if (!(ptf->is_sp_left))
		set_space(ptf, -1);
	return (0);
}

void	put_w(t_ptf *ptf, char c)
{
	set_space(ptf, 1);
	if (c)
	{
		ft_putchar_fd(c, 1);
		ptf->rt += 1;
	}
}
