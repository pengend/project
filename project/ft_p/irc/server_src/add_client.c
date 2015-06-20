/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:40:54 by pxia              #+#    #+#             */
/*   Updated: 2015/06/05 18:12:11 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

static void guest_info_ini(int cli)
{
	int total;
	t_client *client;

	client = g_base->client;
	total = g_base->channels[0].total;
	g_base->client[cli].id = ft_strlen(g_base->cli_id);
	g_base->cli_id[client[cli].id] = '1';
	g_base->client[cli].fd_stat = I_UNKNOWN;
	ft_send_msg(cli, INFO, "Connection has been done\n");
	ft_send_msg(cli, INFO, "Move by default into Channels 0\n");
	ft_send_msg(cli, INFO,
				"Before speaking or receiveing message, type your nickname : (necessary)");
	channel_move(cli, 0, g_base->channels);
}

void remove_client(int cli, int *number)
{
	char disconnected_msg[MSG_SIZE];
	t_client *client;

	client = g_base->client;
	ft_putendl("removed");
	ft_bzero(disconnected_msg, MSG_SIZE);
	ft_strcpy(disconnected_msg, client[cli].name);
	ft_strcat(disconnected_msg, " disconnected ! ");
	ft_bzero(client[cli].write_buf, BLOCK_SIZE);
	ft_bzero(client[cli].name, MSG_SIZE);
	g_base->cli_id[client[cli].id] = '\0';
	close(client[cli].cli.sockfd);
	ft_memmove(client + cli, client + cli + 1, (*number - cli - 1) * sizeof(t_client));
	channel_remove(cli, g_base->channels);
	(*number)--;
	if (client[cli].fd_stat != I_UNKNOWN)
		server_message_to_all_clients(client, *number, client[cli].channel, disconnected_msg);
}

int add_client(int serv_sock, int *number, int *max)
{
	t_socket new_client;
	char *msg;
	t_client *client;

	client = g_base->client;
	new_client.adlen = sizeof(new_client.addr);
	new_client.sockfd = accept(serv_sock, (struct sockaddr *) &new_client.addr, &new_client.adlen);
	if (new_client.sockfd < 0)
		return (0);
	*max = new_client.sockfd > *max ? new_client.sockfd : *max;
	client[*number].cli = new_client;
	msg = ft_addnum("New guest connected id: ", *number);
	ft_sys_msg(SERVER, CHANNEL, C_YELLOW, msg);
	ft_sys_msg(SERVER, INFO, C_YELLOW, "Move into Channel 0 by default");
	ft_bzero(client[*number].write_buf, BLOCK_SIZE);
	guest_info_ini(*number);
	(*number)++;
	free(msg);
	return (1);
}
