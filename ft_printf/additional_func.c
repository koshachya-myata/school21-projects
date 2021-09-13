/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:34:07 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 18:45:08 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(long long n)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putstr_fd("-2147483648", 1);
			return ;
		}
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

long long	num_len(long long num, int x)
{
	long long res;

	res = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= x;
		res++;
	}
	return (res);
}

long long	uns_num_len(unsigned long long num, int x)
{
	long long res;

	res = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= x;
		res++;
	}
	return (res);
}

long long	max(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	min(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}
