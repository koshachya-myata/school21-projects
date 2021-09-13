/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:56:16 by tcider            #+#    #+#             */
/*   Updated: 2021/05/09 17:07:32 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

void	restore_terminal(struct termios *term, t_data *data)
{
	tcgetattr(0, term);
	term->c_lflag = data->lflag;
	tcsetattr(0, TCSANOW, term);
	term->c_cc[VMIN] = data->vmin;
	term->c_cc[VTIME] = data->vtime;
	tgetent(0, data->term_name);
}

void	terminal_clearscr(t_data *data)
{
	tputs(tgetstr("cl", 0), 1, put_intchar);
	ft_putstr_fd(PROMPT, 1);
	tputs(save_cursor, 1, put_intchar);
	data->cursor = 0;
}

void	terminal_clearcmd(t_data *data)
{
	write(1, "\n", 1);
	ft_putstr_fd(PROMPT, 1);
	tputs(save_cursor, 1, put_intchar);
	data->cursor = 0;
}
