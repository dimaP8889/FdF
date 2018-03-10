#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 16:25:54 by dpogrebn          #+#    #+#              #
#    Updated: 2018/02/21 16:25:55 by dpogrebn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ./fdf
LIBA = libft/libft.a
SRC = fdf.c ft_atoi_base.c ft_make_grad.c ft_make_line.c ft_parse.c ft_change.c ft_first_pic.c\
ft_free_struct.c ft_last_cut.c ft_put_last.c ft_rotate.c ft_set_and_first.c ft_make_col_z.c
OBJ = fdf.o ft_atoi_base.o ft_make_grad.o ft_make_line.o ft_parse.o ft_change.o
HEADER = fdf.h
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -lmlx
MLX = minilibx/
CC = gcc
FLAG_FRAME = -framework
FRAMEWORK = $(FLAG_FRAME) OpenGL $(FLAG_FRAME) AppKit

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBA) -L $(MLX) $(FLAGS_MLX) $(FRAMEWORK)