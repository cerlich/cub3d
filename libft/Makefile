# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerlich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 17:48:43 by cerlich           #+#    #+#              #
#    Updated: 2020/11/09 14:44:24 by cerlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRC = ft_atoi.c \
ft_isascii.c \
ft_memchr.c \
ft_putchar_fd.c \
ft_strchr.c \
ft_strlen.c \
ft_strtrim.c \
ft_bzero.c \
ft_isdigit.c \
ft_memcmp.c \
ft_putendl_fd.c \
ft_strdup.c \
ft_strmapi.c \
ft_substr.c \
ft_calloc.c \
ft_isprint.c \
ft_memcpy.c \
ft_putnbr_fd.c \
ft_strjoin.c \
ft_strncmp.c \
ft_tolower.c \
ft_isalnum.c \
ft_itoa.c \
ft_memmove.c \
ft_putstr_fd.c \
ft_strlcat.c \
ft_strnstr.c \
ft_toupper.c \
ft_isalpha.c \
ft_memccpy.c \
ft_memset.c \
ft_split.c  \
ft_strlcpy.c \
ft_strrchr.c \

OBJS = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) : %.o : %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
