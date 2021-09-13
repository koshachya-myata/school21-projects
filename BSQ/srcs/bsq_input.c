/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 07:23:51 by tcider            #+#    #+#             */
/*   Updated: 2020/08/12 10:37:48 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		*bsq_zero_line(int size)
{
	int		i;
	int		*line;

	line = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		line[i] = 0;
	return (line);
}

int		**bsq_make_table(char *str, int *size, char *symb)
{
	int		i;
	int		j;
	int		**table;
	int		n;

	table = (int**)malloc(sizeof(int*) * (size[0] + 1));
	j = 0;
	i = -1;
	table[0] = bsq_zero_line(size[1] + 1);
	while (++j < size[0] + 1)
	{
		n = 0;
		table[j] = (int*)malloc(sizeof(int) * (size[1] + 1));
		table[j][n] = 0;
		while (str[++i] && str[i] != '\n' && n < size[1])
			if (str[i] == symb[0])
				table[j][++n] = -1;
			else if (str[i] == symb[1])
				table[j][++n] = 0;
			else
				return (NULL);
		if (str[i] != '\n' || n != size[1])
			return (NULL);
	}
	return (table);
}

int		bsq_read_header(char *str, int *i, char *symb)
{
	if (str[*i] && str[*i] >= ' ' && str[*i] <= '~')
		symb[0] = str[*i];
	else
		return (0);
	if (str[++(*i)] && str[*i] >= ' ' && str[*i] <= '~')
		symb[1] = str[*i];
	else
		return (0);
	if (str[++(*i)] && str[*i] >= ' ' && str[*i] <= '~')
		symb[2] = str[*i];
	else
		return (0);
	if (!str[++(*i)] || str[*i] != '\n' || symb[0] == symb[1])
		return (0);
	return (1);
}

int		**bsq_input(char *str, int *size, char *symb)
{
	int		i;
	int		n;
	int		**table;

	if (!str || (size[0] = ft_take_num(str)) <= 0)
		return (NULL);
	size[1] = 0;
	i = line_len(str) - 3;
	if (!bsq_read_header(str, &i, symb))
		return (NULL);
	size[1] = 0;
	n = i;
	while (str[++i] && str[i] != '\n')
		size[1]++;
	if (!size[1] || str[i] != '\n')
		return (NULL);
	table = bsq_make_table(&str[++n], size, symb);
	free(str);
	return (table);
}
