/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:14:40 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 11:58:12 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*dst_tmp;
	const unsigned char		*src_tmp;

	i = 0;
	dst_tmp = dst;
	src_tmp = src;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		if (src_tmp[i] == (unsigned char)c)
			return ((void*)&dst_tmp[i + 1]);
		i++;
	}
	return (NULL);
}
