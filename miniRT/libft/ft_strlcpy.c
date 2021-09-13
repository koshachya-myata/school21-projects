/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:51:11 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/04 13:32:21 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	if (!dst || !dstsize)
		return (ft_strlen(src));
	if (ft_strlen(src) < dstsize)
		dstsize = ft_strlen(src) + 1;
	i = 0;
	while (i < dstsize - 1)
	{
		dst[i] = src[i];
		if (dst[i] == '\0')
			break ;
		i++;
	}
	if (dstsize != 0 && i == dstsize - 1)
		dst[i] = '\0';
	return (ft_strlen(src));
}
