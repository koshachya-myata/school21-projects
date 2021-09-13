# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 15:45:24 by vaztar            #+#    #+#              #
#    Updated: 2021/03/23 17:55:21 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRC:.s=.o)

HEADER = libasm.h

CFLAGS = -Wall -Wextra -Werror

NAME = libasm.a

all: $(NAME)

%.o: %.s $(HEADER)
	nasm -fmacho64 $<

$(NAME): $(OBJ) main.o
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o
	
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus