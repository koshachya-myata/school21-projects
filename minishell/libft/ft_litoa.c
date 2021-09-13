/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:03:49 by tcider            #+#    #+#             */
/*   Updated: 2020/11/26 13:59:52 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_writenum(char *res, long int n,
	unsigned long int mlt, int size)
{
	int					tmp;
	int					sign;

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

char			*ft_litoa(long int n)
{
	int					sign;
	int					sum;
	unsigned long int	mlt;
	char				*res;
	long int			tmp;

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
