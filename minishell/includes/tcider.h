/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcider.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:25:55 by tcider            #+#    #+#             */
/*   Updated: 2021/07/13 19:55:12 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCIDER_H
# define TCIDER_H

# include <errno.h>
# include <stdio.h>
# include <term.h>
# include <termios.h>
# include <termcap.h> //FIXME
# include "libft.h"

# define PROMPT "$> "
# define BUF_SIZE 100
# define STACK_SIZE 100

typedef struct	s_dlist
{
	char	*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct	s_token
{
	char	*cmd;
	int		pipe;
	// 0 - None
	// 1 - |
	// 2 - <
	// 3 - >
	// 4 - >>
	struct s_token	*next;
}				t_token;

typedef struct	s_env
{
	char	*name;
	char	*value;
}				t_env;

typedef struct s_data
{
	t_dlist	*history;
	t_dlist	*current;
	t_list	*env;
	t_list	*token_list;
	char	**char_env;
	int		cursor;
	int lflag;
	int	vmin;
	int	vtime;
	int	width;
	char *term_name;
}				t_data;

t_dlist	*history_new(t_data *data);
void	history_prev(t_data *data);
void	history_next(t_data *data);
int		history_write(t_data *data);
void	history_free(t_dlist *history);
void	history_bksp(t_data *data);
void	history_add(t_data *data, char *buf, int ret);
void	history_left(t_data *data);
void	history_right(t_data *data);
void	history_insert(t_data *data, char *str, int len);
void	history_del(t_data *data);
void	init_terminal(struct termios *term, t_data *data);
void	run_terminal(struct termios *term, t_data *data);
void	restore_terminal(struct termios *term, t_data *data);
void	terminal_read(char *buf, t_data *data);
int		put_intchar(int c);
void	env_free(void *env);
int		manual_free(char *str);
void	print_env(t_list *env);
t_list	*get_env(char **env);
char	*read_env_value(char *name, t_list *env_list);
int		data_free(t_data *data);
void	terminal_clearscr(t_data *data);
void	terminal_clearcmd(t_data *data);
int		history_pass(t_data *data);

void	parser_main(char *str, t_data *data);
void	parser_clear_token(void *token);
void	del_c_instr(char **str, int pos);
int		check_semicolon(char *str);
int		check_pipe(char *str);
int		remove_quotes(char **str);
int		parser_exit(t_list **token, char *msg, int err);
t_token	*parser_new_token(char *cmd, char *pipe);
int		parser_add_token(t_token **lst, t_token *new);
char	*parser_trim(char *str);

// tcider_vaztar_adapter.c
int		exec_command(t_data *data);


#endif
