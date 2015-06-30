#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/29 15:11:48 by pxia              #+#    #+#              #
#    Updated: 2015/06/29 15:27:04 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libfts.a
SRCS = ft_bzero.s ft_cat.s ft_isascii.s ft_isalpha.s ft_isalnum.s ft_isdigit.s \
	ft_isprint.s ft_memalloc.s ft_memcpy.s ft_memset.s ft_puts.s ft_strcat.s \
	ft_strdup.s ft_strlen.s ft_tolower.s ft_toupper.s

GC = gcc -Wall -Werror -Wextra -O3
OBJ = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.s
	nasmv -f macho64 -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
