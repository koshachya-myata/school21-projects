/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:50:46 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/31 12:44:39 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)dest)[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
