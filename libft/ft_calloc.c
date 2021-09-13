/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:54:51 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/31 12:12:54 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count == 0 && size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(res = (void*)malloc(count * size)))
		return (NULL);
	return (ft_memset(res, 0, count * size));
}
