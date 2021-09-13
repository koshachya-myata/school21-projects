/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:57:47 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/03 16:50:40 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_symb_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	long	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = (long)ft_strlen(s1) - 1;
	while (s1[i] && is_symb_in_set(s1[i], set))
		i++;
	while (j >= 0 && is_symb_in_set(s1[j], set))
		j--;
	if (j < 0)
	{
		str = (char*)malloc(1);
		str[0] = '\0';
		return (str);
	}
	return (ft_substr(s1, i, j - i + 1));
}
