# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 11:01:38 by vkuksa            #+#    #+#              #
#    Updated: 2017/12/16 16:25:35 by dpogrebn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_atoi.c ./ft_bzero.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c \
./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_lstadd.c ./ft_lstdel.c \
 ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstnew.c ./ft_memalloc.c \
./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memdel.c \
./ft_memmove.c ./ft_memset.c ./ft_putchar.c ./ft_putchar_fd.c ./ft_putendl.c \
./ft_putendl_fd.c ./ft_putnbr.c ./ft_putnbr_fd.c ./ft_putstr.c \
./ft_putstr_fd.c ./ft_strcat.c ./ft_strchr.c ./ft_strclr.c ./ft_strcmp.c \
./ft_strcpy.c ./ft_strdel.c ./ft_strdup.c ./ft_strequ.c ./ft_striter.c \
./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlen.c ./ft_strmap.c \
./ft_strmapi.c ./ft_strncat.c ./ft_strncmp.c ./ft_strncpy.c ./ft_strnequ.c \
./ft_strnew.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strsplit.c ./ft_strstr.c \
./ft_strsub.c ./ft_strtrim.c ./ft_tolower.c ./ft_toupper.c ./ft_inoder.c \
./ft_lstaddlast.c ./ft_lstsortcontent.c ./ft_preorder.c ./ft_str_gather.c \
./get_next_line.c ./ft_addletter.c ./ft_strjoin_freemem.c \

SRC_PRNTF = ft_printf/ft_printf.c ft_printf/ft_find_params.c \
ft_printf/ft_converse.c \
ft_printf/ft_itoa_base.c ft_printf/ft_converse_numb.c ft_printf/ft_make_flag.c \
ft_printf/ft_print_num.c ft_printf/ft_sizes_l_z.c \
ft_printf/ft_make_unicode_char.c ft_printf/ft_pars.c ft_printf/ft_pars_extra_f.c\
ft_printf/ft_converse_extra_f.c ft_printf/ft_sizes_h_hh.c \
ft_printf/ft_make_flag_minus.c ft_printf/ft_make_flag_minus_adl.c \
ft_printf/ft_finish_flags.c ft_printf/ft_set_flags.c


SRCO = ./ft_atoi.o ./ft_bzero.o ./ft_isalnum.o ./ft_isalpha.o ./ft_isascii.o \
./ft_isdigit.o ./ft_isprint.o ./ft_itoa.o ./ft_lstadd.o ./ft_lstdel.o \
 ./ft_lstdelone.o ./ft_lstiter.o ./ft_lstmap.o ./ft_lstnew.o ./ft_memalloc.o \
./ft_memccpy.o ./ft_memchr.o ./ft_memcmp.o ./ft_memcpy.o ./ft_memdel.o \
./ft_memmove.o ./ft_memset.o ./ft_putchar.o ./ft_putchar_fd.o ./ft_putendl.o \
./ft_putendl_fd.o ./ft_putnbr.o ./ft_putnbr_fd.o ./ft_putstr.o \
./ft_putstr_fd.o ./ft_strcat.o ./ft_strchr.o ./ft_strclr.o ./ft_strcmp.o \
./ft_strcpy.o ./ft_strdel.o ./ft_strdup.o ./ft_strequ.o ./ft_striter.o \
./ft_striteri.o ./ft_strjoin.o ./ft_strlcat.o ./ft_strlen.o ./ft_strmap.o \
./ft_strmapi.o ./ft_strncat.o ./ft_strncmp.o ./ft_strncpy.o ./ft_strnequ.o \
./ft_strnew.o ./ft_strnstr.o ./ft_strrchr.o ./ft_strsplit.o ./ft_strstr.o \
./ft_strsub.o ./ft_strtrim.o ./ft_tolower.o ./ft_toupper.o ./ft_inoder.o \
./ft_lstaddlast.o ./ft_lstsortcontent.o ./ft_preorder.o ./ft_str_gather.o \
./get_next_line.o ./ft_addletter.o ./ft_strjoin_freemem.o \

SRCO_PRNTF = ft_printf.o ft_find_params.o \
ft_converse.o ft_itoa_base.o ft_converse_numb.o ft_make_flag.o \
ft_print_num.o ft_sizes_l_z.o \
ft_make_unicode_char.o ft_pars.o ft_pars_extra_f.o\
ft_converse_extra_f.o ft_sizes_h_hh.o ft_make_flag_minus.o \
ft_make_flag_minus_adl.o \
ft_finish_flags.o ft_set_flags.o


CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = ./includes/libft.h ./ft_printf/ft_printf.h ./includes/get_next_line.h

all: $(NAME)

$(NAME):
	@$(CC) -c $(FLAGS) $(SRC) $(SRC_PRNTF) -I $(INC)
	@ar rc $(NAME) $(SRCO) $(SRCO_PRNTF)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(SRCO) $(SRCO_PRNTF)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean $(NAME)
