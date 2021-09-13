/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:25:16 by tcider            #+#    #+#             */
/*   Updated: 2021/05/28 21:34:14 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_len;
	int		i;
	int		j;

	s1_len = 0;
	i = 0;
	if (s1)
		s1_len = (int)ft_strlen(s1);
	j = s1_len - 1;
	while (set && i < s1_len && ft_strchr(set, s1[i]))
		i++;
	while (set && j >= 0 && ft_strchr(set, s1[j]))
		j--;
	if (j < 0 || i > j)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, (unsigned int)i, (size_t)(j - i + 1)));
}
