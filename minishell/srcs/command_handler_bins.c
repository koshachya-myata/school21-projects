/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler_bins.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:15:14 by vaztar            #+#    #+#             */
/*   Updated: 2021/07/11 19:05:25 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vaztar.h"

int is_bin(char *path)
{
	struct stat st;
	
	if ((lstat(path, &st)) < 0)
		return 0;
	if (st.st_mode & S_IXUSR)
		return (1);
	return (0);
	// S_IXUSR	00100	владелец имеет право выполнения.
	// S_IFREG	0100000	обычный файл.

}

int	check_bin(char *b_path)
{
	char **paths;
	int	i;
	char *new_str;
	char *p;
	
	new_str = ft_strjoin("/", b_path);
	paths = get_paths();
	i = 0;
	while (paths[i] != NULL)
	{
		p = ft_strjoin(paths[i], new_str);
		if (is_bin(p))
		{
			free(p);
			free(new_str);
			return (1);
		}
		free(p);
		p = NULL;
		i++;
	}
	free(new_str);
	printf("minishell: %s command not found\n", b_path);
	return (0);
}