# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 18:56:34 by vaztar            #+#    #+#              #
#    Updated: 2020/12/18 19:55:32 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	printf.c \
		put_ch.c \
		format_func.c \
		additional_func.c \
		put_int.c \
		put_p.c \
		parser.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cd libft && $(MAKE) && cd ../
	mv libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

clean:
	cd libft && $(MAKE) clean && cd ../
	/bin/rm -f *.o

fclean: clean
	cd libft && $(MAKE) fclean && cd ../
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
