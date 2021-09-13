/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:27:58 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 15:37:24 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	if (!(res = (unsigned char*)malloc(count * size)))
		return (NULL);
	while (i < count * size)
	{
		res[i] = 0;
		i++;
	}
	return ((void*)res);
}
