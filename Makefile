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
SRC = fdf.c ft_atoi_base.c ft_make_grad.c ft_make_line.c ft_parse.c \
ft_change.c ft_first_pic.c ft_free_struct.c ft_keycode.c ft_put_last.c \
ft_rotate.c ft_set_and_first.c ft_make_col_z.c
HEADER = fdf.h
FL = -Wall -Wextra -Werror
F_MLX = -lmlx
MLX = /usr/local/lib/
CC = gcc
FLAG_FRAME = -framework
FW = $(FLAG_FRAME) OpenGL $(FLAG_FRAME) AppKit
MLX_HEAD = /usr/local/include

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft
	@$(CC) $(FL) -I MLX_HEAD -o $(NAME) $(SRC) $(LIBA) -L $(MLX) $(F_MLX) $(FW)

clean:
	@$(MAKE) -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all
