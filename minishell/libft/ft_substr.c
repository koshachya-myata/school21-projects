/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:38:39 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 17:23:54 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = 0;
	if (s)
		s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len && s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
