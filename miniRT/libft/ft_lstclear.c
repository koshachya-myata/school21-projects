/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:15:54 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/02 16:30:58 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;

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
