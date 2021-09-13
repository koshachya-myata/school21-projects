/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:16:50 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/31 10:38:30 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char*)(s + len));
		len--;
	}
	if (!c)
		return ((char*)(s + ft_strlen(s)));
	return (NULL);
}
