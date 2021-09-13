/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcider_vaztar_adapter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:04:54 by tcider            #+#    #+#             */
/*   Updated: 2021/07/11 19:05:29 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"
#include "vaztar.h"

static	int	get_pipes_num(t_token *token)
{
	int		i;

	i = 1;
	while (token)
	{
		if (token->pipe == 1)
			i += 1;
		token = token->next;
	}
	return (i);
}

static	int	exec_pipes(t_token *token, char **envpv) //FIXME norm
{
	t_commands	*rt;
	t_command	*c;
	int			i;
	int			pipe;

	rt = (t_commands*)malloc(sizeof(t_commands));
	if (!rt)
		return (1);
	rt->len = get_pipes_num(token);
	rt->envpv = envpv;
	i = 0;
	rt->commands = (t_command*)malloc(sizeof(t_command) * rt->len);
	if (!rt->commands)
		return (1);
	while (i < rt->len)
	{
		c = &(rt->commands[i]);
		c->argv = ft_split(token->cmd, ' ');
		c->command = (c->argv)[0];
		c->envpv = envpv;
		c->in = 0;
		c->out = 1;
		while (token && token->next)
		{
			pipe = token->pipe;
			token = token->next;
			if (pipe == 2)
				c->in = open(token->cmd, O_RDONLY);
			else if (pipe == 3)
				c->out = open(token->cmd, O_WRONLY|O_TRUNC|O_CREAT,S_IREAD|S_IWRITE);
			else if (pipe == 1)
				break ;
		}
		i += 1;
	}
	printf("Return: %d\n", command_handler(rt));// FIXME можно сделать чтобы возращал 1 при ош
	// free(rt) free(rt->commands) free(tr->commands->argv) и все!
	return (0);
}

int		exec_command(t_data *data)
{
	t_token *tmp;
	t_list	*token_list;

	token_list = data->token_list;
	while (token_list)
	{
		tmp = (t_token *)(token_list->content);
		if (!ft_strlen(tmp->cmd))
			break ;
		if (exec_pipes(tmp, data->char_env))
			return (1);
		token_list = token_list->next;
	}
	return (0);
}
