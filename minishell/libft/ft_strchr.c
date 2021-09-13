/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:08:25 by tcider            #+#    #+#             */
/*   Updated: 2020/11/29 22:16:49 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = -1;
	ch = (char)c;
	while (s[++i])
		if (s[i] == ch)
			return ((char*)&s[i]);
	if (!c)
		return ((char*)&s[i]);
	return (NULL);
}
