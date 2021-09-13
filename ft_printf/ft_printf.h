/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:18:27 by vaztar            #+#    #+#             */
/*   Updated: 2020/12/18 19:15:37 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_ptf
{
	char		space;
	long long	width;
	int			is_sp_left;
	char		*inp;
	int			rt;
	long long	limit;
	int			is_dot;
	int			limit_minus;
	int			width_minus;
	int			limit_opr;
	int			width_opr;
}				t_ptf;

int				ft_printf(const char *inp, ...);
void			put_i(t_ptf *ptf, long long num);
int				put_s(t_ptf *ptf, char *str);
int				put_c(t_ptf *ptf, char c);
void			put_x(t_ptf *ptf, unsigned long long num, char start_10);
void			put_u(t_ptf *ptf, unsigned long num);
void			put_p(t_ptf *ptf, unsigned long long num);
void			put_w(t_ptf *ptf, char c);
int				put_percent(t_ptf *ptf);

void			set_space(t_ptf *ptf, long long limit);
int				put_null(t_ptf *ptf);
long long		min(long long a, long long b);
void			putstr_limit(t_ptf *ptf, char *str);
void			ft_putnbr(long long n);
long long		max(long long a, long long b);
void			putzero(t_ptf *ptf, int len, int sign);
void			print_hex(unsigned long long num, char start_10);
long long		num_len(long long num, int x);
long long		uns_num_len(unsigned long long num, int x);

int				parse(t_ptf *ptf, const char *inp, va_list *argptr, int *i);
int				get_width(t_ptf *ptf, const char *inp, int *i);
int				get_limit(t_ptf *ptf, const char *inp, int *i);

#endif
