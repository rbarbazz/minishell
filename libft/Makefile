# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2018/04/13 17:04:37 by rbarbazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = src

SRC_NAME = boolean/ft_isalnum.c\
		   boolean/ft_isalpha.c\
		   boolean/ft_isascii.c\
		   boolean/ft_isdigit.c\
		   boolean/ft_isprint.c\
		   display/clrscr.c\
		   display/ft_putchar.c\
		   display/ft_putchar_fd.c\
		   display/ft_putendl.c\
		   display/ft_putendl_fd.c\
		   display/ft_putnbr.c\
		   display/ft_putnbr_fd.c\
		   display/ft_putstr.c\
		   display/ft_putstr_fd.c\
		   ft_atoi.c\
		   ft_itoa.c\
		   ft_printf/apply_flags.c\
		   ft_printf/convert_c.c\
		   ft_printf/convert_int_long.c\
		   ft_printf/convert_p.c\
		   ft_printf/convert_s.c\
		   ft_printf/convert_wchar.c\
		   ft_printf/ft_printf.c\
		   ft_printf/handle_arg.c\
		   ft_printf/handle_arg2.c\
		   get_next_line.c\
		   get_stdin.c\
		   lists/ft_lstdel.c\
		   lists/ft_lstdelone.c\
		   lists/ft_lstnew.c\
		   mem/ft_bzero.c\
		   mem/ft_memalloc.c\
		   mem/ft_memccpy.c\
		   mem/ft_memchr.c\
		   mem/ft_memcmp.c\
		   mem/ft_memcpy.c\
		   mem/ft_memdel.c\
		   mem/ft_memmove.c\
		   mem/ft_memset.c\
		   mem/strstr_free.c\
		   strings/count_char.c\
		   strings/dup_from_char.c\
		   strings/dup_to_char.c\
		   strings/ft_reverse.c\
		   strings/ft_strcat.c\
		   strings/ft_strchr.c\
		   strings/ft_strclr.c\
		   strings/ft_strcmp.c\
		   strings/ft_strcpy.c\
		   strings/ft_strdel.c\
		   strings/ft_strdup.c\
		   strings/ft_strequ.c\
		   strings/ft_striter.c\
		   strings/ft_striteri.c\
		   strings/ft_strjoin.c\
		   strings/ft_strlcat.c\
		   strings/ft_strlen.c\
		   strings/ft_strmap.c\
		   strings/ft_strmapi.c\
		   strings/ft_strncat.c\
		   strings/ft_strncmp.c\
		   strings/ft_strncpy.c\
		   strings/ft_strnequ.c\
		   strings/ft_strnew.c\
		   strings/ft_strnstr.c\
		   strings/ft_strrchr.c\
		   strings/ft_strsplit.c\
		   strings/ft_strstr.c\
		   strings/ft_strsub.c\
		   strings/ft_strtrim.c\
		   strings/ft_tolower.c\
		   strings/ft_toupper.c\
		   strings/strdup_wo_c.c\
		   strings/strjoinchar.c\
		   strings/strsplit_whitespace.c\
		   strings/strstrdup.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude

CFLAGS = -Wall -Wextra -Werror

CC = clang

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p obj/ft_printf obj/strings obj/boolean obj/display obj/lists obj/mem
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
