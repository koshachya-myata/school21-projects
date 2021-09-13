/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:48:47 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/04 19:38:45 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	int	i;
	int	j;
	int	f;

	if (!*ned)
		return ((char*)hay);
	i = 0;
	while (i < (int)len && hay[i])
	{
		f = 1;
		j = 0;
		while (i + j < (int)len && j < (int)ft_strlen(ned) && f)
		{
			if (hay[i + j] != ned[j])
				f = 0;
			j++;
		}
		if (f && j == (int)ft_strlen(ned))
			return ((char*)(hay + i));
		i++;
	}
	return (NULL);
}
