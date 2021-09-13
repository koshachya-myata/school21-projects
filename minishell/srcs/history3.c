/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:18:28 by tcider            #+#    #+#             */
/*   Updated: 2021/05/09 17:13:00 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

void	history_left(t_data *data)
{
	if (data->cursor)
	{
		tputs(tgetstr("le", 0), 1, put_intchar);
		data->cursor -= 1;
	}
	else
		tputs(tigetstr("rc"), 1, put_intchar);
}

void	history_right(t_data *data)
{
	if (data->cursor < (int)ft_strlen(data->history->content))
	{
		tputs(tgetstr("nd", 0), 1, put_intchar);
		data->cursor += 1;
	}
}

void	history_insert(t_data *data, char *str, int len)
{
	char	*res;
	char	*str1;
	char	*str2;

	str1 = NULL;
	if (data->cursor > 0)
		str1 = ft_substr(data->history->content, 0, data->cursor);
	str2 = ft_strdup(&((data->history->content)[data->cursor]));
	res = ft_strjoin(str1, str);
	if (str1)
		free(str1);
	str1 = ft_strjoin(res, str2);
	if (!res || !str1 || !str2)
		exit(data_free(data));
	if (res)
		free(res);
	free(data->history->content);
	data->history->content = str1;
	data->cursor += len;
	write(1, str, len);
	tputs(save_cursor, 1, put_intchar);
	write(1, str2, ft_strlen(str2));
	tputs(tigetstr("rc"), 1, put_intchar);	
	free(str2);
}

int	history_pass(t_data *data)
{
	if (ft_strlen(data->history->content))
		data->current = history_new(data);
	return 0;
}
