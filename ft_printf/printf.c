/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:17:12 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 19:21:40 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(t_ptf *ptf, const char *inp, int *i)
{
	int res;

	res = ft_atoi(&(inp[*i]));
	while ((inp[*i] >= '0' && inp[*i] <= '9') || inp[*i] == '-')
		(*i)++;
	if (res < 0)
		ptf->width_minus = 1;
	ptf->width_opr = 1;
	return (res);
}

int		get_limit(t_ptf *ptf, const char *inp, int *i)
{
	int res;

	res = ft_atoi(&(inp[*i]));
	while ((inp[*i] >= '0' && inp[*i] <= '9') || inp[*i] == '-')
		(*i)++;
	if (res < 0)
		ptf->limit_minus = 1;
	ptf->limit_opr = 1;
	return (res);
}

void	initialize(t_ptf *ptf)
{
	ptf->space = ' ';
	ptf->width = -1;
	ptf->is_sp_left = 1;
	ptf->inp = NULL;
	ptf->limit = -1;
	ptf->is_dot = 0;
	ptf->limit_minus = 0;
	ptf->width_minus = 0;
	ptf->limit_opr = 0;
	ptf->width_opr = 0;
}

int		start_parse(t_ptf *ptf, const char *inp, va_list *argptr, int *i)
{
	initialize(ptf);
	(*i)++;
	return (parse(ptf, inp, argptr, i));
}

int		ft_printf(const char *inp, ...)
{
	va_list argptr;
	int		i;
	t_ptf	*ptf;

	va_start(argptr, inp);
	i = -1;
	if (!(ptf = (t_ptf*)malloc(sizeof(t_ptf))))
		return (-1);
	initialize(ptf);
	ptf->rt = 0;
	while (inp && inp[++i] && ptf->rt != -1)
	{
		if (inp[i] != '%' || !(inp[i + 1]))
		{
			ft_putchar_fd(inp[i], 1);
			(ptf->rt)++;
		}
		else if (start_parse(ptf, inp, &argptr, &i) == -1)
			return (-1);
	}
	va_end(argptr);
	free(ptf);
	return (ptf->rt);
}
