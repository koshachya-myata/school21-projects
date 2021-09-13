/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:38:42 by tcider            #+#    #+#             */
/*   Updated: 2020/10/29 15:41:49 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s1);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}
