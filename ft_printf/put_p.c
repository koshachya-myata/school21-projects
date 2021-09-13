/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:32:22 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 18:44:23 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_p(t_ptf *ptf, unsigned long long num)
{
	int			f;
	long long	p;

	p = ptf->limit;
	f = 1;
	if (ptf->limit_opr == 1)
		ptf->space = ' ';
	ptf->limit = uns_num_len(num, 16) + 2;
	if (ptf->is_dot && num == 0 && (ptf->limit_opr == 0 || p == 0))
	{
		f = 0;
		ptf->limit -= 1;
	}
	if (ptf->is_sp_left)
		set_space(ptf, -1);
	ft_putstr_fd("0x", 1);
	ptf->rt += 2;
	if (f)
		print_hex(num, 'a');
	if (!(ptf->is_sp_left))
		set_space(ptf, -1);
	if (f)
		ptf->rt += uns_num_len(num, 16);
}

void	print_hex(unsigned long long num, char start_10)
{
	if (num >= 16)
	{
		print_hex(num / 16, start_10);
		print_hex(num % 16, start_10);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd('0' + num, 1);
		else
			ft_putchar_fd(start_10 + (num - 10), 1);
	}
}

int		init_ptf_x(t_ptf *ptf, unsigned long long num)
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
	t = 0;
	if (ptf->limit == 0)
		t = 1;
	if (ptf->limit != -1 && ptf->limit_minus == 0)
		ptf->space = ' ';
	else if (ptf->space == '0')
		ptf->limit = num > 0 ? ptf->width : ptf->width - 1;
	return (t);
}

int		init_len_x(t_ptf *ptf, unsigned long long num)
{
	int len;

	len = max(num_len(num, 16), ptf->limit);
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

void	put_x(t_ptf *ptf, unsigned long long num, char start_10)
{
	int	len;
	int	t;

	t = init_ptf_x(ptf, num);
	len = init_len_x(ptf, num);
	if ((!(t && num == 0)) || (ptf->limit_minus))
	{
		if (num >= 0)
			putzero(ptf, len - uns_num_len(num, 16), 0);
		else
		{
			num = -num;
			putzero(ptf, len - 1 - uns_num_len(num, 16), 0);
		}
		ptf->rt += uns_num_len(num, 16);
		print_hex(num, start_10);
	}
	else if (num == 0 && ptf->limit == 0 && ptf->width > 0)
	{
		ft_putchar_fd(' ', 1);
		ptf->rt += 1;
	}
	if (!(ptf->is_sp_left))
		set_space(ptf, len);
}
