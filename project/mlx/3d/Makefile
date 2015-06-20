#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 18:22:48 by pxia              #+#    #+#              #
#    Updated: 2015/02/17 18:02:12 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
GC = gcc -Wall -Wextra -Werror
SRC = main.c pixelput.c hook.c trace.c get_matrix.c tools.c camera.c cube.c \
	keyboard_control.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(GC) -g -o $@ $^ -L /usr/X11/lib -lmlx -lXext -lX11 libft/libft.a

%.o: %.c
	$(GC) -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a

re: fclean all