/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:02:51 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 17:22:20 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	char		*res;
	size_t		i;

	s1_len = 0;
	s2_len = 0;
	i = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			res[i] = s1[i];
		else
			res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = '\0';
	return (res);
}
