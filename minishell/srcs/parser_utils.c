/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:09:19 by tcider            #+#    #+#             */
/*   Updated: 2021/05/10 20:16:12 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

void	del_c_instr(char **str, int pos)
{
	char	*str1;
	char	*str2;
	char	*res;

	str1 = NULL;
	str2 = NULL;
	if (pos > 0)
	{
		str1 = ft_substr(*str, 0, pos);
		if (!str1)
			return ;
	}
	if (pos < (int)ft_strlen(*str) - 1)
	{
		str2 = ft_strdup(&((*str)[pos + 1]));
		if (!str2)
			return ;
	}
	res = ft_strjoin(str1, str2);
	manual_free(str1);
	manual_free(str2);
	manual_free(*str);
	*str = res;
}

int		remove_quotes(char **str)
{
	int		i;
	int		j;
	char	buf[STACK_SIZE];

	i = -1;
	j = -1;
	while (++j < (int)ft_strlen(*str))
		if ((*str)[j] == '\'' || (*str)[j] == '\"')
		{
			if (i >= 0 && buf[i] == (*str)[j])
				i -= 1;
			else
				buf[++i] = (*str)[j];
			del_c_instr(str, j);
			if (!(*str))
				return (1);
		}
	if (i != -1)
		return (1);
	return (0);
}

int	check_semicolon(char *str)
{
	int		flag;

	flag = 1;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != ';')
			flag = 0;
		else if (*str == ';')
		{
			if (flag)
				return (1);
			str++;
			while (*str && (*str == ' ' || *str == '\t'))
				str++;
			if (*str && *str == ';')
				return (1);
			if (!*str)
				return (0);
		}
		str++;
	}
	return (0);
}

static int	str_is_pipe(char *str)
{
	if (*str == '|' || *str == '<' || *str == '>')
	{
		if (*(str + 1) == '>')
			return (2);
		return (1);
	}
	return (0);
}

int	check_pipe(char *str)
{
	int		flag;
	int		i;

	flag = 1;
	while (*str)
	{
		i = str_is_pipe(str);
		if (!i)
			flag = 0;
		else
		{
			if (flag)
				return (1);
			str += i;
			while (*str && (*str == ' ' || *str == '\t'))
				str++;
			if (!*str || str_is_pipe(str))
				return (1);
		}
		str++;
	}
	return (0);
}
