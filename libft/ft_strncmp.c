/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:07:49 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/04 19:54:02 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (!*s1 || !*s2)
		return (*((unsigned char*)s1) - *(unsigned char*)s2);
	while ((i < n) && s1[i] && s2[i])
	{
		if (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i] != 0)
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
	}
	if (i < n && (!s1[i] || !s2[i]))
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}
