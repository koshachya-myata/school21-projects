/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:58:43 by tcider            #+#    #+#             */
/*   Updated: 2021/05/09 17:09:41 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

t_dlist *history_new(t_data *data)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->next = data->history;
	new->prev = NULL;
	if (data->history)
		new->prev = data->history->prev;
	new->content = (char *)malloc(sizeof(char));
	if (!(new->content))
		return (NULL);
	(new->content)[0] = '\0';
	if (data->history)
	{
		if (data->history->prev)
			data->history->prev->next = new;
		data->history->prev = new;
	}
	data->history = new;
	data->cursor = 0;
	return (new);
}

void	history_prev(t_data *data)
{
	int		size;

	if (data->history->next)
		data->history = data->history->next;
	if (data->history->content)
	{
		size = ft_strlen(data->history->content);
		write(1, data->history->content, size);
	}
	data->cursor = ft_strlen(data->history->content);
}

void	history_next(t_data *data)
{
	int		size;

	if (data->history->prev)
		data->history = data->history->prev;
	if (data->history->content)
	{
		size = ft_strlen(data->history->content);
		write(1, data->history->content, size);
	}
	data->cursor = ft_strlen(data->history->content);
}

int		history_write(t_data *data)
{
	if (data->current != data->history)
	{
		free(data->current->content);
		data->current->content = ft_strdup(data->history->content);
		if (!(data->current->content))
			exit(data_free(data));
		data->history = data->current;
	}
	write(1, "\n", 1);
	return (0);
}

void	history_free(t_dlist *history)
{
	t_dlist *tmp;

	while (history->prev)
		history = history->prev;
	while (history)
	{
		tmp = history->next;
		if (history->content)
			free(history->content);
		free(history);
		history = tmp;
	}
}	
