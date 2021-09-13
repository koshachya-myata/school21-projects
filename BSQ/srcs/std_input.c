/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:19:19 by vaztar            #+#    #+#             */
/*   Updated: 2020/08/11 15:21:01 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

t_list	*std_create_list(char *data, int size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	list->next = NULL;
	list->data = data;
	list->size = size;
	return (list);
}

void	std_add_list(t_queue *list, char *data, int size)
{
	if (!list->begin_list)
	{
		list->begin_list = std_create_list(data, size);
		list->size = size;
		list->end_list = list->begin_list;
		return ;
	}
	(list->end_list)->next = std_create_list(data, size);
	list->end_list = (list->end_list)->next;
	list->size += size;
}

char	*std_concat_buf(t_queue *list)
{
	t_list	*tmp_list;
	char	*str;
	int		i;
	int		j;

	if (!list->begin_list)
		return (NULL);
	tmp_list = list->begin_list;
	str = (char*)malloc(sizeof(char) * (list->size + 1));
	j = -1;
	while (list->begin_list)
	{
		i = -1;
		while (++i < (list->begin_list)->size)
			str[++j] = ((list->begin_list)->data)[i];
		free((list->begin_list)->data);
		tmp_list = (list->begin_list)->next;
		free(list->begin_list);
		list->begin_list = tmp_list;
	}
	free(list);
	str[++j] = '\0';
	return (str);
}

int		std_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

char	*std_input(int fd)
{
	char	*buf;
	t_queue	*list;
	int		size;

	if (fd == -1)
		return (NULL);
	list = (t_queue*)malloc(sizeof(t_queue));
	list->begin_list = NULL;
	list->size = 0;
	while ((buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))) &&
			(size = read(fd, buf, BUF_SIZE)))
	{
		if (size == -1)
			return (NULL);
		buf[size] = '\0';
		std_add_list(list, buf, size);
	}
	free(buf);
	return (std_concat_buf(list));
}
