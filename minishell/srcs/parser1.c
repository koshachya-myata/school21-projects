/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:12:17 by tcider            #+#    #+#             */
/*   Updated: 2021/07/07 20:27:04 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

static t_token	*parser_split_token(char *str)
{
	t_token	*token;
	t_token *new;
	char	*tmp;
	int		start;
	int		end;

	start = 0;
	end = 1;
	token = NULL;
	while (str[end - 1])
	{
		if (ft_strchr("|<>", str[end]) || !str[end])
		{
			tmp = ft_substr(str, start, end - start);
			tmp = parser_trim(tmp);
			new = parser_new_token(tmp, &str[end]);
			if (parser_add_token(&token, new))
				return (NULL);
			start = end + 1 + new->pipe / 4;
			end = start;
		}
		else
			end++;
	}
	return (token);
}

static int	parser_split(t_list **token_list, char *str)
{
	char	**res;
	t_list	*list;
	t_token *token;
	int		i;

	if (check_semicolon(str))
		return (1);
	res = ft_split(str, ';');
	i = -1;
	while (res[++i])
	{
		if (check_pipe(res[i]))
			return (1);
		token = parser_split_token(res[i]);
		if (!token)
			return (1);
		list = ft_lstnew(token);
		if (!list)
			return (1);
		ft_lstadd_back(token_list, list);
		free(res[i]);
	}
	free(res);
	return (0);
}

static int str_insert_str(char **dest, int i, char *src)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = ft_substr((*dest), 0, i);
	tmp2 = ft_strdup(&((*dest)[i]));
	if (src)
		tmp3 = ft_strjoin(tmp1, src);
	else
		tmp3 = ft_strdup(tmp1);
	if (!tmp3)
		return (1);
	manual_free(tmp1);
	tmp1 = ft_strjoin(tmp3, tmp2);
	if (!tmp1)
		return (1);
	manual_free(*dest);
	manual_free(tmp2);
	manual_free(tmp3);
	*dest = tmp1;
	return (0);
}

static int	set_env(char **str, t_list *env)
{
	int		i;
	int		j;
	int		k;
	char	buf[STACK_SIZE];

	i = -1;
	k = -1;
	while (++i < (int)ft_strlen(*str))
		if ((*str)[i] == '$' && (*str)[i + 1] && (*str)[i + 1] != ' ' && (*str)[i + 1] != '$')
		{
			j = -1;
			del_c_instr(str, i);
			while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '$')
			{
				buf[++j] = (*str)[i];
				del_c_instr(str, i);
				if (!(*str))
					return (1);
			}
			buf[++j] = '\0';
			if (str_insert_str(str, i, read_env_value(buf, env)))
				return (1);

		}
	return (0);
}

void	parser_main(char *str, t_data *data)
{
	char	*str2;
	t_list	*token_list;

	token_list = NULL;
	str2 = ft_strdup(str);
	if (!str2 || remove_quotes(&str2) || set_env(&str2, data->env) || \
			parser_split(&token_list, str2))
		parser_exit(&token_list, "Syntax error", 1);
	data->token_list = token_list;
	if (exec_command(data))
		parser_exit(&token_list, "Execution error", 1);
	ft_lstclear(&token_list, parser_clear_token);
}
