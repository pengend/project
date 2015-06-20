/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 20:32:34 by pxia              #+#    #+#             */
/*   Updated: 2015/05/23 19:53:48 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int check_name(t_client *client, char *name, int number)
{
	int i;

	i = 0;
	while (i < number)
	{
		if (!ft_strcmp(client[i].name, name))
			return (i);
		i++;
	}
	return (-1);
}

int check_args_name(t_client *client, int cli, char **args, int *number)
{
	char *name;
	char *msg;
	int to_send_id;

	name = args[0];
	msg = NULL;
	if (ft_tablen(args) < 2)
		msg = ft_strdup("Two arguments expected");
	else if (!ft_strcmp((name = args[0]), client[cli].name))
		msg = ft_strdup("Own nickname");
	else if ((to_send_id = check_name(client, name, *number)) < 0)
		msg = ft_strdup("No such nickname in whole server");
	if (msg != NULL)
	{
		ft_send_msg(cli, ERRORS, msg);
		free(msg);
		return (-1);
	}
	return (to_send_id);
}

int ft_msg(t_client *client, int cli, char **args, int *number)
{
	char *msg;
	char *to_send;
	int to_send_id;

	if ((to_send_id = check_args_name(client, cli, args, number)) == -1)
		return (0);
	to_send = ft_unsplit(args + 1);
	msg = ft_join_all(5, C_BCYAN, client[cli].name, " : ", C_RESET, to_send);
	ft_strcat(client[to_send_id].write_buf, msg);
	free(msg);
	free(to_send);
	return (1);
}
