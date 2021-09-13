/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:56:16 by tcider            #+#    #+#             */
/*   Updated: 2021/07/07 18:28:22 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcider.h"

int	put_intchar(int c)
{
	return (write(1, &c, 1));
}

void	init_terminal(struct termios *term, t_data *data)
{
	char	*term_name;

	term_name = getenv("TERM");
	if (!term_name)
		term_name = "xterm-256color";
	tcgetattr(0, term);
	data->lflag = term->c_lflag;
	data->vmin = term->c_cc[VMIN];
	data->vtime = term->c_cc[VTIME];
	data->term_name = term_name;
}

void	run_terminal(struct termios *term, t_data *data)
{
	struct winsize	win;

	ft_putstr_fd(PROMPT, 1);
	tcgetattr(0, term);
	term->c_lflag &= ~(ECHO);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, term);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tgetent(0, data->term_name) == -1)
		exit(1);
	tputs(save_cursor, 1, put_intchar);
	data->cursor = 0;
	data->width = win.ws_col;
}

static int	clear_word(void)
{
	tputs(tigetstr("rc"), 1, put_intchar);
	tputs(tigetstr("ed"), 1, put_intchar);
	return (0);
}

void	terminal_read(char *buf, t_data *data)
{
	int		ret;
	
	ret = read(0, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!ft_strcmp(buf, "\e[A") && !clear_word())
		history_prev(data);
	else if (!ft_strcmp(buf, "\e[B") && !clear_word())
		history_next(data);
	else if (!ft_strcmp(buf, "\e[D"))
		history_left(data);
	else if (!ft_strcmp(buf, "\e[C"))
		history_right(data);
	else if (!ft_strcmp(buf, "\x7f"))
		history_bksp(data);
	else if (!ft_strcmp(buf, "\e[3~"))
		history_del(data);
	else if (!ft_strcmp(buf, "\f") && !history_pass(data))
		terminal_clearscr(data);
	else if (!ft_strcmp(buf, "\x3") && !history_pass(data))
		terminal_clearcmd(data);
	else if (!ft_strcmp(buf, "\x1C"))
		exit(data_free(data));
	else if (ft_strcmp(buf, "\t"))
		history_add(data, buf, ret);
}
