# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 16:01:38 by tcider            #+#    #+#              #
#    Updated: 2021/08/29 20:25:49 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = libft.a

LIBFT_DIR = ./libft/

SRC_DIR = srcs/

OBJ_DIR = obj/

HEADER_DIR = ./includes/

HEADERS = tcider.h vaztar.h

#SRC = main_vaztar.c exec.c command_handler_bins.c

SRC = main.c history1.c history2.c terminal1.c terminal2.c history3.c \
env.c parser_utils.c parser1.c parser2.c tcider_vaztar_adapter.c \
main_vaztar.c exec.c command_handler_bins.c error.c ft_pwd.c ft_exit.c \
ft_cd.c ft_env.c ft_echo.c

SRC_LIST = $(addprefix $(SRC_DIR),$(SRC))

OBJ_LIST = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_LIST))

HEADER_LIST = $(addprefix $(HEADER_DIR),$(HEADERS))

COMPILE = clang #-Wall -Wextra -Werror -g -fsanitize=address #FIXME
#COMPILE = gcc -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_LIST)
	mkdir -p $(OBJ_DIR)
	$(COMPILE) -c $< -o $@ -I$(HEADER_DIR) -I$(LIBFT_DIR)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ_LIST) $(LIBFT_DIR)$(LIBFT)
	$(COMPILE) -o $(NAME) $(OBJ_LIST) -L$(LIBFT_DIR) -lft -ltermcap

bonus: all

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
