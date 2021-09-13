/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstobj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:27:19 by vaztar            #+#    #+#             */
/*   Updated: 2021/02/25 14:19:44 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objlst	*ft_objnew(void *content, short type)
{
	t_objlst *res;

	if (!(res = (t_objlst*)malloc(sizeof(t_objlst))))
		return (NULL);
	res->content = content;
	res->next = NULL;
	res->obj_type = type;
	return (res);
}

void		ft_objclear(t_objlst **lst, void (*del)(void*))
{
	t_objlst	*t;

	if (lst && *lst)
	{
		while (*lst)
		{
			t = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = t;
		}
	}
	lst = NULL;
}

void		ft_objadd_back(t_objlst **lst, t_objlst *new)
{
	t_objlst *t;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		t = *lst;
		while (t->next)
			t = t->next;
		t->next = new;
	}
}
