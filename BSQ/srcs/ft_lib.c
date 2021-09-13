/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:08:36 by vaztar            #+#    #+#             */
/*   Updated: 2020/08/12 12:09:33 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int		line_len(char *str)
{
	int res;

	res = 0;
	while (str[res] != '\0' && str[res] != '\n')
		res++;
	return (res);
}

int		ft_atoi(char *str, int len)
{
	int i;
	int znak;
	int res;

	znak = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\n' || str[i] == '\v')
		return (-1);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			znak *= -1;
		i++;
	}
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (znak * res);
}

int		ft_take_num(char *str)
{
	int s;

	s = line_len(str);
	if (s < 4)
		return (-1);
	return (ft_atoi(str, s - 3));
}

int		ft_min(int x, int y, int z)
{
	int		min;

	if (x < y)
		min = x;
	else
		min = y;
	if (min > z)
		min = z;
	return (min);
}
