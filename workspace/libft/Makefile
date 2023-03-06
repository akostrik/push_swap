# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:32:35 by akostrik          #+#    #+#              #
#    Updated: 2023/02/22 10:55:12 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
SRCS   = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
          ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
          ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
          ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
          ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
          ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
          ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
          ft_printf.c ft_putnbr_base_10_fd.c ft_put_pointer_fd.c \
          ft_put_uns_long_fd.c ft_get_next_line.c \
          ft_get_next_line_utils.c ft_iswhitespace.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS} 
	ar rc ${NAME} ${OBJS}

%.o: %.c 
	gcc -c ${CFLAGS} -o $@ $<

clean:
	rm -f ${OBJS} 

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
