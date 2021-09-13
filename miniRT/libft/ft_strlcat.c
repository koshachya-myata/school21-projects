/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:48:20 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/31 16:00:16 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	len2;

	len = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size > len + len2)
		size = len + len2 + 1;
	i = 0;
	if (size <= len)
		return (size + len2);
	while (len + i < size - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + len2);
}
