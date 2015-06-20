/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_gestion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 16:12:59 by pxia              #+#    #+#             */
/*   Updated: 2015/05/23 18:47:20 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <irc.h>

void send_pack(int cli, int sockfd)
{
	t_pack pack;
	char *buf;
	t_download *dl;

	recv(sockfd, &pack, sizeof(pack), 0);
	if ((dl = search_dl_mission(pack.id)) == NULL ||
		dl->sd != &(g_base->client[cli]) || dl->stat != CONFIRMED)
	{
		return ;
	}
	buf = g_base->client[dl->rv->id].write_buf;
	ft_strcat(buf, (char*)&pack);
	dl->stat = WAIT_ACK;
}
