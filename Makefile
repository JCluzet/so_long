# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 21:27:58 by jcluzet           #+#    #+#              #
#    Updated: 2021/08/12 20:18:22 by jcluzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAMEBONUS	=	so_long_bonus

MLX			=	libmlx.a

SRCS			=	so_long.c	\
					display/*	\
					parsing/*	\
					GNL/*		\
					utils/*

SRCS_BONUS			=	bonus/so_long.c	\
					bonus/display/*	\
					bonus/parsing/*	\
					bonus/GNL/*		\
					bonus/utils/*


CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME):
			@echo "\033[33m[Compilation of so_long...]"
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/$(MLX) .
			@$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(SRCS) -g -fsanitize=address -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
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
bonus:		$(NAME_BONUS)
				@echo "\033[33m[so_long MACOS compilation with bonus...]"
				@ $(MAKE) -C mlx all
				@ cp ./mlx/$(MLX) .
				$(CC) $(CFLAGS) -g3 -Ofast -o $(NAMEBONUS) -Imlx $(SRCS_BONUS) -g -fsanitize=address -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
				@echo "\033[32m[ ./so_long_bonus created ]"
endif

ifeq ($(UNAME), Linux)
bonus:		$(NAME_BONUS)
				@echo "\033[33m[so_long Linux compilation with bonus...]"
				@chmod 777 mlx_linux/configure
				@ $(MAKE) -C mlx_linux all
				$(CC) $(CFLAGS) -g3 -o $(NAMEBONUS) $(SRCS_BONUS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
				@echo "\033[32m[ ./so_long_bonus created ]"
endif

ifeq ($(UNAME), Darwin)
clean:
			@ echo "\033[31m[Remove last version...]"
			@ $(MAKE) -C mlx clean
			@ rm -rf so_long.dSYM so_long_bonus.dSYM >/dev/null 2>&1
endif

ifeq ($(UNAME), Linux)
clean:
			@ echo "\033[31m[Remove last version...]"
			@ $(MAKE) -C mlx_linux clean 
			@ rm -rf so_long.dSYM so_long_bonus.dSYM >/dev/null 2>&1
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ rm $(MLX)
			@ rm so_long >/dev/null 2>&1
			@ rm so_long_bonus >/dev/null 2>&1
endif

ifeq ($(UNAME), Linux)
fclean:		clean
			@ rm so_long >/dev/null 2>&1
			@ rm so_long_bonus >/dev/null 2>&1
endif

re:			fclean all

.PHONY:		$(NAME) all bonus test clean fclean re

