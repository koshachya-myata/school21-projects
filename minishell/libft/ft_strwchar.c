/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:21:51 by tcider            #+#    #+#             */
/*   Updated: 2020/12/03 12:38:05 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_wchar(int c, char *str)
{
	int		i;

	i = -1;
	if (c <= 0x100)
		str[++i] = c;
	else if (c < 0x0800)
	{
		str[++i] = ((c >> 6) & 0x1F) | 0xC0;
		str[++i] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (c < 0x010000)
	{
		str[++i] = ((c >> 12) & 0x0F) | 0xE0;
		str[++i] = ((c >> 6) & 0x3F) | 0x80;
		str[++i] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (c < 0x110000)
	{
		str[++i] = ((c >> 18) & 0x07) | 0xF0;
		str[++i] = ((c >> 12) & 0x3F) | 0x80;
		str[++i] = ((c >> 6) & 0x3F) | 0x80;
		str[++i] = ((c >> 0) & 0x3F) | 0x80;
	}
	return (i + 1);
}

/*
** strwchar doesn't put \0 at the end
** thats why *size is important to have
*/

char		*ft_strwchar(int c, int *size)
{
	char	str[4];
	char	*res;

	*size = get_wchar(c, str);
	if (!(res = (char*)malloc(sizeof(char) * (*size))))
		return (NULL);
	ft_memcpy(res, str, *size);
	return (res);
}
