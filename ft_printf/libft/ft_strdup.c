/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:00:43 by vaztar            #+#    #+#             */
/*   Updated: 2020/10/30 20:36:01 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	if (!(str = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s))
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
