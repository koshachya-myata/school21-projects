NAME = philo

SRC_DIR = srcs/

OBJ_DIR = obj/

HEADER_DIR = ./includes/

HEADERS = philo.h

SRC = main.c time.c utils.c utils2.c\
 print.c exit.c monitoring.c\
 philo.c parse.c

SRC_LIST = $(addprefix $(SRC_DIR),$(SRC))

OBJ_LIST = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_LIST))

HEADER_LIST = $(addprefix $(HEADER_DIR),$(HEADERS))

COMPILE = gcc -Wall -Wextra

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(COMPILE) -c $< -o $@ -I$(HEADER_DIR)

$(NAME): $(OBJ_LIST) $(HEADER_LIST)
	$(COMPILE) -o $(NAME) $(OBJ_LIST)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
