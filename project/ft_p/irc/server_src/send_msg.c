/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:42:41 by pxia              #+#    #+#             */
/*   Updated: 2015/05/22 16:31:05 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void send_message_to_all_clients(t_client *client, int cli, char *buffer)
{
	t_channel cur_channel;
	char *msg;
	int i;

	if ((msg = ft_addnum("Message received from id: ", client[cli].id)) == NULL)
		return ;
	cur_channel = g_base->channels[client[cli].channel];
	ft_sys_msg(SERVER, INFO, C_YELLOW, msg);
	free(msg);
	msg = NULL;
	if ((msg = ft_join_all(5, C_YELLOW, client[cli].name, " : ", C_RESET, buffer)) == NULL)
		return ;
	i = 0;
	while (i < cur_channel.total)
	{
		if (cur_channel.client[i] != &(client[cli]) && cur_channel.client[i]->fd_stat != I_UNKNOWN)
		{
			ft_strcpy(cur_channel.client[i]->write_buf, msg);
		}
		i++;
	}
	free(msg);
}

void server_message_to_all_clients(t_client *client, int number, int channel_num, char *buff)
{
	int i;
	t_channel channel;
	int id;

	i = 0;
	if (channel_num >= 0)
	{
		channel = g_base->channels[channel_num];
		while (i < channel.total)
		{
			if (channel.client[i]->fd_stat != I_UNKNOWN)
			{
				id = channel.client[i]->id;
				ft_send_msg(id, CHANNEL, buff);
			}
			i++;
		}
	}
	else
	{
		while (i < number)
		{
			if (client[i].fd_stat != I_UNKNOWN)
				ft_send_msg(i, INFO, buff);
			i++;
		}		
	}
}
