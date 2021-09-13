/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:30:42 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 19:22:37 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_space(t_ptf *ptf, long long limit)
{
	long long i;

	i = -1;
	if (limit == -1)
		limit = ptf->limit;
	while (++i < ptf->width - limit)
	{
		ft_putchar_fd(ptf->space, 1);
		(ptf->rt)++;
	}
}

int		put_null(t_ptf *ptf)
{
	char *str;

	if (!(str = ft_strdup("(null)")))
		return (-1);
	put_s(ptf, str);
	free(str);
	return (0);
}

void	putstr_limit(t_ptf *ptf, char *str)
{
	int i;

	i = 0;
	while (i < ptf->limit && str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
		(ptf->rt)++;
	}
}

void	putzero(t_ptf *ptf, int len, int sign)
{
	int i;

	i = -1;
	if (sign)
	{
		ft_putchar_fd('-', 1);
		(ptf->rt)++;
	}
	while (++i < len)
	{
		ft_putchar_fd('0', 1);
		(ptf->rt)++;
	}
}
