#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/12 20:37:02 by pxia              #+#    #+#              #
#    Updated: 2015/06/12 20:41:46 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo
LIBFT_LIB = ./libft/libft.a
SRC_DIR	= ./src/
SRC	= main.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ	= $(SRCS:.c=.o)
INC	= -I ./libft -I ./includes
FLAGS = -Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) -lpthread

$(LIBFT_LIB):
	make -C libft/

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
