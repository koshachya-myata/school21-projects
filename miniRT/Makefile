# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 17:22:26 by vaztar            #+#    #+#              #
#    Updated: 2021/02/25 17:50:44 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_DIR = mlx_mms

INCLUDE = libft/libft.a -framework OpenGL -framework AppKit libmlx.dylib

SRC =	src/main.c src/parser.c src/get_next_line.c src/get_next_line_utils.c \
		src/trace.c src/lstobj.c src/vector.c src/vector2.c src/vector3.c \
		src/sphere.c src/triangle.c src/light.c src/plane.c src/numeric.c \
		src/square.c src/cylinder.c src/intersect.c src/bmp.c \
		src/parse_checker.c src/addition_func.c src/parser2.c \
		src/parser3.c src/additional_func2.c src/addition_func3.c

OBJ = $(SRC:.c=.o)

HEADER = src/minirt.h src/get_next_line.h

CFLAGS = -Wall -Wextra -Werror

NAME = miniRT

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	cd libft && $(MAKE) bonus && cd ../
	cd mlx_mms && $(MAKE) && cp libmlx.dylib ../ && cd ../
	gcc $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
	cd libft && $(MAKE) clean && cd ../
	cd src && /bin/rm -f *.o && cd ../
	cd mlx_mms && $(MAKE) clean && cd ../
	
fclean: clean
	cd libft && $(MAKE) fclean && cd ../
	cd mlx_mms && $(MAKE) clean && cd ../
	/bin/rm -f $(NAME)
	/bin/rm -f libmlx.dylib

re: fclean all

.PHONY: all clean fclean re bonus