/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:54:36 by vaztar            #+#    #+#             */
/*   Updated: 2021/04/07 17:42:45 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dst, const char *src);

int		ft_strcmp(const char *s1, const char *s2);

ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

char	*ft_strdup(const char *s1);
#endif
