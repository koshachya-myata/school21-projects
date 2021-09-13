/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:55:36 by vaztar            #+#    #+#             */
/*   Updated: 2021/08/29 20:55:38 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vaztar.h"
#include "tcider.h"

int	init_echo(int *i, int *nl, t_command c)
{
	*nl = 1;
	*i = 1;
	if (!c.argv[*i])
	{
		printf("\n");
		return (0);
	}
	return (1);
}

int	ft_echo(t_command c)
{
	int	i;
	int	nl;

	if (!init_echo(&i, &nl, c))
		return (0);
	while (c.argv[i] && ft_strncmp("-n", c.argv[i], 3) == 0)
	{
		i++;
		nl = 0;
	}
	while (c.argv[i])
	{
		printf("%s", c.argv[i]);
		i++;
		if (c.argv[i])
			printf(" ");
	}
	if (nl)
		printf("\n");
	return (0);
}
