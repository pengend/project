/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:37:54 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 16:23:29 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_H
# define IRC_H
# define MAX_CLIENT 100
# define MSG_SIZE 1024
# define BLOCK_SIZE 4096
# define MAX_DL 100000
# define MAX_NAME 9
# define I_FREE 0b00000000
# define I_UNKNOWN 0b00000000
# define I_CLIENT 0b0000001
# define STABLE 0b00000100
# define WAIT 0b00000000
# define CONFIRMED 0b00000001
# define WAIT_ACK 0b00000010
# define I_SERVER 0b10000000
# define CHANNEL " Channel "
# define INFO " Info "
# define ERRORS " Error "
# define SERVER "[SERVER]"

# define STX 0b00000010
# define ACP 0b00000011
# define EOT 0b00000100
# define ACK 0b00000110
# define NAK 0b00010101
# define RS	0b00011110
# define RFD 0b00000001

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <dirent.h>
# include "libft.h"
# include <sys/select.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <time.h>

typedef struct sockaddr_in	sock_addr;

typedef struct				s_pack
{
	int						id;
	char					buff[4000];
}							t_pack;

typedef struct				s_request
{
	int						type;
	int						max_size;
	char					*name;
}							t_request;

typedef	struct				s_confirm
{
	int						id;
	char					msg[100];
	struct s_confirm		*next;
}							t_confirm;

typedef struct				s_socket
{
	int						sockfd;
	int						port;
	sock_addr				addr;
	socklen_t				adlen;
}							t_socket;

typedef struct				s_client
{
	t_socket				cli;
	int						id;
	char					name[9];
	int						fd_stat;
	int						channel;
	int						id_channel;
	char					write_buf[BLOCK_SIZE];
}							t_client;

typedef struct				s_download
{
	t_client				*sd;
	t_client				*rv;
	int						stat;
	int						id;
	int						size;
	int						max_size;
	char					name[MSG_SIZE];
	struct s_download		*next;
}							t_download;

typedef struct s_channel
{
	int total;
	char *name;
	t_client *client[MAX_CLIENT];
}				t_channel;

typedef struct s_server
{
	int sockfd;
	int number;
	int max_fd;
	t_client client[MAX_CLIENT];
	t_channel channels[100];
	char msg[MSG_SIZE];
	t_download *dl;
	char count_id[MAX_DL];
	char cli_id[MAX_CLIENT];
	fd_set rdfs;
	fd_set wdfs;
}				t_server;

typedef struct				s_action
{
	int						id;
	int						(*func)(t_client *client, int cli, char **args, int *number);
	struct s_action			*next;
}							t_action;

typedef struct				s_file_info
{
	char sd[9];
	char rv[9];
	char name[MSG_SIZE];
	size_t size;
	int id;
}							t_file_info;

typedef struct				s_ack
{
	int						id;
	char					ack;
}							t_ack;

t_server *g_base;

int							recv_gestion(char *request, t_client *client, int cli, int *number);
int							ft_nick(t_client *client, int cli, char **args, int *number);
int							ft_join(t_client *client, int cli, char **args, int *number);
int							ft_leave(t_client *client, int cli, char **args, int *number);
int							ft_send_msg(int cli, char *type, char *to_send);
void						ft_send_pack(t_pack *pack, t_download *dl);
void						channel_move(int cli, int num, t_channel *channels);
void						channel_remove(int cli, t_channel *channels);
int							add_client(int serv_sock, int *number, int *max);
void						server_message_to_all_clients(t_client *client, int number, int channel_num, char *buffer);
void						send_message_to_all_clients(t_client *client, int cli, char *buffer);
void						remove_client(int cli, int *number);
void						chat_system(t_socket serv);
void						read_client(t_client *client, int cli, char *buff, int *number);
void						write_client(t_client *client, int cli, char *buff, int *number);
int							check_name(t_client *client, char *name, int number);
int							check_args_name(t_client *client, int cli, char **args, int *number);
int							ft_who(t_client *client, int cli, char **args, int *number);
int							ft_help(t_client *client, int cli, char **args, int *number);
int							ft_msg(t_client *client, int cli, char **args, int *number);
int							ft_time(t_client *client, int cli, char **args, int *number);
int							ft_quit(t_client *client, int cli, char **args, int *number);
int							check_if_pack(int cli, int sockfd, char c);
void						prepare_dl_mission(int cli, int sockfd);
void						recv_ack(int cli, int sockfd);
void						recv_nack(int cli, int sockfd);
void						recv_acp(int cli, int sockfd);
void						recv_rfd(int cli, int sockfd);
void						send_pack(int cli, int sockfd);
t_download					*search_dl_mission(int id);
void						add_end(t_download **liste, t_download *new);
void						delete_dl(t_download *dl);
void						ft_send_answer(t_client *dest, int type, t_file_info *info);
void						ft_send_ack(t_client *dest, int type, int *id);

#endif
