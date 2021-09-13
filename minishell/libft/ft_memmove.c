/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:48:35 by tcider            #+#    #+#             */
/*   Updated: 2020/11/02 11:23:08 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if ((unsigned char*)dst < (unsigned char*)src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}
