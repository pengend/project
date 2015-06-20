/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 16:58:10 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 17:59:41 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <irc.h>

t_download *init_dl(int cli, int to_send_id, t_file_info info)
{
	t_download *dl;

	dl = (t_download*)malloc(sizeof(t_download));
	dl->id = ft_strlen(g_base->count_id);
	dl->sd = &(g_base->client[cli]);
	dl->rv = &(g_base->client[to_send_id]);
	dl->stat = WAIT;
	dl->size = 0;
	dl->max_size = info.size;
	ft_strcpy(dl->name, info.name);
	dl->next = NULL;
	return (dl);
}

void prepare_dl_mission(int cli, int sockfd)
{
	t_file_info info;
	t_download *dl;
	int to_send_id;

	recv(sockfd, &info, sizeof(info), 0);
	if ((to_send_id = check_name(g_base->client, info.rv, g_base->number)) == -1
		|| cli == to_send_id)
	{
		ft_send_answer(&(g_base->client[cli]), RFD, &info);
		return ;
	}
	dl = init_dl(cli, to_send_id, info);
	ft_strncpy(info.sd, g_base->client[cli].name, 9);
	add_end(&(g_base->dl), dl);
	ft_send_msg(cli, INFO, "File info sended, waiting for the answer");
	g_base->client[to_send_id].write_buf[0] = RS;
	ft_memcpy(g_base->client[to_send_id].write_buf + 1, &info, sizeof(info));
	ft_memcpy(g_base->client[to_send_id].write_buf + 1 + sizeof(info), &(dl->id), sizeof(int));
}
