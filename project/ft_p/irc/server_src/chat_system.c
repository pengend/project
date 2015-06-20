/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:44:41 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 17:03:52 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

static void client_reset(t_client *client)
{
	int i;

	i = 0;
	while (i < MAX_CLIENT)
	{
		ft_bzero(&(client[i]), sizeof(t_client));
		client[i].fd_stat = I_FREE;
		client[i].channel = -1;
		ft_bzero(client[i].write_buf, BLOCK_SIZE);
		ft_bzero(client[i].name, MSG_SIZE);
		i++;
	}
	ft_sys_msg(SERVER, INFO, C_YELLOW, "Client reset successful");
}

static void init_client(fd_set *rdfs, fd_set *wdfs)
{
	int i;

	i = 0;
	FD_ZERO(rdfs);
	FD_ZERO(wdfs);
	FD_SET(0, rdfs);
	FD_SET(g_base->sockfd, rdfs);
	while (i < g_base->number)
	{
		FD_SET(g_base->client[i].cli.sockfd, rdfs);
		if (g_base->client[i].write_buf[0] != '\0')
			FD_SET(g_base->client[i].cli.sockfd, wdfs);
		i++;
	}
}

static void base_init(t_socket serv)
{
	int i;
	int j;

	g_base = (t_server*)malloc(sizeof(t_server));
	g_base->max_fd = serv.sockfd;
	g_base->sockfd = serv.sockfd;
	g_base->number = 0;
	g_base->dl = NULL;
	ft_bzero(g_base->count_id, MAX_DL);
	ft_bzero(g_base->cli_id, MAX_CLIENT);
	i = 0;
	while (i < 100)
	{
		g_base->channels[i].total = 0;
		j = 0;
		while (j < MAX_CLIENT)
		{
			g_base->channels[i].client[j] = NULL;
			j++;
		}
		i++;
	}
	i = 0;
}

static void server_answer(t_client *client, fd_set *rdfs, fd_set *wdfs, int *number)
{
	int i;
	char buff[BLOCK_SIZE];
	char c;
	
	i = 0;
	ft_bzero(buff, BLOCK_SIZE);
	while (i < *number)
	{
		if (FD_ISSET(client[i].cli.sockfd, rdfs))
		{
			recv(client[i].cli.sockfd, &c, sizeof(c), MSG_PEEK);
			if (!ft_isprint(c))
			{
				if (check_if_pack(i, client[i].cli.sockfd, c) == 0)
				{
					recv(client[i].cli.sockfd, buff, BLOCK_SIZE, 0);
					read_client(client, i, buff, number);
				}
			}
			else
				read_client(client, i, buff, number);
			ft_bzero(buff, BLOCK_SIZE);
			break ;
		}
		if (FD_ISSET(client[i].cli.sockfd, wdfs))
		{
			write_client(client, i, client[i].write_buf, number);
			ft_bzero(g_base->client[i].write_buf, BLOCK_SIZE);
		}
		i++;
	}
}

void chat_system(t_socket serv)
{
	base_init(serv);
	client_reset(g_base->client);
	while (1)
	{
		init_client(&(g_base->rdfs), &(g_base->wdfs));
		if (select(g_base->max_fd + 1, &(g_base->rdfs), &(g_base->wdfs), NULL, NULL) == -1)
			ft_sys("On select", 2, 2, 3);
		if (FD_ISSET(0, &(g_base->rdfs)))
			ft_sys("Keyboard", 2, 2, 3);
		else if (FD_ISSET(g_base->sockfd, &(g_base->rdfs)))
		{
			if (!add_client(g_base->sockfd, &(g_base->number), &(g_base->max_fd)) == 0)
				continue ;
			else
				FD_SET(g_base->client[g_base->number - 1].cli.sockfd, &(g_base->rdfs));
		}
		else
			server_answer(g_base->client, &(g_base->rdfs), &(g_base->wdfs), &(g_base->number));
	}
}
