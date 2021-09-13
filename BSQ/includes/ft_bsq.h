/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:48 by tcider            #+#    #+#             */
/*   Updated: 2020/08/12 11:51:40 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUF_SIZE 4000

typedef struct	s_result
{
	int			i;
	int			j;
	int			size;
}				t_result;

typedef struct	s_list
{
	int				size;
	char			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_queue
{
	t_list	*begin_list;
	t_list	*end_list;
	int		size;
}				t_queue;

char			*std_input(int fd);
int				**bsq_input(char *str, int *size, char *symb);
int				std_file(char *file);
int				ft_atoi(char *str, int len);
void			ft_putstr(char *str);
int				ft_min(int x, int y, int z);
void			std_add_list(t_queue *list, char *data, int size);
char			*std_concat_buf(t_queue *list);
int				ft_take_num(char *str);
int				line_len(char *str);

#endif
