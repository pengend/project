/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:41:50 by pxia              #+#    #+#             */
/*   Updated: 2015/06/05 17:41:33 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# define BLOCK_SIZE 4096
# define MSG_SIZE 1024

# define RFD 0b00000001
# define ACP 0b00000011
# define STX 0b00000010
# define EOT 0b00000100
# define ACK 0b00000110
# define NAK 0b00010101
# define RS	0b00011110

# define CLIENT "[CLIENT]"
# define ERRORS " Error "
# define INFO " Info "
# define WAIT 0b00000000
# define CONFIRMED 0b00000001
# define WAIT_ACK 0b00000010

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <netinet/in.h>
# include <netdb.h>
# include <sys/mman.h>
# include <dirent.h>
# include "libft.h"
# include <arpa/inet.h>

typedef struct sockaddr_in sock_addr;

typedef struct hostent host;

typedef struct	s_socket
{
	int sockfd;
	int port;
	sock_addr addr;
	socklen_t adlen;
}				t_socket;

typedef struct				s_file_info
{
	char sd[9];
	char rv[9];
	char name[MSG_SIZE];
	int id;
	size_t size;
}							t_file_info;

typedef struct				s_sd_mission
{
	int						fd;
	t_file_info				info;
	size_t					size;
	size_t					max_size;
	int						stat;
	struct s_sd_mission		*next;
}							t_sd_mission;

char g_write_buf[BLOCK_SIZE];
int g_reposit;
t_sd_mission *g_sd;
t_sd_mission *g_rv;

void						send_recv_info(int sockfd, fd_set *rdfs, fd_set *wdfs);
int							ft_send_file(char **args);
int							client_side_command(char *command);
int							ft_confirm(char **args);
int							ft_recv_file(int sockfd);
void						delete_rv(int id);
void						create_fd(t_sd_mission *dl);
void						client_answer(char c, t_file_info *info);
int							test_create(char *name);
void						add_end(t_sd_mission **liste, t_sd_mission *new);
int							ft_ms(char **args);
void						delete_mission(int sockfd);
void						start_mission(int sockfd);

#endif
