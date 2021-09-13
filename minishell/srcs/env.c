/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:08:26 by tcider            #+#    #+#             */
/*   Updated: 2021/07/07 20:22:08 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

static t_env	*make_env(char *name, char *value)
{
	t_env	*res;

	res = (t_env*)malloc(sizeof(t_env));
	if (!res)
		return (NULL);
	res->name = name;
	res->value = value;
	return (res);
}

void	env_free(void *elem)
{
	manual_free(((t_env *)elem)->name);
	((t_env *)elem)->name = NULL;
	manual_free(((t_env *)elem)->value);
	((t_env *)elem)->value = NULL;
	free((t_env *)elem);
}

t_list			*get_env(char **env)
{
	t_list	*res;
	t_list	*list_elem;
	t_env	*env_elem;
	char	*name;
	char	*value;

	res = NULL;
	value = NULL;
	while (*env)
	{
		name = ft_substr(*env, 0, ft_strchr(*env, '=') - *env);
		value = ft_strdup(ft_strchr(*env, '=') + 1);
		env_elem = make_env(name, value);
		if ((!name || !value || !env_elem) && \
			!manual_free(name) && !manual_free(value))
			return (NULL);
		list_elem = ft_lstnew(env_elem);
		if (!list_elem)
			ft_lstclear(&res, env_free);
		ft_lstadd_back(&res, list_elem);
		env++;
	}
	return (res);
}

void			print_env(t_list *env_list)
{
	while (env_list)
	{
		printf("%s = %s\n", ((t_env *)env_list->content)->name, \
			((t_env *)env_list->content)->value);
		env_list = env_list->next;
	}
}

char	*read_env_value(char *name, t_list *env_list)
{
	while (env_list)
	{
		if (!ft_strcmp(name, ((t_env *)env_list->content)->name))
			return (((t_env *)env_list->content)->value);
		env_list = env_list->next;
	}
	return (NULL);
}
