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
SRC = fdf.c
OBJ = fdf.o
HEADER = fdf.h
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -lmlx
MLX = minilibx/
CC = gcc
FLAG_FRAME = -framework
FRAMEWORK = $(FLAG_FRAME) OpenGL $(FLAG_FRAME) AppKit

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) -L $(MLX) $(FLAGS_MLX) $(FRAMEWORK)