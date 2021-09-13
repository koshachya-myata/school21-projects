/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:24:22 by tcider            #+#    #+#             */
/*   Updated: 2020/11/30 18:29:05 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strdelc(char **s)
{
	size_t		s_len;
	char		*res;
	size_t		i;

	s_len = 0;
	i = 0;
	if (*s)
		s_len = ft_strlen(*s);
	if (s_len < 1 || !(res = malloc(sizeof(char) * s_len)))
	{
		if (*s)
			free(*s);
		*s = NULL;
	}
	while (i < s_len - 1)
	{
		res[i] = (*s)[i];
		i++;
	}
	res[i] = '\0';
	if (*s)
		free(*s);
	*s = res;
}
