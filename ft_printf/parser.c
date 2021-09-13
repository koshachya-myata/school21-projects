/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:35:51 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 19:22:14 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_ptf *ptf, const char *inp, va_list *argptr, int *i)
{
	if ((inp[(*i)] >= '0' && inp[(*i)] <= '9') || inp[(*i)] == '-')
		ptf->width = get_width(ptf, inp, i);
	else if (inp[(*i)] == '*')
	{
		ptf->width_opr = 1;
		ptf->width = va_arg(*argptr, int);
		if (ptf->width < 0)
		{
			ptf->width_minus = 1;
			ptf->width *= -1;
			ptf->is_sp_left = 0;
		}
		(*i)++;
	}
}

void	get_first_flags(t_ptf *ptf, const char *inp, int *i)
{
	while (inp[(*i)] == '-' || inp[(*i)] == '0')
	{
		if (inp[(*i)] == '-')
		{
			ptf->is_sp_left = 0;
		}
		else
		{
			if (ptf->is_sp_left)
				ptf->space = '0';
		}
		(*i)++;
	}
}

void	parse_limit(t_ptf *ptf, const char *inp, va_list *argptr, int *i)
{
	if (inp[(*i)] == '.')
	{
		ptf->is_dot = 1;
		(*i)++;
	}
	if ((inp[(*i)] >= '0' && inp[(*i)] <= '9') || inp[(*i)] == '-')
		ptf->limit = get_limit(ptf, inp, i);
	else if (inp[(*i)] == '*')
	{
		ptf->limit_opr = 1;
		ptf->limit = va_arg(*argptr, int);
		if (ptf->limit < 0)
			ptf->limit_minus = 1;
		(*i)++;
	}
}

int		parse_conversesion(t_ptf *ptf, const char *inp, va_list *argptr, int *i)
{
	int rt;

	rt = 0;
	if (inp[(*i)] == '%')
		put_percent(ptf);
	else if (inp[(*i)] == 'c')
		put_c(ptf, (unsigned char)va_arg(*argptr, int));
	else if (inp[(*i)] == 's')
		rt = put_s(ptf, va_arg(*argptr, char*));
	else if (inp[(*i)] == 'i' || inp[(*i)] == 'd')
		put_i(ptf, va_arg(*argptr, int));
	else if (inp[(*i)] == 'x')
		put_x(ptf, va_arg(*argptr, unsigned int), 'a');
	else if (inp[(*i)] == 'X')
		put_x(ptf, va_arg(*argptr, unsigned int), 'A');
	else if (inp[(*i)] == 'p')
		put_p(ptf, va_arg(*argptr, long));
	else if (inp[(*i)] == 'u')
		put_u(ptf, va_arg(*argptr, unsigned int));
	else
		put_w(ptf, inp[*i]);
	return (rt);
}

int		parse(t_ptf *ptf, const char *inp, va_list *argptr, int *i)
{
	int rt;

	get_first_flags(ptf, inp, i);
	parse_width(ptf, inp, argptr, i);
	parse_limit(ptf, inp, argptr, i);
	rt = parse_conversesion(ptf, inp, argptr, i);
	if (!(inp[*i]))
		(*i)--;
	return (rt);
}
