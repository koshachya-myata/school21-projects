/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:55 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/06 13:06:24 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int res;

	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static void	if_num_less_zero(int *n, char *str, int len)
{
	if (*n != 0 && *n != -0 && *n != INT_MIN)
	{
		*n *= -1;
		str[0] = '-';
	}
	if (*n == 0 || *n == -0)
		ft_strlcpy(str, "0", (size_t)len + 1);
	if (*n == INT_MIN)
	{
		ft_strlcpy(str, "-2147483648", (size_t)len + 1);
		*n = 0;
	}
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	len = num_len(n);
	i = len;
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (n <= 0)
		if_num_less_zero(&n, str, len);
	while (n)
	{
		str[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}
