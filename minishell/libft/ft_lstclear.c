/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:31:57 by tcider            #+#    #+#             */
/*   Updated: 2020/10/30 17:51:47 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = *lst;
	while (tmp)
	{
		del(tmp->content);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
