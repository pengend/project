/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 18:13:19 by pxia              #+#    #+#             */
/*   Updated: 2015/06/05 15:41:02 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void recv_ack(int cli, int sockfd)
{
	int id;
	t_download *dl;

	recv(sockfd, &id, 4, 0);
	if ((dl = search_dl_mission(id)) == NULL ||
		dl->rv != &(g_base->client[cli]))
	{
		ft_send_msg(cli, ERROR, "No such id. Check id with /ms");
		return ;
	}
	ft_send_ack(dl->sd, ACK, &(dl->id));
	dl->stat = CONFIRMED;
}

void recv_nack(int cli, int sockfd)
{
	int id;
	t_download *dl;

	recv(sockfd, &id, 4, 0);
	if ((dl = search_dl_mission(id)) == NULL)
	{
		ft_send_msg(cli, ERROR, "No such id. Check id with /ms");
		return ;
	}
	ft_send_ack(dl->sd, NAK, &(dl->id));
	delete_dl(dl);
}

void recv_acp(int cli, int sockfd)
{
	t_file_info info;
	t_download *dl;

	recv(sockfd, &info, sizeof(info), 0);
	if ((dl = search_dl_mission(info.id)) == NULL)
	{
		ft_send_msg(cli, ERROR, "No such id. Check id with /ms");
		return ;
	}
	ft_send_answer(dl->sd, ACP, &info);
	dl->stat = CONFIRMED;
}

void recv_rfd(int cli, int sockfd)
{
	t_file_info info;
	t_download *dl;

	recv(sockfd, &info, sizeof(info), 0);
	if ((dl = search_dl_mission(info.id)) == NULL)
	{
		ft_send_msg(cli, ERROR, "No such id. Check id with /ms");
		return ;
	}
	ft_send_answer(dl->sd, ACP, &info);
	delete_dl(dl);
}
