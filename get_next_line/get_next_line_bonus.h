/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:27:31 by vaztar            #+#    #+#             */
/*   Updated: 2020/11/20 17:29:51 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s, int f);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
