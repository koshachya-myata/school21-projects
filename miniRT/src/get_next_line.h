/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:27:34 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/24 18:58:51 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
char	*gnl_ft_strdup(char *s, int f);
char	*gnl_ft_strjoin(char *s1, char const *s2);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);

#endif
