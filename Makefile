# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 21:27:58 by jcluzet           #+#    #+#              #
#    Updated: 2021/08/08 21:47:25 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

MLX			=	libmlx.dylib

SRCS			=	so_long.c \
					parsing.c \
					display.c \
					

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME):
			@echo "\033[33m[so_long MACOS compilation...]"
			@ $(MAKE) -C mlx all
			@ cp ./mlx/$(MLX) .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(SRCS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "\033[32m[ ./so_long created ]"
endif

ifeq ($(UNAME), Linux)
$(NAME):
			@echo "\033[31;1mCompiling for Linux...\033[0m"
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(SRCS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "\033[32m[ ./so_long created ]"
endif

all:		$(NAME)

ifeq ($(UNAME), Darwin)
clean:
			@ echo "\033[31m[Remove last version...]"
			@ $(MAKE) -C mlx clean
			@ rm -rf so_long.dSYM
			@ rm $(BMP)
endif

ifeq ($(UNAME), Linux)
clean:
			@ echo "\033[31m[Remove last version...]"
			@ $(MAKE) -C mlx_linux clean
			@ rm -rf so_long.dSYM
			@ rm $(BMP)
endif

fclean:		clean
			@ rm $(MLX)
			rm so_long


re:			fclean all

.PHONY:		$(NAME) all bonus test clean fclean re

