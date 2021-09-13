/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caddstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:01:47 by tcider            #+#    #+#             */
/*   Updated: 2020/11/26 12:56:41 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_caddstr(char c, char **s)
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
	res[i] = c;
	i++;
	while (i < s_len + 1)
	{
		res[i] = (*s)[i - 1];
		i++;
	}
	res[i] = '\0';
	if (*s)
		free(*s);
	*s = res;
}
