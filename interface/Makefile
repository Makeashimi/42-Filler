# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/08 11:55:46 by jcharloi          #+#    #+#              #
#    Updated: 2017/06/16 16:44:25 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = interface.filler

SRC_NAME = ncurse.c put_board.c board_tool.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_PATH = ../sources/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@$(CC) -o $(NAME) $(OBJ_NAME) -lncurses $(LIB_PATH) $(CFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ_NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean re
