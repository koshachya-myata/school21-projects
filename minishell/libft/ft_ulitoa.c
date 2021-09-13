/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:11:23 by tcider            #+#    #+#             */
/*   Updated: 2020/11/26 13:58:25 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_writenum(char *res, unsigned long int n,
	unsigned long int mlt, int size)
{
	int					tmp;

	tmp = -1;
	while (++tmp < size)
	{
		res[tmp] = n / mlt + '0';
		n %= mlt;
		mlt /= 10;
	}
	res[tmp] = '\0';
	return (res);
}

char			*ft_ulitoa(unsigned long int n)
{
	int					sum;
	unsigned long int	mlt;
	char				*res;
	unsigned long int	tmp;

	tmp = n;
	mlt = 1;
	sum = 1;
	while ((tmp /= 10) && sum++)
		mlt *= 10;
	if (!(res = (char*)malloc(sizeof(char) * (sum + 1))))
		return (NULL);
	return (ft_writenum(res, n, mlt, sum));
}
