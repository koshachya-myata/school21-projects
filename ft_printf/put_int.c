/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:24:09 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 18:06:42 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_u(t_ptf *ptf, unsigned long num)
{
	put_i(ptf, num);
}

int		init_ptf_i(t_ptf *ptf, long long num)
{
	int t;

	t = 0;
	if (ptf->width_minus)
	{
		ptf->space = ' ';
		ptf->is_sp_left = 0;
	}
	if (ptf->is_dot && ptf->limit == -1)
		ptf->limit = 0;
	if (ptf->limit == 0)
		t = 1;
	if (ptf->limit != -1 && ptf->limit_minus == 0)
		ptf->space = ' ';
	else if (ptf->space == '0')
		ptf->limit = num > 0 ? ptf->width : ptf->width - 1;
	return (t);
}

int		init_len_i(t_ptf *ptf, long long num)
{
	int len;

	len = max(num_len(num, 10), ptf->limit);
	len = num < 0 ? len + 1 : len;
	if (ptf->is_sp_left)
		set_space(ptf, len);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		ptf->rt++;
	}
	return (len);
}

void	put_i(t_ptf *ptf, long long num)
{
	int len;
	int t;

	t = init_ptf_i(ptf, num);
	len = init_len_i(ptf, num);
	if ((!(t && num == 0)) || (ptf->limit_minus))
	{
		if (num >= 0)
			putzero(ptf, len - num_len(num, 10), 0);
		else
		{
			num = -num;
			putzero(ptf, len - 1 - num_len(num, 10), 0);
		}
		ptf->rt += num_len(num, 10);
		ft_putnbr(num);
	}
	else if (num == 0 && ptf->limit == 0 && ptf->width > 0)
	{
		ft_putchar_fd(' ', 1);
		ptf->rt += 1;
	}
	if (!(ptf->is_sp_left))
		set_space(ptf, len);
}
