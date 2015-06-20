/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:08:09 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 17:16:35 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void init_connection(t_socket *serv, char **argv)
{
	struct protoent *proto;

	proto = getprotobyname("tcp");
	if (proto == 0)
	{
		ft_sys_msg(CLIENT, ERRORS, C_RED, "Wrong protocol");
		exit(0);
	}
	serv->port = ft_atoi(argv[2]);
	serv->sockfd = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	ft_sys_msg(CLIENT, INFO, C_YELLOW, "Openning socket successful");
	ft_bzero((char*)&serv->addr, sizeof(serv->addr));
	serv->addr.sin_family = AF_INET;
	serv->addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv->addr.sin_port = htons(serv->port);
}

static int message_type(int sockfd)
{
	char *command;

	get_next_line(0, &command);
	if (command[0] == '\0')
		return (0);
	if (!client_side_command(command))
		if (send(sockfd, command, ft_strlen(command), 0) == 0)
			exit(0);
	free(command);
	command = NULL;
	return (1);
}

static void create_download_reposit(void)
{
	if (opendir("P_Download") == NULL)
		if (mkdir("P_Download", (mode_t)0755) < 0)
		{
			ft_sys_msg(CLIENT, ERRORS, C_RED,
					   "Cannot create download repository");
			g_reposit = 0;
			return ;
		}
	g_reposit |= 1;
}

static void client_system(t_socket serv)
{
	fd_set rdfs;
	fd_set wdfs;

	ft_bzero(g_write_buf, BLOCK_SIZE);
	g_sd = NULL;
	g_rv = NULL;
	create_download_reposit();
	while (1)
	{
		FD_ZERO(&rdfs);
		FD_ZERO(&wdfs);
		FD_SET(0, &rdfs);
		FD_SET(serv.sockfd, &rdfs);
		if (g_write_buf[0] != '\0')
			FD_SET(serv.sockfd, &wdfs);
		if (select(serv.sockfd + 1, &rdfs, &wdfs, NULL, NULL) == -1)
			return ;
		if (FD_ISSET(0, &rdfs))
		{
			if (!message_type(serv.sockfd))
				continue ;
		}
		else
			send_recv_info(serv.sockfd, &rdfs, &wdfs);
	}
}

int main(int argc, char **argv)
{
	t_socket serv;

	if (argc != 3)
		return (0);
	init_connection(&serv, argv);
	if (connect(serv.sockfd, (const struct sockaddr *)&(serv.addr), sizeof(serv.addr)) < 0)
		return (ft_sys_msg(CLIENT, ERRORS, C_RED, "On connecting"));
	client_system(serv);
	close(serv.sockfd);
	return (0);
}
