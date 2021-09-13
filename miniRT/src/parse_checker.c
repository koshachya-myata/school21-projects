/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:20:10 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 16:19:43 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	tab_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_num(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isdigit((*str)) == 0)
			return (0);
		str++;
	}
	return (1);
}

int	is_double(char *str)
{
	int dot;

	dot = 0;
	if (!str || !(*str))
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '.')
			return (0);
		if (*str == '.')
			dot++;
		str++;
	}
	if (dot > 1)
		return (0);
	if (*str == '.')
		return (0);
	return (1);
}

int	is_coords(char *str)
{
	char **tab;

	tab = ft_split(str, ',');
	if (tab_len(tab) != 3)
	{
		free_tab(&tab);
		return (0);
	}
	if (!is_double(tab[0]) || !is_double(tab[1]) || !is_double(tab[2]))
	{
		free_tab(&tab);
		return (0);
	}
	free_tab(&tab);
	return (1);
}

int	is_color(char *str)
{
	char	**tab;
	int		rt;

	if (!str)
		return (0);
	rt = 1;
	tab = ft_split(str, ',');
	if (tab_len(tab) != 3)
		rt = 0;
	if (!is_num(tab[0]) || !is_num(tab[1]) || !is_num(tab[2]))
		rt = 0;
	if (ft_atoi(tab[0]) < 0 || ft_atoi(tab[0]) > 255)
		rt = 0;
	if (ft_atoi(tab[1]) < 0 || ft_atoi(tab[2]) > 255)
		rt = 0;
	if (ft_atoi(tab[2]) < 0 || ft_atoi(tab[1]) > 255)
		rt = 0;
	free_tab(&tab);
	return (rt);
}
