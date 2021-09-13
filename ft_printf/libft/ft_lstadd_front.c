/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:57:46 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/02 16:20:16 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		t = *lst;
		new->next = t;
		*lst = new;
	}
}
