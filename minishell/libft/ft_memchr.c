/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:28:06 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 11:57:13 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = c;
	while (i < n)
	{
		if (((const unsigned char*)s)[i] == ch)
			return ((void*)&((const unsigned char*)s)[i]);
		i++;
	}
	return (NULL);
}
