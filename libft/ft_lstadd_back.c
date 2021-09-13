/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:57:09 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/03 16:54:54 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *t;

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
