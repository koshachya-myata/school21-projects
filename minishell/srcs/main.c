/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:33:23 by tcider            #+#    #+#             */
/*   Updated: 2021/07/06 14:41:26 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

int manual_free(char *str)
{
	if (str)
		free(str);
	return (0);
}

int	data_free(t_data *data)
{
	int		res;
	struct termios	term;

	res = 0;
	if (!data->env || !data->history || !data->history->content)
	{
		res = 1;
		ft_putstr_fd("Malloc error!\n", 2);
	}
	if (data->env)
		ft_lstclear(&(data->env), env_free);
	if (data->history)
		history_free(data->history);
	restore_terminal(&term, data);
	return (res);
}

int		main(int argc, char **argv, char **env)
{
	char	buf[BUF_SIZE + 1];
	struct	termios	term;
	t_data	data;

	if (argc > 1)
	{
		ft_putstr_fd("Too many arguments\n", 2);
		return (1);
	}
	argv = NULL;
	data.env = get_env(env);
	data.char_env = env;
	data.history = NULL;
	data.current = history_new(&data);
	init_terminal(&term, &data);
	if (!(data.env) || !(data.current))
		return (data_free(&data));
	run_terminal(&term, &data); 
	ft_bzero(buf, BUF_SIZE);
	while (ft_strcmp(buf, "\004") && (data.history)->content)
		terminal_read(buf, &data);
	return (data_free(&data));
}
