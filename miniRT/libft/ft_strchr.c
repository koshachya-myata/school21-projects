/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:16:36 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/30 20:22:34 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s))
		if (s[i] == (char)c)
			return ((char*)(s + i));
	if (!c)
		return ((char*)(s + i));
	return (NULL);
}
