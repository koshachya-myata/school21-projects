/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:03:15 by tcider            #+#    #+#             */
/*   Updated: 2020/10/30 12:29:08 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nwords(const char *tmp, char c)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (tmp[i])
	{
		if (tmp[i] != c)
		{
			sum++;
			while (tmp[i] && tmp[i] != c)
				i++;
		}
		else
			i++;
	}
	return (sum);
}

static char		*ft_getchar(const char *str, char c)
{
	char	*res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (k < i)
	{
		res[k] = str[k];
		k++;
	}
	res[k] = '\0';
	return (res);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		nwords;
	char	**res;

	if (s)
		nwords = ft_nwords(s, c);
	if (!s || !(res = (char**)malloc(sizeof(char*) * (nwords + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res[k] = ft_getchar(&s[i], c);
			k++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	res[k] = NULL;
	return (res);
}
