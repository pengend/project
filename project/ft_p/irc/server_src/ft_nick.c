/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:02:19 by pxia              #+#    #+#             */
/*   Updated: 2015/05/22 16:31:18 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int check_no_repeat(t_client *client, int cli, char *name, int *number)
{
	int i;

	i = 0;
	while (i < *number)
	{
		if (i != cli)
		{
			if (!ft_strcmp(name, client[i].name))
				return (1);
		}
		i++;
	}
	return (0);
}

int ft_nick(t_client *client, int cli, char **args, int *number)
{
	char *name;
	char *msg;

	msg = NULL;
	name = args[0];
	if (name == NULL || name[0] == '/')
		msg = ft_strdup("One argument expected");
	else if (check_no_repeat(client, cli, name, number))
		msg = ft_strdup("Nickname already used");
	else if (ft_strlen(name) > 9)
		msg = ft_strdup("Nickname too long");
	if (msg)
	{
		ft_send_msg(cli, ERRORS, msg);
		free(msg);
		return (0);
	}
	msg = ft_strdup("Nickname has been create");
	ft_strncpy(g_base->client[cli].name, name, 9);
	free(msg);
	return (1);
}
