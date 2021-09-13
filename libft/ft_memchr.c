/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:51:30 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/31 14:12:33 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		if (((unsigned char*)arr)[i] == (unsigned char)c)
			return ((void*)(arr + i));
	}
	return (NULL);
}
