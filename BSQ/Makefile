# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 13:14:00 by vaztar            #+#    #+#              #
#    Updated: 2020/08/12 11:50:43 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/bsq_input.c \
	  srcs/ft_lib.c \
	  srcs/main.c \
	  srcs/std_input.c

OBJ = bsq_input.o \
	  ft_lib.o \
	  main.o \
	  std_input.o

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
