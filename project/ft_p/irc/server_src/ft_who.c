/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_who.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:57:12 by pxia              #+#    #+#             */
/*   Updated: 2015/05/22 16:40:06 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void get_channel_all_user(t_channel channel, char *buff)
{
	int max;
	char *id;
	int i;

	max = channel.total;
	i = 0;
	ft_strcat(buff, "\nThe current Channel's User List: \n");
	while (i < max)
	{
		id = ft_itoa(i);
		ft_strcat(buff, id);
		ft_strcat(buff, " : ");
		ft_strcat(buff, channel.client[i]->name);
		ft_strcat(buff, "\n");
		free(id);
		i++;
	}
}

int ft_who(t_client *client, int cli, char **args, int *number)
{
	char buff[BLOCK_SIZE];

	(void)args;
	(void)number;
	ft_bzero(buff, BLOCK_SIZE);
	get_channel_all_user(g_base->channels[client[cli].channel], buff);
	ft_send_msg(cli, INFO, buff);
	return (1);
}
