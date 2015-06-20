/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:48:35 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 17:20:32 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"
#include "pack.h"

void read_client(t_client *client, int cli, char *buff, int *number)
{
	int ret;

	ret = recv(client[cli].cli.sockfd, buff, BLOCK_SIZE, 0);
	if (ret == 0)
	{
		remove_client(cli, number);
	}
	else
	{
		if (recv_gestion(buff, client, cli, number) == 0)
		{
			if (ft_strlen(buff) < 100)
			{
				send_message_to_all_clients(client, cli, buff);
			}
			else
			{
				ft_send_msg(cli, ERRORS, "Too long message");
			}
		}
	}
}

int check_if_pack(int cli, int sockfd, char c)
{
	char t;
	int i;

	i = 0;
	while (g_pfunc[i].req != 0)
	{
		if (g_pfunc[i].req == c)
		{
			recv(sockfd, &t, 1, 0);
			g_pfunc[i].func(cli, sockfd);
			return (1);
		}
		i++;
	}
	return (0);
}
