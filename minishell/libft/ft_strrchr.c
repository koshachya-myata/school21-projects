/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:21:49 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 13:25:56 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;
	int		tmp;

	i = -1;
	tmp = -1;
	ch = (char)c;
	while (s[++i])
		if (s[i] == ch)
			tmp = i;
	if (tmp != -1)
		return ((char*)&s[tmp]);
	if (!c)
		return ((char*)&s[i]);
	return (NULL);
}
