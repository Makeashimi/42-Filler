# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 11:53:26 by jcharloi          #+#    #+#              #
#    Updated: 2017/06/21 16:54:35 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = jcharloi.filler

SRC_PATH = ./sources/
SRC_NAME = filler.c get_everything.c game.c piece.c enemy.c
OBJ_PATH = ./objects/
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_PATH = ./sources/libft/libft.a

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = ./sources/libft/
VIEWER = ./interface/

YELLOW = "\033[38;5;228m"
ORANGE = "\033[38;5;214m"
PINK = "\033[38;5;213m"
PURPLE = "\033[38;5;105m"
BLUE = "\033[38;5;33m"
GREEN = "\033[33;32m"
EOC = "\033[0m"

all: creation
	@make $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB_PATH) $(CFLAGS)
	@echo $(GREEN)"Done, you can now work on your filler, GLHF ! ✅"$(EOC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(PURPLE)"Your ./$@. file is ready to work !"$(EOC)

creation:
	@make -C sources/libft/
	@echo $(ORANGE)"Your $(LIB_PATH) is (al)ready (ready) to work !"$(EOC)
	@make -C $(VIEWER)
	@echo $(ORANGE)"Your $(VIEWER)interface.filler is (al)ready (ready) to work !"$(EOC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo $(BLUE)"Your $(OBJ_PATH) folder is (al)ready (ready) to work !"$(EOC)

clean:
	@make clean -C $(LIB)
	@make clean -C $(VIEWER)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo $(YELLOW)"Cleaned !"$(EOC)

fclean: clean
	@make fclean -C $(LIB)
	@make fclean -C $(VIEWER)
	@rm -f $(NAME)
	@echo $(PINK)"Fcleaned ! Compile me again !"$(EOC)

re: fclean all

.PHONY : all creation clean fclean re