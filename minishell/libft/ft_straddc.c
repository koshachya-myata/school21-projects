/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:07:49 by tcider            #+#    #+#             */
/*   Updated: 2020/11/26 12:56:07 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_straddc(char **s, char c)
{
	size_t		s_len;
	char		*res;
	size_t		i;

	s_len = 0;
	i = 0;
	if (*s)
		s_len = ft_strlen(*s);
	if (!(res = malloc(sizeof(char) * (s_len + 2))))
	{
		if (*s)
			free(*s);
		*s = NULL;
	}
	while (i < s_len)
	{
		res[i] = (*s)[i];
		i++;
	}
	res[i] = c;
	res[++i] = '\0';
	if (*s)
		free(*s);
	*s = res;
}
