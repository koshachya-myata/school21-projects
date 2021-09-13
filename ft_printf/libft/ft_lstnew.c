/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:45:29 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/02 16:48:49 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
