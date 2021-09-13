/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:28:22 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/04 20:01:30 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static int	wordlen(char const *s, char c)
{
	int z;

	z = 0;
	while (s[z] && s[z] != c)
		z++;
	return (z);
}

char		*new_str(const char *s, char c)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(str = (char*)malloc(wordlen(s, c) + 1)))
		return (NULL);
	while (s[j] && s[j] != c)
	{
		str[++i] = s[j];
		j++;
	}
	str[++i] = '\0';
	return (str);
}

static int	fill_tab(char **tab, char const *s, char c)
{
	int i;
	int len;
	int z;

	i = -1;
	z = 0;
	len = word_count(s, c);
	while (++i < len && s[z])
	{
		while (s[z] == c)
			z++;
		if (!s[z])
			break ;
		if (!(tab[i] = new_str(s + z, c)))
		{
			while (i--)
				free(tab[i]);
			free(tab);
			return (0);
		}
		while (s[z] && s[z] != c)
			z++;
	}
	tab[i] = NULL;
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char **tab;

	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc((word_count(s, c) + 1) * sizeof(char*))))
		return (NULL);
	if (fill_tab(tab, s, c))
		return (tab);
	return (NULL);
}
