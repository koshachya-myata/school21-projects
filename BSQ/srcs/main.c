/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:48:49 by tcider            #+#    #+#             */
/*   Updated: 2020/08/11 15:52:09 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void		free_table(int **table, int size)
{
	int	i;

	i = -1;
	while (++i <= size)
		free(table[i]);
	free(table);
}

t_result	bsq_solution(int **tbl, int *size)
{
	int			i;
	int			j;
	t_result	res;

	i = 0;
	res.size = 0;
	res.i = 0;
	res.j = 0;
	while (++i < size[0] + 1)
	{
		j = 0;
		while (++j < size[1] + 1)
		{
			if (tbl[i][j])
				tbl[i][j] =
					ft_min(tbl[i - 1][j], tbl[i - 1][j - 1], tbl[i][j - 1]) + 1;
			if (tbl[i][j] > res.size)
			{
				res.i = i;
				res.j = j;
				res.size = tbl[i][j];
			}
		}
	}
	return (res);
}

void		bsq_print(int **tbl, int *size, char *symb, t_result res)
{
	int			i;
	int			j;

	i = 0;
	while (++i < size[0] + 1)
	{
		j = 0;
		while (++j < size[1] + 1)
		{
			if (!tbl[i][j])
				write(1, &symb[1], 1);
			else if (i > (res.i - res.size) && i <= res.i &&
					(j > (res.j - res.size) && j <= res.j))
				write(1, &symb[2], 1);
			else
				write(1, &symb[0], 1);
		}
		write(1, "\n", 1);
	}
	free_table(tbl, size[0]);
}

int			main(int argc, char **argv)
{
	char		symb[3];
	int			size[2];
	int			**table;
	int			i;

	if (argc == 1)
	{
		if ((table = bsq_input(std_input(0), size, symb)))
			bsq_print(table, size, symb, bsq_solution(table, size));
		else
			write(2, "map error\n", 10);
	}
	i = 0;
	while (++i < argc)
	{
		if ((table = bsq_input(std_input(std_file(argv[i])), size, symb)))
			bsq_print(table, size, symb, bsq_solution(table, size));
		else
			write(2, "map error\n", 10);
		if (i != argc - 1)
			write(1, "\n", 1);
	}
	return (0);
}
