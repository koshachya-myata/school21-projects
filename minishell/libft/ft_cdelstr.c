/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdelstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:56:12 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 11:59:57 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_cdelstr(char **s)
{
	size_t		s_len;
	char		*res;
	size_t		i;

	s_len = 0;
	i = 1;
	if (*s)
		s_len = ft_strlen(*s);
	if (s_len < 1 || !(res = malloc(sizeof(char) * s_len)))
	{
		if (*s)
			free(*s);
		*s = NULL;
	}
	while (i < s_len)
	{
		res[i - 1] = (*s)[i];
		i++;
	}
	res[i - 1] = '\0';
	if (*s)
		free(*s);
	*s = res;
}
