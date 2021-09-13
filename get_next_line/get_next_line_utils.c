/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:57:19 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/18 19:29:06 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s, int f)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	if (f)
		free(s);
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	long	strlen1;
	long	i;
	long	strlen2;

	if (!s1 || !s2)
		return ((!s1) ? (char*)s2 : (char*)s1);
	strlen1 = (long)ft_strlen(s1);
	strlen2 = (long)ft_strlen(s2);
	if (!(str = (char*)malloc((strlen1 + strlen2 + 1))))
		return (NULL);
	i = -1;
	while (++i < strlen1)
		str[i] = s1[i];
	i = -1;
	while (++i < strlen2)
		str[strlen1 + i] = s2[i];
	str[strlen1 + strlen2] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = -1;
	while (++i < len)
		if (s[i] == (char)c)
			return ((char*)(s + i));
	if (!c)
		return ((char*)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	lenstr;

	if (!s || !(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	lenstr = ft_strlen(s);
	if (start >= lenstr)
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
