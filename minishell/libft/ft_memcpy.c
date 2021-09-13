/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:35:04 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 11:53:21 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dst_tmp;
	const unsigned char		*src_tmp;

	if (!dst && !src)
		return (NULL);
	dst_tmp = dst;
	src_tmp = src;
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}
