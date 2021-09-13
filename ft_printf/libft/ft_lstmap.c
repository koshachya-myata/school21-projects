/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:34:33 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/03 16:22:43 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*el;

	if (!f || !lst)
		return (NULL);
	res = NULL;
	while (lst)
	{
		el = ft_lstnew(f(lst->content));
		if (!el)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, el);
		lst = lst->next;
	}
	return (res);
}
