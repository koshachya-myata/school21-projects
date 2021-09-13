/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:58:43 by tcider            #+#    #+#             */
/*   Updated: 2021/07/07 18:44:13 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

void	history_bksp(t_data *data)
{
	if (data->cursor)
	{
		tputs(tgetstr("le", 0), 1, put_intchar);
		tputs(tgetstr("dc", 0), 1, put_intchar);
		del_c_instr(&(data->history->content), data->cursor - 1);
		data->cursor -= 1;
	}
}

static char	*history_join(t_data *data, char *str, int len)
{
	char	*res;

	if (!(data->history->content))
		exit(data_free(data));
	write(1, str, len);
	res = ft_strjoin(data->history->content, str);
	free(data->history->content);
	data->history->content = res;
	data->cursor = ft_strlen(data->history->content);
	return (res);
}

void	history_add(t_data *data, char *buf, int ret)
{
	int		start;
	int		end;
	char	*str;
	struct	termios	term;

	start = 0;
	end = -1;
	while (++end < ret && data->history->content)
		if (buf[end] == '\n')
		{
			buf[end] = '\0';
			str = history_join(data, &buf[start], end - start);
			if (ft_strlen(str) && !history_write(data))
				data->current = history_new(data);
			else
				write(1, "\n", 1);
			restore_terminal(&term, data);
			parser_main(str, data);
			run_terminal(&term, data); 
			start = end + 1;
		}
	if (start < ret && data->cursor == (int)ft_strlen(data->history->content))
		history_join(data, &buf[start], ret - start);
	if (start < ret && data->cursor < (int)ft_strlen(data->history->content))
		history_insert(data, &buf[start], ret - start);
}

void	history_del(t_data *data)
{
	if (data->cursor < (int)ft_strlen(data->history->content))
	{
		tputs(tgetstr("dc", 0), 1, put_intchar);
		del_c_instr(&(data->history->content), data->cursor);
	}
}
