#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 16:02:07 by pxia              #+#    #+#              #
#    Updated: 2015/05/27 18:53:33 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

S_NAME = server
C_NAME = client
LIBFT_LIB = ./libft/libft.a
S_SRC_DIR	= ./server_src/
S_SRC	= server.c client_gestion.c tools.c ft_msg.c ft_join.c ft_nick.c \
		add_client.c send_msg.c chat_system.c read_client.c write_client.c \
		ft_who.c ft_help.c ft_time.c ft_quit.c download.c pack_gestion.c \
		ft_recv.c
S_SRCS = $(addprefix $(S_SRC_DIR), $(S_SRC))
S_OBJ	= $(S_SRCS:.c=.o)
C_SRC_DIR = ./client_src/
C_SRC = client.c send_recv_info.c ft_file.c ft_recv_file.c tools.c ft_ms.c \
		mission_control.c
C_SRCS = $(addprefix $(C_SRC_DIR), $(C_SRC))
C_OBJ = $(C_SRCS:.c=.o)
INC	= -I ./libft -I ./server_h -I ./client_h
FLAGS = -Wall -Werror -Wextra -O3

all: $(S_NAME)

$(S_NAME): $(LIBFT_LIB) $(S_OBJ) $(C_OBJ) 
	gcc $(FLAGS) -o $(S_NAME) $(S_OBJ) $(LIBFT_LIB)
	gcc $(FLAGS) -o $(C_NAME) $(C_OBJ) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C libft/

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	make -C libft/ clean
	rm -rf $(S_OBJ)
	rm -rf $(C_OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(S_NAME)
	rm -rf $(C_NAME)

re: fclean all
