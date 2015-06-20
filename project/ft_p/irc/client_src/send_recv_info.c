/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 16:37:31 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 17:27:10 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include "cfunc.h"

int client_side_command(char *command)
{
	char **args;
	int i;

	if (command[0] != '/')
		return (0);
	i = 0;
	args = ft_strsplit(command, '\t', ' ');
	while (g_func[i].name != NULL)
	{
		if (!ft_strcmp(args[0] + 1, g_func[i].name))
		{
			g_func[i].func(args + 1);
			ft_freetab(args);
			return (1);
		}
		i++;
	}
	ft_freetab(args);
	return (0);
}

static int pack_gestion(char c, int sockfd)
{
	if (c == RS)
	{
		ft_recv_file(sockfd);
		return (1);
	}
	if (c == RFD)
	{
		delete_mission(sockfd);
		return (1);
	}
	if (c == ACP)
	{
		start_mission(sockfd);
		return (1);
	}
	return (0);
}

void send_recv_info(int sockfd, fd_set *rdfs, fd_set *wdfs)
{
	char msg[BLOCK_SIZE];
	char c;

	if (FD_ISSET(sockfd, rdfs))
	{
		ft_bzero(msg, BLOCK_SIZE);
		if (recv(sockfd, &c, 1, MSG_PEEK) == 0)
			exit(0);
		if (g_reposit & 1 && pack_gestion(c, sockfd))
			return ;
		if (recv(sockfd, msg, BLOCK_SIZE, 0) == 0)
			exit(0);
		ft_putendl(msg);
		return ;
	}
	if (FD_ISSET(sockfd, wdfs))
	{
		if (send(sockfd, g_write_buf, BLOCK_SIZE, 0) == 0)
			exit(0);
		ft_bzero(g_write_buf, BLOCK_SIZE);
	}
}
