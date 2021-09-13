/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:34:56 by tcider            #+#    #+#             */
/*   Updated: 2020/10/31 09:03:38 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_writenum(char *res, int n, int mlt, int size)
{
	int		tmp;
	int		sign;

	tmp = -1;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		res[++tmp] = '-';
	}
	while (++tmp < size)
	{
		res[tmp] = (1 + (-2) * sign) * (n / mlt) + '0';
		n %= mlt;
		mlt /= 10;
	}
	res[tmp] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	int		sign;
	int		sum;
	int		mlt;
	char	*res;
	int		tmp;

	tmp = n;
	sign = 0;
	mlt = 1;
	if (n < 0)
		sign = 1;
	sum = 1;
	while ((tmp /= 10) && sum++)
		mlt *= 10;
	if (!(res = (char*)malloc(sizeof(char) * (sum + 1 + sign))))
		return (NULL);
	return (ft_writenum(res, n, mlt, sum + sign));
}
