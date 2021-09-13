/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:23:50 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/31 14:08:06 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*s;

	if (!dst && !src)
		return (NULL);
	dest = (char*)dst;
	s = (char*)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		dest[len - 1] = s[len - 1];
		len--;
	}
	return (dst);
}
