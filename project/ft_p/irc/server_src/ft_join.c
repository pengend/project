/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 18:59:38 by pxia              #+#    #+#             */
/*   Updated: 2015/05/22 16:32:43 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

static int check_if_full_num(char *id)
{
	int i;

	i = 0;
	while (id[i])
	{
		if (!ft_isdigit(id[i]))
			return (1);
		i++;
	}
	return (0);
}

void channel_move(int cli, int num, t_channel *channels)
{
	t_client *client;

	client = g_base->client;
	client[cli].channel = num;
	client[cli].id_channel = channels[num].total;
	channels[num].client[channels[num].total] = &(client[cli]);
	channels[num].total += 1;
}

void channel_remove(int cli, t_channel *channels)
{
	int id_channel;
	int cur_channel;
	t_client *client;

	client = g_base->client;
	cur_channel = client[cli].channel;
	id_channel = 0;
	while (channels[cur_channel].client[id_channel] != &(client[cli]))
		id_channel++;
	ft_memmove(channels[cur_channel].client + id_channel,
			   channels[cur_channel].client + id_channel + 1,
			   (channels[cur_channel].total - id_channel - 1) * sizeof(t_client));
	channels[cur_channel].total -= 1;
}

int ft_leave(t_client *client, int cli, char **args, int *number)
{
	(void)args;
	(void)number;
	(void)client;
	channel_remove(cli, g_base->channels);
	channel_move(cli, 0, g_base->channels);
	ft_send_msg(cli, CHANNEL, "Joined Channel id: 0");
	return (1);
}

int ft_join(t_client *client, int cli, char **args, int *number)
{
	char *msg;
	char *id;
	int num;

	(void)number;
	id = args[0];
	msg = NULL;
	if (id == NULL || id[0] == '/')
		msg = ft_strdup("One argument expected");
	else if (check_if_full_num(id))
		msg = ft_strdup("The channel id should be a number");
	else if ((num = ft_atoi(id)) == client[cli].channel)
		msg = ft_strdup("Already in channel");
	else if (num < 0 || num > 99)
		msg = ft_strdup("Channel doesn't exist");
	if (msg)
	{
		ft_send_msg(cli, ERRORS, msg);
		free(msg);
		return (0);
	}
	msg = ft_strjoin("Joined channel id: ", id);
	channel_remove(cli, g_base->channels);
	channel_move(cli, num, g_base->channels);
	ft_send_msg(cli, CHANNEL, msg);
	free(msg);
	return (1);
}
