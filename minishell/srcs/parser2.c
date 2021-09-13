/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:12:17 by tcider            #+#    #+#             */
/*   Updated: 2021/06/01 11:15:00 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

char	*parser_trim(char *str)
{
	char		*res;

	res = ft_strtrim(str, " \t");
	free(str);
	return (res);
}

void	parser_clear_token(void *token)
{
	t_token *tmp;
	t_token	*tmp2;

	tmp = (t_token *)token;
	while (tmp)
	{
		tmp2 = tmp->next;
		manual_free(tmp->cmd);
		free(tmp);
		tmp = tmp2;
	}
}

int	parser_exit(t_list **token_list, char *msg, int err)
{
	if (token_list)
		ft_lstclear(token_list, parser_clear_token);
	if (ft_strlen(msg))
		ft_putstr_fd(msg, 1);
	else
		ft_putstr_fd("Error", 1);
	ft_putchar_fd('\n', 1);
	return (err);
}

t_token	*parser_new_token(char *cmd, char *pipe)
{
	t_token	*res;
	int		intpipe;

	if (!cmd)
		return (NULL);
	cmd = parser_trim(cmd);
	res = (t_token *)malloc(sizeof(t_token));
	intpipe = 0;
	if (res)
	{
		if (*pipe == '|')
			intpipe = 1;
		else if (*pipe == '<')
			intpipe = 2;
		else if (*pipe == '>' && *(pipe + 1) != '>')
			intpipe = 3;
		else if (*pipe == '>' && *(pipe + 1) == '>')
			intpipe = 4;
		res->cmd = cmd;
		res->pipe = intpipe;
		res->next = NULL;
	}
	return (res);
}

int		parser_add_token(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (!new)
		return (1);
	tmp = *lst;
	if (!tmp)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}
